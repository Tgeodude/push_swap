#include "push_swap.h"

void    sorting_five(a_stek **head1, b_stek **head2)
{
    if ((*head2)->index < (*head1)->index)
    {
        pa(head1, head2);
        while ((*head2)->index < (*head1)->next->next->index)
            rra(head1);
        pa(head1, head2);
        while ((*head1)->index > (*head1)->next->index)
            ra(head1);
        ra(head1);
        exit(0);
    }
    else if ((*head2)->next->index > (*head1)->index)
    {
        while ((*head1)->next->next->index > (*head2)->next->index)
            rra(head1);
        sb(head2);
        pa(head1, head2);
        while ((*head2)->index < (*head1)->next->next->index)
            rra(head1);
        pa(head1, head2);
        while ((*head1)->index > (*head1)->next->index)
            ra(head1);
        ra(head1);
        exit(0);
    }
    pa(head1, head2);
    pa(head1, head2);
    exit(0);
}