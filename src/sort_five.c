#include "push_swap.h"

int find_min(a_stek **head1)
{
    a_stek *tmp1;
    int min;

    tmp1 = (*head1);
    min = 2147483647;
    while (tmp1)
    {
        if (tmp1->index < min)
            min = tmp1->index;
        tmp1 = tmp1->next;
    }
    return (min);
}

void    sorting_five(a_stek **head1, b_stek **head2)
{
    int min1;
    int min2;

    min1 = find_min(head1);
    if ((*head1)->index != min1 || (*head1)->next->index != min1)
    {
        while (((*head1)->index != min1))
            rra(head1);
        pb(head1, head2);
    }
    else
    {
        if ((*head1)->index != min1)
            pb(head1, head2);
        else
        {
            ra(head1);
            pb(head1, head2);
        }
    }
    min2 = find_min(head1);
    if ((*head1)->index != min2 || (*head1)->next->index != min2)
    {
        while (((*head1)->index != min2))
            rra(head1);
        pb(head1, head2);
    }
    else
    {
        if ((*head1)->index != min2)
            pb(head1, head2);
        else
        {
            ra(head1);
            pb(head1, head2);
        }
    }
}