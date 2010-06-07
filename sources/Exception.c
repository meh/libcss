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

#include "Exception.h"
#include "common.h"

CSSException*
CSS_NewException (unsigned line, unsigned code)
{
    CSSException* exception = (CSSException*) malloc(sizeof(CSSException));
    exception->line         = line;
    exception->code         = code;
    exception->text         = CSSExceptionText[code];

    return exception;
}

void
CSS_DestroyException (CSSException* exception)
{
    free(exception);
}

