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

#ifndef _LIBCSS_EXCEPTION_H
#define _LIBCSS_EXCEPTION_H

static char *CSSExceptionText[] = {
    "Something went wrong.\n"
};

/**
 * Structure that represents an exception.
 */
typedef struct _CSSException {
    unsigned    line; /**< The line number where the exception has been thrown */
    unsigned    code; /**< The exception code */
    char*       text; /**< The error text */
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
void CSS_DestroyException (CSSException* exception);

#endif
