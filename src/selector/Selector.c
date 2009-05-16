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
    size_t i, offset;
    size_t length   = strlen(selector);
    int    inString = 0;
    int    flag     = 0;

    CSSSimpleSelector source = {0, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    CSSSelector*      parsed = CSS_NewSelector(NULL, 0);

    for (i = 0, offset = 0; i < length; i++) {
        if (selector[i] == '.') {
            flag = CSSClassSelector;
        }
        else if (selector[i] == '#') {
            flag = CSSIDSelector;
        }
        else if (selector[i] == '[') {
            flag = CSSAttributeSelector;
        }
        else if (selector[i] == '*') {
            source.flags |= CSSUniversalSelector;
        }
        else {
            
        }
    }

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
