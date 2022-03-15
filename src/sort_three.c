#include "push_swap.h"

void    sorting_three(t_data *push_swap, t_astek **head1)
{
    t_astek *tmp1;
    
    if (push_swap->count == 2)
    {
        tmp1 = (*head1);
        tmp1 = tmp1->next;
        if ((*head1)->index > (*head1)->next->index)
        {
            sa(head1);
            exit(0);
        }
    }
    if (push_swap->count == 3)
    {
        if (push_swap->max == (*head1)->index)
        {
            if (push_swap->min == (*head1)->next->index)
            {
                ra(head1);
                exit(0);
            }
            else
            {
                sa(head1);
                rra(head1);
                exit(0);
            }
        }

        if (push_swap->min == (*head1)->index)
        {
            if (push_swap->max == (*head1)->next->index)
            {
                sa(head1);
                ra(head1);
                exit(0);
            }
        }

        if (push_swap->min == (*head1)->next->index)
        {
            if (push_swap->max == (*head1)->next->next->index)
            {
                sa(head1);
                exit(0);
            }
        }

        if (push_swap->max == (*head1)->next->index)
        {
            if (push_swap->min == (*head1)->next->next->index)
            {
                rra(head1);
                exit(0);
            }
        }
    }   
}