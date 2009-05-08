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

#include "SimpleSelector.h"
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

CSSSimpleSelector*
CSS_NewSimpleSelector (int flags, int relation, char* type, CSSAttribute* attribute, char* id, char* class, char* pseudoClass, char* pseudoElement)
{ 
    CSSSimpleSelector* selector = (CSSSimpleSelector*) malloc(sizeof(CSSSimpleSelector));
    selector->flags             = flags;
    selector->relation          = relation;
    selector->type              = type;
    selector->attribute         = attribute;
    selector->id                = id;
    selector->class             = class;
    selector->pseudoClass       = pseudoClass;
    selector->pseudoElement     = pseudoElement;

    return selector;
}

void
CSS_DestroySimpleSelector (CSSSimpleSelector* selector)
{
    if (selector->type) {
        free(selector->type);
    }

    if (selector->attribute) {
        CSS_DestroyAttribute(selector->attribute);
    }

    if (selector->id) {
        free(selector->id);
    }

    if (selector->class) {
        free(selector->class);
    }

    if (selector->pseudoClass) {
        free(selector->pseudoClass);
    }

    if (selector->pseudoElement) {
        free(selector->pseudoElement);
    }

    free(selector);
}
