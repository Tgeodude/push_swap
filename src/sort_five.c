/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:57:44 by tgeodude          #+#    #+#             */
/*   Updated: 2022/03/15 19:00:08 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_astek **head1)
{
	t_astek	*tmp1;
	int		min;

	tmp1 = (*head1);
	min = 2147483647;
	while (tmp1)
	{
		if (tmp1->index < min)
			min = tmp1->index;
		tmp1 = tmp1->next;
	}
	return (min);
}

void	sorting_five_two(t_astek **head1, t_bstek **head2)
{
	int	min2;

	min2 = find_min(head1);
	if ((*head1)->index != min2 || (*head1)->next->index != min2)
	{
		while (((*head1)->index != min2))
			rra(head1);
		pb(head1, head2);
	}
	else
	{
		if ((*head1)->index != min2)
			pb(head1, head2);
		else
		{
			ra(head1);
			pb(head1, head2);
		}
	}
}

int	sorting_five_one(t_astek **head1, t_bstek **head2, int count)
{
	int	min1;

	min1 = find_min(head1);
	if ((*head1)->index != min1 || (*head1)->next->index != min1)
	{
		while (((*head1)->index != min1))
			rra(head1);
		pb(head1, head2);
	}
	else
	{
		if ((*head1)->index != min1)
			pb(head1, head2);
		else
		{
			ra(head1);
			pb(head1, head2);
		}
	}
	if (count == 4)
		return (0);
	sorting_five_two(head1, head2);
	return (0);
}
