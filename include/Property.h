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

#ifndef _LIBCSS_PROPERTY_H
#define _LIBCSS_PROPERTY_H

/**
 * Structure that represents a CSS property (like "width: 43px")
 */
typedef struct _CSSProperty {
    int   important; /**< The property's importance */
    char* name;      /**< The property's name */
    char* value;     /**< The property's value */
} CSSProperty;

/**
 * Create a new CSSProperty object.
 *
 * @param   name    Name of the property.
 * @param   value   Value of the property.
 *
 * @return  A new CSSProperty object.
 */
CSSProperty* CSS_NewProperty (const char* name, const char* value, int important);

/**
 * Destroy a CSSProperty object.
 *
 * @param   property    The object to destroy.
 */
void CSS_DestroyProperty (CSSProperty* property);

#endif
