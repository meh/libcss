#include <stdio.h>
#include <css/api.h>

int
main (int argc, char* argv[])
{
    CSSSelector*      selector;
    CSSExceptionList* exceptions;

    if (argc < 2) {
        fprintf(stderr, "The selector is missing.\n");
        return -1;
    }

    selector = CSS_ParseSelector(argv[1], exceptions);

    if (expression == NULL) {
        fprintf(stderr, "The selector was invalid.\n");
        return -1;
    }
    else {
        printf("Base:\t%d\n", expression->base);
        printf("Offset:\t%d\n", expression->offset);
    }

    CSS_DestroySelector(selector);
    CSS_DestroyExceptionList(exceptions);

    return 0;
}

