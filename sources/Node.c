/****************************************************************************
* Copyleft meh. [http://meh.doesntexist.org | meh.ffff@gmail.com]           *
*                                                                           *
* This file is part of libcss                                               *
*                                                                           *
* libcss is free software: you can redistribute it and/or modify            *
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

#include "Node.h"
#include "common.h"

CSSNode*
CSS_NewNode (CSS_SELECTOR_TYPE** selectors, unsigned number, CSSPropertyList* properties)
{
    CSSNode* node        = (CSSNode*) malloc(sizeof(CSSNode));
    node->selector       = selectors;
    node->selectorNumber = number;
    node->properties     = properties;

    return node;
}

void
CSS_DestroyNode (CSSNode* node)
{
    while (node->selectorNumber--) {
        #ifdef CSS_SELECTOR
        CSS_DestroySelector(node->selector[node->selectorNumber]);
        #else
        free(node->selector[node->selectorNumber]);
        #endif
    }
    CSS_DestroyPropertyList(node->properties);
    free(node);
}

