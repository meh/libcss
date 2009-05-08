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
    int     flags; /**< attribute's type */
    char*   name;  /**< attribute's name */
    char*   value; /**< attribute's value */
} CSSAttribute;

typedef enum {
    CSSTypeSelector          = 0x01,
    CSSUniversalSelector     = 0x02,
    CSSAttributeSelector     = 0x04,
    CSSIDSelector            = 0x08,
    CSSClassSelector         = 0x16,
    CSSPseudoClassSelector   = 0x32,
    CSSPseudoElementSelector = 0x64
} CSSSelectorType;

#define CSS_SELECTOR_IS_TYPE(selector)          (selector->flags & CSSTypeSelector)
#define CSS_SELECTOR_IS_UNIVERSAL(selector)     (selector->flags & CSSUniversalSelector)
#define CSS_SELECTOR_IS_ATTRIBUTE(selector)     (selector->flags & CSSAttributeSelector)
#define CSS_SELECTOR_IS_ID(selector)            (selector->flags & CSSIDSelector)
#define CSS_SELECTOR_IS_CLASS(selector)         (selector->flags & CSSClassSelector)
#define CSS_SELECTOR_IS_PSEUDOCLASS(selector)   (selector->flags & CSSPseudoClassSelector)
#define CSS_SELECTOR_IS_PSEUDOELEMENT(selector) (selector->flags & CSSPseudoElementSelector)

/**
 * Structure that represents a simple selector
 * (see http://www.w3.org/TR/CSS2/selector.html#selector-syntax)
 */
typedef struct _CSSSimpleSelector {
    int             flags;         /**< simple selector type */
    int             relation;      /**< relationship with the parent simple selector */
    char*           type;          /**< type value */
    CSSAttribute*   attribute;     /**< attribute value */
    char*           id;            /**< id name */
    char*           class;         /**< class name */
    char*           pseudoClass;   /**< pseudoClass name */
    char*           pseudoElement; /**< pseudoElement nme */
} CSSSimpleSelector;

#endif
