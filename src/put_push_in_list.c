#include "push_swap.h"

void    push_in_list(a_stek **head1, int value)
{
    a_stek *tmp;

    tmp = (a_stek *)malloc(sizeof(a_stek));
    tmp->index = value;
    tmp->next = (*head1);
    (*head1) = tmp;
}

void    put_in_list(t_data *push_swap, a_stek **head1)
{
    int i;
    int count;

    i = -1;
    count = push_swap->count;
    while (count--, i < count)
        push_in_list(head1,push_swap->stek_a[count]);
}

