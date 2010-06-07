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

#ifndef _LIBCSS_SELECTOR_PSEUDOCLASS_H
#define _LIBCSS_SELECTOR_PSEUDOCLASS_H

/**
 * This structure represents a tree expression (an+b) in the CSSTreePseudoClass.
 *
 * When a is negative only the positive offset is used, this is usefull to get
 * the first b elements.
 *
 * When b is negative it gets the element starting from the end of the base group.
 *
 * When b is positive it gets the element starting from the beginning of the base group.
 */
typedef struct _CSSTreeExpression {
    int base;   /**< is the a in the expression */
    int offset; /**< is the b in the expression */
} CSSTreeExpression;

/**
 * Parse a string to a CSSTreeExpression object.
 *
 * @param   expression  The string to parse.
 *
 * @return  The parsed CSSTreeExpression object.
 */
CSSTreeExpression* CSS_ParseTreeExpression (const char* expression);

/**
 * Destroy a CSSTreeExpression object.
 *
 * @param   expression  The object to destroy.
 */
void CSS_DestroyTreeExpression (CSSTreeExpression* expression);

#define CSS_PSEUDOCLASS_IS_NORMAL(pseudoClass)  (pseudoClass->type == CSSNormalPseudoClass)
#define CSS_PSEUDOCLASS_IS_TREE(pseudoClass)    (pseudoClass->type == CSSTreePseudoClass)
#define CSS_PSEUDOCLASS_IS_NOT(pseudoClass)     (pseudoClass->type == CSSNotPseudoClass)

/**
 * CSSPseudoClass types.
 */
typedef enum {
    CSSNormalPseudoClass = 0x01, /**< normal pseudo classes */
    CSSTreePseudoClass   = 0x02, /**< tree pseudo classes (eg. :nth-child) */
    CSSNotPseudoClass    = 0x04  /**< :not() pseudo class */
} CSSPseudoClassType;

/**
 * Structure that represents a CSSPseudoClass.
 */
typedef struct _CSSPseudoClass {
    int   type;  /**< pseudo class type */
    char* name;  /**< pseudo class name */
    void* value; /**< pseudo class data */
} CSSPseudoClass;

/**
 * Create a CSSPseudoClass object.
 *
 * The name string has to be allocated by the programmer.
 *
 * @param   type    The pseudo class type.
 * @param   name    The pseudo class name.
 * @param   value   The pseudo class data.
 *
 * @return  The new CSSPseudoClass object.
 */
CSSPseudoClass* CSS_NewPseudoClass (int type, char* name, void* value);

/**
 * Destroy a CSSPseudoClass object.
 *
 * The name value will be free'd by this function.
 *
 * @param   pseudoClass   The object to destroy.
 */
void CSS_DestroyPseudoClass (CSSPseudoClass* pseudoClass);

#endif
