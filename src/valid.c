#include "push_swap.h"

void    chech_valid(const char *s)
{
    if (*s != 45 && *s != 32)
    {
        if (*s < 48 || *s > 57)
        {
            write(1, "Errornoword\n", 12);
            exit(0);
        }
    }
}