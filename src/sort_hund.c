#include "push_swap.h"

int    find_max(b_stek **head2)
{
    b_stek *tmp;
    int max;

    max = -2147483648;
    tmp = (*head2);
    while (tmp)
    {
        if (tmp->index > max)
            max = tmp->index;
        tmp = tmp->next;
    }
    return (max);
}

int    find_max_place(b_stek **head2)
{
    b_stek *tmp;
    int max;
    int place;
    int i;

    max = -2147483648;
    tmp = (*head2);
    i = -1;
    while (i++, tmp)
    {
        if (tmp->index > max)
        {
            max = tmp->index;
            place = i;
        }
        tmp = tmp->next;
    }
    return (place);
}

void    sorting_hund(a_stek **head1, b_stek **head2, int n)
{
    int counter;
    int max;
    int place;

    counter = 0;
    while ((*head1))
    {
        if ((*head1)->index <= counter)
        {
            pb(head1, head2);
            rb(head2);
            counter++;
        }
        else if ((*head1)->index <= counter + n)
        {
            pb(head1, head2);
            counter++;
        }
        else
            ra(head1);
    }
    while((*head2))
    {
        max = find_max(head2);
        place = find_max_place(head2);
        if (n == 15 && place > 16)
            while ((*head2)->index != max)
                rrb(head2);
        if (n == 30 && place > 31)
            while ((*head2)->index != max)
                rrb(head2);
        else
            while ((*head2)->index != max)
                rb(head2);
        pa(head1, head2);
    }
    exit(0);
}
