#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"

typedef struct s_data {
	int	*stek_a;
	int	*stek_b;
	int	count;
	int	max;
	int	min;
}	t_data;

typedef struct Node1 {
	int				index;
	struct Node1	*next;
}	t_astek;

typedef struct Node2 {
	int				index;
	struct Node2	*next;
}	t_bstek;

int		ft_atoi(const char *str);
void	parsing_line(t_data *push_swap, int argc, char **argv);
void	put_in_list(t_data *push_swap, t_astek **head1);
int		ft_strcmp(char *str_1, char *str_2);
void	sa(t_astek **head1);
void	sb(t_bstek **head2);
void	ss(t_astek **head1, t_bstek **head2);
void	ra(t_astek **head1);
void	rb(t_bstek **head2);
void	rr(t_astek **head1, t_bstek **head2);
void	rra(t_astek **head1);
void	rrb(t_bstek **head2);
void	rrr(t_astek **head1, t_bstek **head2);
void	pb(t_astek **head1, t_bstek **head2);
void	pa(t_astek **head1, t_bstek **head2);
void	pop_b(t_bstek **head2);
void	pop_a(t_astek **head1);

#endif