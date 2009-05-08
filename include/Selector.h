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

#ifndef _LIB_CSS_SELECTOR_H
#define _LIB_CSS_SELECTOR_H

#include "libxml/tree.h"

#ifndef LIBXML_TREE_ENABLED
#error  "Your libxml2 hasn't tree support."
#endif

typedef enum {
    CSSTypeSelector         = 0x01,
    CSSUniversalSelector    = 0x02,
    CSSAttributeSelector    = 0x04,
    CSSIDSelector           = 0x08,
    CSSClassSelector        = 0x16
} CSSSelectorType;

#define CSS_SELECTOR_IS_TYPE(selector)      (selector->flags & CSSTypeSelector)
#define CSS_SELECTOR_IS_UNIVERSAL(selector) (selector->flags & CSSUniversalSelector)
#define CSS_SELECTOR_IS_ATTRIBUTE(selector) (selector->flags & CSSAttributeSelector)
#define CSS_SELECTOR_IS_ID(selector)        (selector->flags & CSSIDSelector)
#define CSS_SELECTOR_IS_CLASS(selector)     (selector->flags & CSSClassSelector)

typedef struct _CSSSimpleSelector {
    int     flags;
    char*   type;
    char*   attribute;
    char*   id;
    char*   class;
} CSSSimpleSelector;

typedef struct _CSSSelector {
    CSSSimpleSelector** selectors;
    unsigned            number;
} CSSSelector;

/**
 * Parse a string to a CSSSelector.
 *
 * @param   selector    The string.
 *
 * @return  The CSSSelector.
 */
CSSSelector* CSS_ParseSelector (const char* selector);

/**
 * Match a selector against a xml node.
 *
 * @param   selector    The CSSSelector.
 * @param   node        The xmlNode
 *
 * @return  1 if it matches, 0 otherwise.
 */
int CSS_MatchSelector (const CSSSelector* selector, xmlNode* node);

/**
 * Match a string selector against an xml node.
 *
 * @param   selector    The selector string.
 * @param   node        The xmlNode.
 *
 * @return  1 if it matches, 0 otherwise.
 */
int CSS_MatchSelectorFromString (const char* selector, xmlNode* node);

#endif
