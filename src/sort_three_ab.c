/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:30:28 by tgeodude          #+#    #+#             */
/*   Updated: 2022/03/15 21:34:29 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_max_min_and_count_a(t_data *push_swap, t_astek **head1)
{
	int		i;
	t_astek	*tmp1;

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

int	sorting_three_a_maxmin(t_astek **head1, int min)
{
	if (min == (*head1)->next->index)
	{
		ra(head1);
		return (0);
	}
	sa(head1);
	rra(head1);
	return (0);
}

int	sorting_three_a_maxmin_two(t_astek **head1, int min)
{
	if (min == (*head1)->next->next->index)
		rra(head1);
	return (0);
}

int	sorting_three_a(t_data *push_swap, t_astek **head1)
{
	find_max_min_and_count_a(push_swap, head1);
	if (push_swap->count == 3)
	{
		if (push_swap->max == (*head1)->index)
			return (sorting_three_a_maxmin(head1, push_swap->min));
		if (push_swap->min == (*head1)->index)
		{
			if (push_swap->max == (*head1)->next->index)
			{
				sa(head1);
				ra(head1);
				return (0);
			}
		}
		if (push_swap->min == (*head1)->next->index)
		{
			if (push_swap->max == (*head1)->next->next->index)
			{
				sa(head1);
				return (0);
			}
		}
	}
	return (sorting_three_a_maxmin_two(head1, push_swap->min));
}

int	find_count(t_bstek **head2)
{
	t_bstek	*tmp1;
	int		i;

	tmp1 = (*head2);
	i = -1;
	while (i++, tmp1)
		tmp1 = tmp1->next;
	return (i);
}
