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

#ifndef _LIBCSS_SELECTOR_SIMPLESELECTOR_H
#define _LIBCSS_SELECTOR_SIMPLESELECTOR_H

#include "SimpleSelectorData.h"
#include "Attribute.h"
#include "PseudoClass.h"

/**
 * CSSSimpleSelector relation with the previous CSSSimpleSelector.
 */
typedef enum {
    CSSDescendantSelector           = 0x01, /**< space combinator */
    CSSChildOfSelector              = 0x02, /**< > combinator */ 
    CSSImmediatelyPrecededSelector  = 0x04, /**< + combinator */
    CSSPrecededSelector             = 0x08  /**< ~ combinator */
} CSSSelectorRelation;

/**
 * CSSSimpleSelector types.
 */
typedef enum {
    CSSTypeSelector          = 0x01, /**< element selector */
    CSSUniversalSelector     = 0x02, /**< * selector */
    CSSAttributeSelector     = 0x04, /**< [] selector */
    CSSIDSelector            = 0x08, /**< # selector */
    CSSClassSelector         = 0x16, /**< . selector */
    CSSPseudoClassSelector   = 0x32, /**< : selector */
    CSSPseudoElementSelector = 0x64  /**< :: selector */
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
    int              flags;         /**< simple selector type */
    int              relation;      /**< relationship with the parent simple selector */
    char*            nspace;        /**< selector namespace */
    char*            type;          /*<< Value of the type (eg. panel). */
    CSSAttribute*    attribute;     /*<< Value of the attribute (eg. [width=34px]). */
    char*            id;            /*<< */
    char*            klass;         /*<< Value of the class (eg. .black). */
    CSSPseudoClass** pseudoClass;   /*<< Value of the pseudoClass (eg. button:hover). */
    char*            pseudoElement; /*<< Value of the pseudoElement (eg. textarea:first-line). */
} CSSSimpleSelector;

/**
 * Create a CSSSimpleSelector object.
 *
 * All the values have to be *alloc'd by you because the pointers will be
 * copied as they are.
 *
 * @param   flags           Types present in the simple selector in a bitwise manner.
 * @param   relation        Relationship with the previous simple selector.
 * @param   nspace          The namespace.
 *
 * @return  The new CSSSimpleSelector.
 */
CSSSimpleSelector* CSS_NewSimpleSelector (int flags, int relation, char* nspace,
    char*            type,
    CSSAttribute*    attribute,
    char*            id,
    char*            klass,
    CSSPseudoClass** pseudoClass,
    char*            pseudoElement
);

/**
 * Create a CSSSimpleSelector object.
 *
 * All the values have to be *alloc'd by you because the pointers will be
 * copied as they are.
 *
 * @param   flags           Types present in the simple selector in a bitwise manner.
 * @param   relation        Relationship with the previous simple selector.
 * @param   nspace          The namespace.
 * @param   data            Simple selector data.
 *
 * @return  The new CSSSimpleSelector.
 */
CSSSimpleSelector* CSS_NewSimpleSelectorFromData (int flags, int relation, char* nspace, CSSSimpleSelectorData* data);


CSSSimpleSelector* CSS_ParseSimpleSelector (const char* selector);

/**
 * Destroy a CSSSimpleSelector object.
 *
 * @param   selector    The object to destroy.
 */
void CSS_DestroySimpleSelector (CSSSimpleSelector* selector);

#endif
