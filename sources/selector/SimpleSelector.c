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

#include "selector/SimpleSelector.h"
#include "common.h"

CSSSimpleSelector*
CSS_NewSimpleSelector (int flags, int relation, char* nspace, CSSSimpleSelectorData* data)
{ 
    CSSSimpleSelector* selector = (CSSSimpleSelector*) malloc(sizeof(CSSSimpleSelector));
    selector->flags    = flags;
    selector->relation = relation;
    selector->nspace   = nspace;
    selector->data     = data;

    return selector;
}

CSSSimpleSelector*
CSS_ParseSimpleSelector (const char* selector)
{
    size_t i;
    size_t offset;
    size_t length   = strlen(selector);
    int    inString = 0;

    CSSSimpleSelector* parsed = CSS_NewSimpleSelector(0, 0, NULL, NULL);

    for (i = 0, offset = 0; i < length; i++) {
        if (selector[i] == '.') {
            parsed->flags |= CSSClassSelector;
        }
        else if (selector[i] == '#') {
            parsed->flags |= CSSIDSelector;
        }
        else if (selector[i] == '[') {
            parsed->flags |= CSSAttributeSelector;
        }
        else if (selector[i] == '*') {
            parsed->flags |= CSSUniversalSelector;
        }
        else if (selector[i] == ':') {
            
        }
        else if (strcmp(selector, "::") == 0) {

        }
    }

    return parsed;
}

void
CSS_DestroySimpleSelector (CSSSimpleSelector* selector)
{
    if (selector->type) {
        free(selector->type);
    }

    if (selector->attribute) {
        CSS_DestroyAttribute(selector->attribute);
    }

    if (selector->id) {
        free(selector->id);
    }

    if (selector->class) {
        free(selector->class);
    }

    if (selector->pseudoClass) {
        while (selector->pseudoClass++) {
            CSS_DestroyPseudoClass(*selector->pseudoClass);
        }
    }

    if (selector->pseudoElement) {
        free(selector->pseudoElement);
    }

    free(selector);
}
