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

#ifndef _LIB_CSS_H
#define _LIB_CSS_H

/* Exceptions */

typedef struct _CSSException {
    unsigned    line;
    unsigned    code;
    char*       text;
} CSSException;

/**
 * Create a new CSSException object.
 *
 * @param   line    Line where the exception has been thrown.
 * @param   code    The exception code.
 *
 * @return  The new CSSException object.
 */
CSSException* CSS_NewException (unsigned line, unsigned code);

/**
 * Destroy a CSSException object.
 *
 * @param   exception   The object to destroy.
 */
void          CSS_DestroyException (CSSException* exception);

/* Parser */

/* Property */

typedef struct _CSSProperty {
    char* name;
    char* value;
} CSSProperty;

/**
 * Create a new CSSProperty object.
 *
 * @param   name    Name of the property.
 * @param   value   Value of the property.
 *
 * @return  A new CSSProperty object.
 */
CSSProperty* CSS_NewProperty (const char* name, const char* value);

/**
 * Destroy a CSSProperty object.
 *
 * @param   property    The object to destroy.
 */
void         CSS_DestroyProperty (CSSProperty* property);

/* Node */

typedef struct _CSSNode {
    char**          selector;
    unsigned        selectorNumber;
    CSSProperty**   properties;
} CSSNode;

/**
 * 
 */
CSSNode* CSS_NewNode (char** selectors, unsigned number, CSSProperty** properties);

typedef struct _CSS {
    CSSNode**   content;
} CSSDocument;

/**
 * Parse a CSS text.
 *
 * @param   text    The CSS to parse.
 * @param   func    The function that gets the CSSNodes, if NULL the return value
 *                  will be a tree of CSSNodes.
 *
 * @return  NULL if func isn't NULL.
 */
CSSDocument* CSS_Parse (const char* text, void (*func)(CSSNode*));

/**
 * Parse a CSS file.
 *
 * @param   path    The CSS file to parse.
 * @param   func    The function that gets the CSSNodes, if NULL the return value
 *                  will be a tree of CSSNodes.
 *
 * @return  NULL if func isn't NULL.
 */
CSSDocument* CSS_ParseFile (const char* path, void (*func)(CSSNode*));

#endif
