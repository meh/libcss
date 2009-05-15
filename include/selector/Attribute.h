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

#ifndef _LIB_CSS_SELECTOR_ATTRIBUTE_H
#define _LIB_CSS_SELECTOR_ATTRIBUTE_H

/**
 * CSSAttribute types.
 */
typedef enum {
    CSSAttributePresent    = 0x01, /**< [att] */
    CSSAttributeExactly    = 0x02, /**< [att=val] */
    CSSAttributeIn         = 0x04, /**< [att~=val] */
    CSSAttributeStartsWith = 0x08, /**< [att^=val] */
    CSSAttributeEndsWith   = 0x16, /**< [att$=val] */
    CSSAttributeContains   = 0x32, /**< [att*=val] */
    CSSAttributeBeginsWith = 0x64  /**< [att|=val] */
} CSSAttributeType;

/**
 * Structure that represents a CSSAttributeSelector.
 */
typedef struct _CSSAttribute {
    int     type;  /**< attribute's type */
    char*   name;  /**< attribute's name */
    char*   value; /**< attribute's value */
} CSSAttribute;

/**
 * Create a CSSAttribute object.
 *
 * The name and value won't be copied, just assigned (so you have to *alloc them)
 * it's your job to prevent the deletetion of those strings.
 *
 * @param   type    The attribute type.
 * @param   name    The attribute name.
 * @param   value   The attribute value.
 *
 * @return  The new CSSAttribute object.
 */
CSSAttribute* CSS_NewAttribute (int type, char* name, char* value);

/**
 * Destroy a CSSAttribute object.
 *
 * The name and value that were passed will be free'd.
 *
 * @param   attribute   The object to destroy.
 */
void CSS_DestroyAttribute (CSSAttribute* attribute);

#endif
