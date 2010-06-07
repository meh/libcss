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

#ifndef _LIBCSS_SELECTOR_SIMPLESELECTORDATA_H
#define _LIBCSS_SELECTOR_SIMPLESELECTORDATA_H

#include "Attribute.h"

typedef struct _CSSSimpleSelectorData {
    char*            type;          /*<< Value of the type (eg. panel). */
    CSSAttribute*    attribute;     /*<< Value of the attribute (eg. [width=34px]). */
    char*            id;            /*<< */
    char*            klass;         /*<< Value of the class (eg. .black). */
    CSSPseudoClass** pseudoClass;   /*<< Value of the pseudoClass (eg. button:hover). */
    char*            pseudoElement; /*<< Value of the pseudoElement (eg. textarea:first-line). */
} CSSSimpleSelectorData;

CSSSimpleSelectorData* CSS_NewSimpleSelectorData (
    char*            type,
    CSSAttribute*    attribute,
    char*            id,
    char*            klass,
    CSSPseudoClass** pseudoClass,
    char*            pseudoElement
);

void CSS_DestroySimpleSelectorData (CSSSimpleSelectorData* data);

#endif
