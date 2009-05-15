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

#include "selector/PseudoClass.h"
#include "selector/SimpleSelector.h"
#include "common.h"
#include <ctype.h>

CSSTreeExpression*
CSS_ParseTreeExpression (const char* expression)
{
    CSSTreeExpression* treeExpression = (CSSTreeExpression*) malloc(sizeof(CSSTreeExpression));

    size_t length = strlen(expression);
    size_t i      = 0;
    size_t h;
    
    // clean spaces
    while (i < length && expression[i] == ' ') {
        i++;
    }

    // if the string ended throw error
    if (i == length) {
        goto tree_expression_parse_error;
    }

    // check that the next char is accepted
    if (expression[i] != '+' && expression[i] != '-' && expression[i] != 'n' && !isdigit(expression[i])) {
        goto tree_expression_parse_error;
    }

    // set the right value
    if (expression[i] != 'n') {
        if (i+2 < length && expression[i+1] == 'n') {
            if (expression[i] == '+') {
                treeExpression->base = 1;
            }
            else {
                treeExpression->base = -1;
            }
        }
        else {
            treeExpression->base = atoi(&expression[i]);
        }
    }
    else {
        treeExpression->base = 1;
    }

    // clean spaces
    while (i < length && expression[i] == ' ') {
        i++;
    }

    // if the string ended the offset is 0, return the tree expression
    if (i == length) {
        treeExpression->offset = 0;
        goto tree_expression_parse_end;
    }

    // if there's no + or - throw an error
    if (!(expression[i] == '+' || expression[i] == '-')) {
        goto tree_expression_parse_error;
    }

    // check that the other chars are digits
    for (h = i+1; h < length && (isdigit(expression[h]) || expression[h] == ' '); h++);

    if (h < length) {
        goto tree_expression_parse_error;
    }

    treeExpression->offset = atoi(&expression[i]);

tree_expression_parse_end:
    return treeExpression;

tree_expression_parse_error:
    free(treeExpression);
    return NULL;
}

CSSPseudoClass*
CSS_NewPseudoClass (int type, char* name, void* value)
{
    CSSPseudoClass* pseudoClass = (CSSPseudoClass*) malloc(sizeof(CSSPseudoClass));
    pseudoClass->type           = type;
    pseudoClass->name           = name;
    pseudoClass->value          = value;

    return pseudoClass;
}

void
CSS_DestroyPseudoClass (CSSPseudoClass* pseudoClass)
{
    free(pseudoClass->name);

    if (pseudoClass->value) {
        if (CSS_PSEUDOCLASS_IS_TREE(pseudoClass)) {
            CSS_DestroyTreeExpression(pseudoClass->value);
        }
        else if (CSS_PSEUDOCLASS_IS_NOT(pseudoClass)) {
            CSS_DestroySimpleSelector(pseudoClass->value);
        }
    }

    free(pseudoClass);
}

