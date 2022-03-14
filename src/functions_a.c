#include "push_swap.h"

void sa(a_stek **head1)
{
    int bubble;
    a_stek *tmp;

    tmp = (*head1);
    bubble = (*head1)->index;
    tmp = tmp->next;
    (*head1)->index = tmp->index;
    tmp->index = bubble;
    write(1, "sa\n", 3);
}

void ra(a_stek **head1)
{
    int bubble;
    a_stek *tmp1;
    a_stek *tmp2;

    tmp1 = (*head1);
    tmp2 = (*head1)->next;
    while (tmp1->next)
    {
        bubble = tmp1->index;
        tmp1->index = tmp2->index;
        tmp2->index = bubble;
        tmp2 = tmp2->next;
        tmp1 = tmp1->next;
    }
    write(1, "ra\n", 3);
}

void pa(a_stek **head1, b_stek **head2)
{
    a_stek *tmp;

    tmp = (a_stek *)malloc(sizeof(a_stek));
    tmp->index = (*head2)->index;
    tmp->next = (*head1);
    (*head1) = tmp;
    pop_b(head2);
    write(1, "pa\n", 3);
}

void pop_a(a_stek **head1) 
{
    a_stek *prev;

    if (head1 == NULL) {
        exit(-1);
    }
    prev = (*head1);
    (*head1) = (*head1)->next;
    free(prev);
}

void rra(a_stek **head1)
{
    int bubble;
    int i;
    int count;
    a_stek *tmp1;
    a_stek *tmp2;

    tmp1 = (*head1);
    i = -1;
    while (i++, tmp1->next)
        tmp1 = tmp1->next;
    bubble = tmp1->index;
    while (i > -1)
    {
        count = -1;
        tmp2 = (*head1);
        while (count++, count < i)
            tmp2 = tmp2->next;
        tmp1->index = tmp2->index;
        tmp2->index = bubble;
        tmp1 = tmp2;
        i--;
    }
    write(1, "rra\n", 4);
}