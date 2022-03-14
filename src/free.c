#include "push_swap.h"

void free_line(char **s)
{
    int i;

    i = -1;
    while (i++, s[i])
        free(s[i]);
    free(s);
}