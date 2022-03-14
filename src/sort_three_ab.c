#include "push_swap.h"

void    find_max_min_and_count_a(t_data *push_swap, a_stek **head1)
{
    int i;
    a_stek *tmp1;

    tmp1 = (*head1);
    i = -1;
    push_swap->max = -2147483648;
    push_swap->min = 2147483647;
    while (i++, tmp1)
    {
        if (tmp1->index >= push_swap->max)
            push_swap->max = tmp1->index;
        if (tmp1->index <= push_swap->min)
            push_swap->min = tmp1->index;
        tmp1 = tmp1->next;
    }
    push_swap->count = i;
}

int    sorting_three_a(t_data *push_swap, a_stek **head1)
{
    find_max_min_and_count_a(push_swap, head1);
    if (push_swap->count == 2)
    {
        if ((*head1)->index > (*head1)->next->index)
        {
            sa(head1);
            return(0);
        }
    }
     if (push_swap->count == 3)
    {
        if (push_swap->max == (*head1)->index)
        {
            if (push_swap->min == (*head1)->next->index)
            {
                ra(head1);
                return(0);
            }
            else
            {
                sa(head1);
                rra(head1);
                return(0);
            }
        }

        if (push_swap->min == (*head1)->index)
        {
            if (push_swap->max == (*head1)->next->index)
            {
                sa(head1);
                ra(head1);
                return(0);
            }
        }

        if (push_swap->min == (*head1)->next->index)
        {
            if (push_swap->max == (*head1)->next->next->index)
            {
                sa(head1);
                return(0);
            }
        }

        if (push_swap->max == (*head1)->next->index)
        {
            if (push_swap->min == (*head1)->next->next->index)
            {
                rra(head1);
                return(0);
            }
        }
    }  
    return(0);   
}

int find_count(b_stek **head2)
{
    b_stek *tmp1;
    int i;

    tmp1 = (*head2);
    i = -1;
    while (i++, tmp1)
        tmp1 = tmp1->next;
    return (i);
}

int    sorting_three_b(b_stek **head2)
{
    if (find_count(head2) == 2)
    {
        if ((*head2)->index < (*head2)->next->index)
        {
            sb(head2);
            return(0);
        }
    }
    return(0);
}