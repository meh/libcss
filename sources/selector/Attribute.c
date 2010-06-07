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

#include "selector/Attribute.h"
#include "common.h"

CSSAttribute*
CSS_NewAttribute (int type, char* name, char* value)
{
    CSSAttribute* attribute = (CSSAttribute*) malloc(sizeof(CSSAttribute));
    attribute->type         = type;
    attribute->name         = name;
    attribute->value        = value;

    return attribute;
}

void
CSS_DestroyAttribute (CSSAttribute* attribute)
{
    free(attribute->name);
    free(attribute->value);
    free(attribute);
}

