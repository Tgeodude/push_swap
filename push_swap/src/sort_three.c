/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:03:11 by tgeodude          #+#    #+#             */
/*   Updated: 2022/03/15 21:39:44 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_two(t_astek **head1)
{
	t_astek	*tmp1;

	tmp1 = (*head1);
	tmp1 = tmp1->next;
	if ((*head1)->index > (*head1)->next->index)
	{
		sa(head1);
		exit(0);
	}
}

void	sorting_three_maxmin(t_astek **head1, int min, int max)
{
	if (max == (*head1)->index)
	{
		if (min == (*head1)->next->index)
		{
			ra(head1);
			exit(0);
		}
		else
		{
			sa(head1);
			rra(head1);
			exit(0);
		}
	}
}

void	sorting_three_minmax(t_astek **head1, int min, int max)
{
	if (min == (*head1)->index)
	{
		if (max == (*head1)->next->index)
		{
			sa(head1);
			ra(head1);
			exit(0);
		}
	}
}

void	sorting_three(t_data *push_swap, t_astek **head1)
{
	if (push_swap->count == 2)
		sorting_two(head1);
	if (push_swap->count == 3)
	{
		sorting_three_maxmin(head1, push_swap->min, push_swap->max);
		sorting_three_minmax(head1, push_swap->min, push_swap->max);
		if (push_swap->min == (*head1)->next->index)
		{
			if (push_swap->max == (*head1)->next->next->index)
			{
				sa(head1);
				exit(0);
			}
		}
		if (push_swap->max == (*head1)->next->index)
		{
			if (push_swap->min == (*head1)->next->next->index)
			{
				rra(head1);
				exit(0);
			}
		}
	}
}
