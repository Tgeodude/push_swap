#include "push_swap.h"

int main(int argc, char **argv)
{
    t_data push_swap;
    a_stek *head1;
    b_stek *head2;
    a_stek *tmp;
    int i;

    head1 = NULL;
    head2 = NULL;
    parsing_line(&push_swap, argc, argv);
    sorting_mass(&push_swap);
    put_in_list(&push_swap, &head1);
    if (push_swap.count <= 3)
        sorting_three(&push_swap, &head1);
    if (push_swap.count == 5)
    {
        tmp = head1;
        i = -1;
        while (i++, tmp->index < tmp->next->index && tmp)
            tmp = tmp->next;
        if (i == push_swap.count)
            exit(0);
        pb(&head1, &head2);
        pb(&head1, &head2);
        sorting_three_a(&push_swap, &head1);
        sorting_three_b(&head2);
        sorting_five(&head1, &head2);
    }
    //sleep(30);
    exit (0);
}