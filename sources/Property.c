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

#include "Property.h"
#include "common.h"

CSSProperty*
CSS_NewProperty (const char* name, const char* value, int important)
{
    CSSProperty* property = (CSSProperty*) malloc(sizeof(CSSProperty));
    property->name        = strdup(name);
    property->value       = strdup(value);
    property->important   = important;

    return property;
}

void
CSS_DestroyProperty (CSSProperty* property)
{
    free(property->name);
    free(property->value);
    free(property);
}

