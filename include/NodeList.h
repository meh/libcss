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

#ifndef _LIBCSS_NODELIST_H
#define _LIBCSS_NODELIST_H

#include "Node.h"

/**
 * Structure that representes a CSSProperty list
 */
typedef struct _CSSNodeList {
    CSSNode**   item;   /**< Array of CSSNode */
    unsigned    length; /**< Length of the list */
} CSSNodeList;

/**
 * Create a new CSSNodeLits object.
 *
 * @param   nodes   Array of nodes.
 * @param   number  Length of the array.
 *
 * @return  The new CSSNodeList object.
 */
CSSNodeList* CSS_NewNodeList (CSSNode** nodes, unsigned number);

/**
 * Destroy a CSSPropertyList object.
 *
 * @param   list    The object to destroy.
 */
void CSS_DestroyPropertyList (CSSPropertyList* list);

#endif
