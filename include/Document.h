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

#ifndef _LIBCSS_DOCUMENT_H
#define _LIBCSS_DOCUMENT_H

#include "NodeList.h"

/**
 * Structure that represents a CSS document.
 */
typedef struct _CSSDocument {
    CSSNodeList*    content; /**< Nodes in the CSS document */
    unsigned        number;  /**< Number of nodes in the CSS document */
} CSSDocument;

/**
 * Parse a CSS document in a string.
 *
 * @param   text    The CSS to parse.
 * @param   func    The function that gets the CSSNodes, if NULL the return value
 *                  will be a tree of CSSNodes.
 *
 * @return  NULL if func isn't NULL.
 */
CSSDocument* CSS_Parse (const char* text, void (*func)(CSSNode*));

/**
 * Parse a CSS document in a file.
 *
 * @param   path    The CSS file to parse.
 * @param   func    The function that gets the CSSNodes, if NULL the return value
 *                  will be a tree of CSSNodes.
 *
 * @return  NULL if func isn't NULL.
 */
CSSDocument* CSS_ParseFile (const char* path, void (*func)(CSSNode*));

#endif
