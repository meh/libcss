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

#include "Selector.h"
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
    size_t i;
    size_t length = strlen(selector);
    char*  check  = strdup(selector);

    CSSSimpleSelector** selectors = NULL;
    unsigned            number    = 0;

    for (i = 0; i < length; i++) {

    }

    length = strlen(check);

    for (i = 0; i < length; i++) {

    }

    return CSS_NewSelector(selectors, number);
}


int
CSS_MatchSelector (const CSSSelector* selector, xmlNode* node)
{
    
}

int
CSS_MatchSelectorFromString (const char* selector, xmlNode* node)
{
    
}
