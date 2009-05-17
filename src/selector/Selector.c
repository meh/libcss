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

void
CSS_DestroySelector (CSSSelector* selector)
{
    while (selector->length--) {
        CSS_DestroySimpleSelector(selector->item[selector->length]);
    }
}

CSSSelector*
CSS_ParseSelector (const char* selector)
{
    size_t       offset          = 0;
    char*        tmp             = NULL;
    char*        currentSelector = NULL;
    char         ok              = 1;
    CSSSelector* parsed          = CSS_NewSelector(NULL, 0);

    while (tmp = strchr(selector, ',') != NULL) {
        parsed->length++;
        parsed->item = (CSSSimpleSelector**) realloc(parsed->item, sizeof(CSSSimpleSelector*)*parse->length);
        currentSelector = strndup(&selector[offset], (tmp-&selector[offset]));
        parsed->item[parsed->length-1] = CSS_ParseSimpleSelector(currentSelector);
        free(currentSelector); currentSelector = NULL;
    }

    parsed->length++;
    parsed->item = (CSSSimpleSelector**) realloc(parsed->item, sizeof(CSSSimpleSelector*)*parse->length);
    parsed->item[parsed->length-1] = CSS_ParseSimpleSelector(&selector[offset]);

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
