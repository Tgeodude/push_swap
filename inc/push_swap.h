#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data {
    int *stek_a;
    int *stek_b;
    int count;
    int max;
    int min;
}   t_data;

typedef struct Node1 {
    int index;
    struct Node1 *next;
} a_stek;

typedef struct Node2 {
    int index;
    struct Node2 *next;
} b_stek;


int     ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *string, int symbol);
size_t  ft_strlen(const char *s);
void    parsing_line(t_data *push_swap, int argc, char **argv);
void    free_line(char **s);
void    chech_valid(const char *s);
void    sorting_mass(t_data *push_swap);
void    put_in_list(t_data *push_swap, a_stek **head1);
void    push_in_list(a_stek **head1, int value);
void    sa(a_stek **head1);
void    sb(b_stek **head2);
void    ss(a_stek **head1, b_stek **head2);
void    ra(a_stek **head1);
void    rb(b_stek **head2);
void    rr(a_stek **head1, b_stek **head2);
void    rra(a_stek **head1);
void    rrb(b_stek **head2);
void    rrr(a_stek **head1, b_stek **head2);
void    pb(a_stek **head1, b_stek **head2);
void    pa(a_stek **head1, b_stek **head2);
void    pop_b(b_stek **head2);
void    pop_a(a_stek **head1);
int     sorting_three_a(t_data *push_swap, a_stek **head1);
int     sorting_three_b(b_stek **head2);
void    sorting_five(a_stek **head1, b_stek **head2);
void    sorting_three(t_data *push_swap, a_stek **head1);
void    sorting_hund(a_stek **head1, b_stek **head2, int n);

#endif