#include "push_swap.h"

int counter(const char *s)
{
    int i;
    int counter;

    i = 0;
    counter = 0;
    while (s[i])
    {
        while ((s[i] < '0' || s[i] > '9') && s[i])
            i++;
        if (s[i] >= '0' && s[i] <= '9')
            counter++;
        while (s[i] >= '0' && s[i] <= '9')
            i++;
    }
    return (counter);
}

int counter_number(int argc, char **argv)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (i++, i < argc)
        count += counter(argv[i]);
    return (count);
}

void    check_duplicate(t_data *push_swap)
{
    int i;
    int n;

    i = -1;
    n = 0;
    while (i++, push_swap->stek_a[i])
    {
        while (n++, push_swap->stek_a[i + n])
        {
            if (push_swap->stek_a[i] == push_swap->stek_a[i + n] && push_swap->stek_a[i + n])
            {
                write(1,"Errordup\n", 9);
                exit(0);
            }
        }
        n = 0;
    }
}

int parse_argv(const char *s, int count, t_data *push_swap)
{
    int i;
    char **s1;

    i = -1;
    while (i++, s[i])
        chech_valid(&s[i]);
    s1 = ft_split(s, ' ');
    i = -1;
    while (i++, s1[i])
        push_swap->stek_a[count++] = ft_atoi(&s1[i][0]);
    free_line(s1);
    return (count);
}

void    parsing_line(t_data *push_swap, int argc, char **argv)
{
    int i;
    int count;

    i = 0;
    count = 0;
    push_swap->stek_a = malloc(sizeof(int*)  * counter_number(argc, argv));
    while (i++, i < argc)
    {
        chech_valid(argv[i]);
        if (ft_strchr(argv[i], ' '))
            count = parse_argv(argv[i], count , push_swap);
        else
            push_swap->stek_a[count++] = ft_atoi(argv[i]);
    }
    push_swap->count = count;
    check_duplicate(push_swap);
}
