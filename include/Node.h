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

#ifndef _LIB_CSS_NODE_H
#define _LIB_CSS_NODE_H

#include "PropertyList.h"

/**
 * Structure that represents a CSS node (a new selectors properties)
 */
typedef struct _CSSNode {
    char**              selector;       /**< Selectors array */
    unsigned            selectorNumber; /**< Number of selectors */
    CSSPropertyList*    properties;     /**< Selectors' properties */
} CSSNode;

/**
 * Create a new CSSNode object.
 *
 * @param   selectors   Array of selectors.
 * @param   number      Number of selectors.
 * @param   properties  List of properties.
 *
 * @return  A new CSSNode object.
 */
CSSNode* CSS_NewNode (char** selectors, unsigned number, CSSPropertyList* properties);

/**
 * Destroy a CSSNode object.
 *
 * @param   node    The object to destroy.
 */
void CSS_DestroyNode (CSSNode* node);

#endif
