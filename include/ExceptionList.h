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

#ifndef _LIB_CSS_EXCEPTIONLIST_H
#define _LIB_CSS_EXCEPTIONLIST_H

#include "Exception.h"

/**
 * Structure that represents an exception list (like the DOMNodeList)
 */
typedef struct _CSSExceptionList {
    CSSException**  item;   /**< Array of CSSException */
    unsigned        length; /**< Length of the list */
} CSSExceptionList;

/**
 * Create a new CSSExceptionList object.
 *
 * @param   exceptions  Array of exceptions.
 * @param   number      Length of the array.
 *
 * @return  The new CSSExceptionList object.
 */
CSSExceptionList* CSS_NewExceptionList (CSSException** exceptions, unsigned number);

/**
 * Destroy a CSSExceptionList object.
 *
 * @param   list    The object to destroy.
 */
void CSS_DestroyExceptionList (CSSExceptionList* list);

#endif
