/****************************************************************************
* This file is part of libcss                                               *
* Copyleft meh. [http://meh.doesntexist.org | meh.ffff@gmail.com]           *
*                                                                           *
* lal is free software: you can redistribute it and/or modify               *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation, either version 3 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* libcss is distributed in the hope that it will be useful.                 *
* but WITHOUT ANY WARRANTY; without even the implied warranty o.            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See th.             *
* GNU General Public License for more details.                              *
*                                                                           *
* You should have received a copy of the GNU General Public License         *
* along with libcss.  If not, see <http://www.gnu.org/licenses/>.           *
****************************************************************************/

#include "selector/Selector.h"
#include "common.h"

CSSSelector*
CSS_NewSelector (CSSSimpleSelector** selectors, unsigned number)
{
    CSSSelector* newSelector = (CSSSelector*) malloc(sizeof(CSSSelector));
    newSelector->item        = selectors;
    newSelector->length      = number;

    return newSelector;
}

CSSSimpleSelector*
CSS_SetSelectorItem (CSSSelector* selector, CSSSimpleSelector* simpleSelector, int index)
{
    CSSSimpleSelector* result;

    if (index > selector->length-1) {
        return NULL;
    }

    result                = selector->item[index];
    selector->item[index] = simpleSelector;

    return result;
}

inline
CSSSimpleSelector*
CSS_GetSelectorItem (CSSSelector* selector, int index)
{
    if (index > selector->length-1) {
        return NULL;
    }

    return selector->item[index];
}

void
CSS_SetSelectorLength (CSSSelector* selector, int length)
{
    int oldLength;
    int i;

    if (length < 0) {
        return;
    }

    oldLength = selector->length;

    if (length < selector->length) {
        while (length != selector->length--) {
            CSS_DestroySimpleSelector(selector->item[selector->length]);
        }
    }
    else {
        selector->length = length;
    }

    selector->item = (CSSSimpleSelector**) realloc(selector->item, sizeof(CSSSimpleSelector*)*length);

    if (oldLength < selector->length) {
        for (i = oldLength; i < selector->length; i++) {
            selector->item[i] = NULL;
        }
    }
}

inline
int
CSS_GetSelectorLength (CSSSelector* selector)
{
    return selector->length;
}

void
CSS_AddSimpleSelector (CSSSelector* selector, CSSSimpleSelector* simpleSelector)
{
    CSS_SetSelectorLength(selector, CSS_GetSelectorLength(parsed)+1);
    CSS_SetSelectorItem(selector, simpleSelector, CSS_GetSelectorLength(parsed)-1);
}

CSSSelector*
CSS_ParseSelector (const char* selector, CSSExceptionList* exceptions)
{
    size_t             offset  = 0;
    char*              tmp     = NULL;
    char*              current = NULL;
    CSSSelector*       parsed  = CSS_NewSelector(NULL, 0);
    CSSSimpleSelector* simple  = NULL;

    while ((tmp = strchr(selector, ',')) != NULL) {
        current = strndup(&selector[offset], (tmp-&selector[offset]));
        simple = CSS_ParseSimpleSelector(current);

        if (simple == NULL) {
            CSS_DestroySelector(parsed);
            free(current);
            return NULL;
        }

        CSS_AddSimpleSelector(parsed, CSS_ParseSimpleSelector(current));
        free(current); current = NULL;
    }

    CSS_AddSimpleSelector(parsed, CSS_ParseSimpleSelector(&selector[offset]));

    return parsed;
}


int
CSS_MatchSelector (const CSSSelector* selector, xmlNode* node)
{
    return 0;
}

int
CSS_MatchSelectorFromString (const char* selector, xmlNode* node)
{
    return 0;
}

void
CSS_DestroySelector (CSSSelector* selector)
{
    while (selector->length--) {
        CSS_DestroySimpleSelector(selector->item[selector->length]);
    }
}

