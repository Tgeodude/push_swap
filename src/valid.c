#include "push_swap.h"

void    chech_valid(const char *s)
{
    int i;

    i = -1;
    while (i++, s[i])
    {
        if (s[i] == 45 && (!(s[i + 1] >= '0' && s[i + 1] <= '9')))
        {
            write(2, "Error\n", 6);
            exit(0);
        }
        if ((s[i] >= 48 && s[i] <= 57) && s[i + 1] == 45 && s[i + 1])
        {
            write(2, "Error\n", 6);
            exit(0);
        }
        if (s[i] != 45 && s[i] != 32)
        {
            if (s[i] < 48 || s[i] > 57)
            {
                write(2, "Error\n", 6);
                exit(0);
            }
        }
    }
}