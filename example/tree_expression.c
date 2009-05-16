#include <stdio.h>
#include "css/api.h"
 
int
main (int argc, char* argv[])
{
    CSSTreeExpression* expression;
 
    if (argc < 2) {
        fprintf(stderr, "Expression is missing.\n");
        return -1;
    }
 
    expression = CSS_ParseTreeExpression(argv[1]);
 
    if (expression == NULL) {
        fprintf(stderr, "The expression was invalid.\n");
        return -1;
    }
    else {
        printf("Base:\t%d\n", expression->base);
        printf("Offset:\t%d\n", expression->offset);
    }
 
    return 0;
}

