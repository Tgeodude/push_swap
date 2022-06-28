/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:44:44 by tgeodude          #+#    #+#             */
/*   Updated: 2022/03/15 21:42:09 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *string, int symbol);
size_t	ft_strlen(const char *s);
void	parsing_line(t_data *push_swap, int argc, char **argv);
void	free_line(char **s);
void	chech_valid(const char *s);
void	sorting_mass(t_data *push_swap);
void	put_in_list(t_data *push_swap, t_astek **head1);
void	push_in_list(t_astek **head1, int value);
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
int		sorting_three_a(t_data *push_swap, t_astek **head1);
int		sorting_three_b(t_bstek **head2, t_astek **head1, int count);
int		sorting_five_one(t_astek **head1, t_bstek **head2, int count);
void	sorting_five_two(t_astek **head1, t_bstek **head2);
void	sorting_three(t_data *push_swap, t_astek **head1);
void	sorting_hund_one(t_astek **head1, t_bstek **head2, int n);
void	sorting_hund_two(t_astek **head1, t_bstek **head2, int n);
int		find_count(t_bstek **head2);

#endif
