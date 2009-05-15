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
    size_t i;
    size_t h;
    size_t j;
    char   positive;
    
    // clean spaces
    for (i = 0; i < length && expression[i] == ' '; i++);

    // if the string ended it's 0
    if (i == length) {
        treeExpression->base   = 0;
        treeExpression->offset = 0;
        return treeExpression;
    }

    // check that the next char is accepted
    if (expression[i] != '+' && expression[i] != '-' && expression[i] != 'n' && !isdigit(expression[i])) {
        free(treeExpression);
        return NULL;
    }

    // check that there's a n
    for (h = i; h < length && expression[h] != 'n'; h++);

    // check that there are only digits between i and the n
    for (j = (expression[i] == '+' || expression[i] == '-') ? i+1 : i; j < h-1 && isdigit(expression[j]); j++);

    if (j == h) {
        free(treeExpression);
        return NULL;
    }

    // set the right value
    if (h < length) {
        // if there's just a sign put 1 or -1
        if (i+2 < length && (expression[i] == '+' || expression[i] == '-') && expression[i+1] == 'n') {
            if (expression[i] == '+') {
                treeExpression->base = 1;
            }
            else {
                treeExpression->base = -1;
            }
        }
        else {
            // if it's just n put 1, else convert the string
            treeExpression->base = (expression[i] == 'n')
                ? 1
                : atoi(&expression[i]);
        }

        for (; i < length && expression[i] != 'n'; i++);
        i++;
    }
    else {
        treeExpression->base = 0;
    }

    // clean spaces
    while (i < length && expression[i] == ' ') i++;

    // if the string ended the offset is 0, return the tree expression
    if (i == length) {
        treeExpression->offset = 0;
        return treeExpression;
    }

    // if there's no + or - throw an error
    if (expression[i] != '+' && expression[i] != '-') {
        free(treeExpression);
        return NULL;
    }

    positive = (expression[i] == '+') ? 1 : -1;
    i++;

    // clean spaces
    while (i < length && expression[i] == ' ') i++;

    // check that the other chars are digits and could end with spaces
    for (h = i; h < length && isdigit(expression[h]); h++);
    for (; h < length && expression[h] == ' '; h++);

    if (h < length) {
        free(treeExpression);
        return NULL;
    }

    treeExpression->offset = positive * atoi(&expression[i]);

    return treeExpression;
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
            free(pseudoClass->value);
        }
        else if (CSS_PSEUDOCLASS_IS_NOT(pseudoClass)) {
            CSS_DestroySimpleSelector(pseudoClass->value);
        }
    }

    free(pseudoClass);
}

