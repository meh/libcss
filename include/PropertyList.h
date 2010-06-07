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

#ifndef _LIBCSS_PROPERTYLIST_H
#define _LIBCSS_PROPERTYLIST_H

#include "Property.h"

/**
 * Structure that represents a CSSProperty list
 */
typedef struct _CSSPropertyList {
    CSSProperty**   item;   /**< Array of CSSProperty */
    unsigned        length; /**< Length of the list */
} CSSPropertyList;

/**
 * Create a new CSSPropertyList object.
 *
 * @param   properties  Array of properties.
 * @param   number      Length of the array.
 *
 * @return  The new CSSPropertyList object.
 */
CSSPropertyList* CSS_NewPropertyList (CSSProperty** properties, unsigned number);

/**
 * Destroy a CSSPropertyList object.
 *
 * @param   list    The object to destroy
 */
void CSS_DestroyPropertyList (CSSPropertyList* list);

#endif
