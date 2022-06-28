/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hund.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:05:11 by tgeodude          #+#    #+#             */
/*   Updated: 2022/03/15 19:55:14 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_bstek **head2)
{
	t_bstek	*tmp;
	int		max;

	max = -2147483648;
	tmp = (*head2);
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	find_max_place(t_bstek **head2)
{
	t_bstek	*tmp;
	int		max;
	int		place;
	int		i;

	max = -2147483648;
	tmp = (*head2);
	i = -1;
	while (i++, tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			place = i;
		}
		tmp = tmp->next;
	}
	return (place);
}

void	sorting_hund_two(t_astek **head1, t_bstek **head2, int n)
{
	int	max;
	int	place;

	while ((*head2))
	{
		max = find_max(head2);
		place = find_max_place(head2);
		if (n == 15 && place > 16)
			while ((*head2)->index != max)
				rrb(head2);
		if (n == 30 && place > 31)
			while ((*head2)->index != max)
				rrb(head2);
		else
			while ((*head2)->index != max)
				rb(head2);
		pa(head1, head2);
	}
	exit(0);
}

void	sorting_hund_one(t_astek **head1, t_bstek **head2, int n)
{
	int	counter;

	counter = 0;
	while ((*head1))
	{
		if ((*head1)->index <= counter)
		{
			pb(head1, head2);
			rb(head2);
			counter++;
		}
		else if ((*head1)->index <= counter + n)
		{
			pb(head1, head2);
			counter++;
		}
		else
			ra(head1);
	}
	sorting_hund_two(head1, head2, n);
}
