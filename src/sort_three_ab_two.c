/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_ab_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:37:11 by tgeodude          #+#    #+#             */
/*   Updated: 2022/03/15 21:42:24 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_three_b(t_bstek **head2, t_astek **head1, int count)
{
	if (count == 4)
	{
		pa(head1, head2);
		exit(0);
	}
	if (find_count(head2) == 2)
	{
		if ((*head2)->index < (*head2)->next->index)
		{
			sb(head2);
			pa(head1, head2);
			pa(head1, head2);
			exit (0);
		}
	}
	pa(head1, head2);
	pa(head1, head2);
	exit (0);
}
