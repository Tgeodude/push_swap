#include "push_swap.h"

void sb(b_stek **head2)
{
    int bubble;
    b_stek *tmp;

    tmp = (*head2);
    bubble = (*head2)->index;
    tmp = tmp->next;
    (*head2)->index = tmp->index;
    tmp->index = bubble;
    write(1, "sb\n", 3);
}

void pop_b(b_stek **head2) 
{
    b_stek *prev;

    if (head2 == NULL) {
        exit(-1);
    }
    prev = (*head2);
    (*head2) = (*head2)->next;
    free(prev);
}

void pb(a_stek **head1, b_stek **head2)
{
    b_stek *tmp;

    tmp = (b_stek *)malloc(sizeof(b_stek));
    tmp->index = (*head1)->index;
    tmp->next = (*head2);
    (*head2) = tmp;
    pop_a(head1);
    write(1, "pb\n", 3);
}

void rb(b_stek **head2)
{
    int bubble;
    b_stek *tmp1;
    b_stek *tmp2;

    tmp1 = (*head2);
    tmp2 = (*head2)->next;
    while (tmp1->next)
    {
        bubble = tmp1->index;
        tmp1->index = tmp2->index;
        tmp2->index = bubble;
        tmp2 = tmp2->next;
        tmp1 = tmp1->next;
    }
    write(1, "rb\n", 3);
}

void rrb(b_stek **head2)
{
    int bubble;
    int i;
    int count;
    b_stek *tmp1;
    b_stek *tmp2;

    tmp1 = (*head2);
    i = -1;
    while (i++, tmp1->next)
        tmp1 = tmp1->next;
    bubble = tmp1->index;
    while (i > -1)
    {
        count = -1;
        tmp2 = (*head2);
        while (count++, count < i)
            tmp2 = tmp2->next;
        tmp1->index = tmp2->index;
        tmp2->index = bubble;
        tmp1 = tmp2;
        i--;
    }
    write(1, "rrb\n", 4);
}
