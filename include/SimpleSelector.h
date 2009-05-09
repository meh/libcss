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

#ifndef _LIB_CSS_SIMPLESELECTOR_H
#define _LIB_CSS_SIMPLESELECTOR_H

/**
 * CSSAttribute types.
 */
typedef enum {
    CSSAttributePresent    = 0x01, /**< [att] */
    CSSAttributeExactly    = 0x02, /**< [att=val] */
    CSSAttributeIn         = 0x04, /**< [att~=val] */
    CSSAttributeStartsWith = 0x08  /**< [att|=val] */
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

typedef enum {
    CSSTypeSelector          = 0x01,
    CSSUniversalSelector     = 0x02,
    CSSAttributeSelector     = 0x04,
    CSSIDSelector            = 0x08,
    CSSClassSelector         = 0x16,
    CSSPseudoSelector        = 0x32
} CSSSelectorType;

#define CSS_SELECTOR_IS_TYPE(selector)          (selector->flags & CSSTypeSelector)
#define CSS_SELECTOR_IS_UNIVERSAL(selector)     (selector->flags & CSSUniversalSelector)
#define CSS_SELECTOR_IS_ATTRIBUTE(selector)     (selector->flags & CSSAttributeSelector)
#define CSS_SELECTOR_IS_ID(selector)            (selector->flags & CSSIDSelector)
#define CSS_SELECTOR_IS_CLASS(selector)         (selector->flags & CSSClassSelector)
#define CSS_SELECTOR_IS_PSEUDO(selector)        (selector->flags & CSSPseudoSelector)

/**
 * Structure that represents a simple selector
 * (see http://www.w3.org/TR/CSS2/selector.html#selector-syntax)
 */
typedef struct _CSSSimpleSelector {
    int             flags;     /**< simple selector type */
    int             relation;  /**< relationship with the parent simple selector */
    char*           type;      /**< type value */
    CSSAttribute*   attribute; /**< attribute value */
    char*           id;        /**< id name */
    char*           class;     /**< class name */
    char*           pseudo;    /**< pseudo name */
} CSSSimpleSelector;

/**
 * Create a CSSSimpleSelector object.
 *
 * All the values have to be *alloc'd by you because the pointers will be
 * copied as they are.
 *
 * @param   flags           Types present in the simple selector in a bitwise manner.
 * @param   relation        Relationship with the previous simple selector.
 * @param   type            Value of the type (eg. panel).
 * @param   attribute       Value of the attribute (eg. [width=34px]).
 * @param   class           Value of the class (eg. .black).
 * @param   pseudoClass     Value of the pseudoClass (eg. button:hover).
 * @param   pseudoElement   Value of the pseudoElement (eg. textarea:first-line).
 *
 * @return  The new CSSSimpleSelector.
 */
CSSSimpleSelector* CSS_NewSimpleSelector (int flags, int relation,
    char*           type,
    CSSAttribute*   attribute,
    char*           id,
    char*           class,
    char*           pseudoClass,
    char*           pseudoElement
);

/**
 * Destroy a CSSSimpleSelector object.
 *
 * @param   selector    The object to destroy.
 */
void CSS_DestroySimpleSelector (CSSSimpleSelector* selector);

#endif
