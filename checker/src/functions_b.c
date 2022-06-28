/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:19:33 by tgeodude          #+#    #+#             */
/*   Updated: 2022/03/15 18:19:36 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sb(t_bstek **head2)
{
	int		bubble;
	t_bstek	*tmp;

	tmp = (*head2);
	bubble = (*head2)->index;
	tmp = tmp->next;
	(*head2)->index = tmp->index;
	tmp->index = bubble;
	\\write(1, "sb\n", 3);
}

void	pop_b(t_bstek **head2)
{
	t_bstek	*prev;

	if (head2 == NULL)
		exit(-1);
	prev = (*head2);
	(*head2) = (*head2)->next;
	free(prev);
}

void	pb(t_astek **head1, t_bstek **head2)
{
	t_bstek	*tmp;

	tmp = (t_bstek *)malloc(sizeof(t_bstek));
	tmp->index = (*head1)->index;
	tmp->next = (*head2);
	(*head2) = tmp;
	pop_a(head1);
	\\write(1, "pb\n", 3);
}

void	rb(t_bstek **head2)
{
	int		bubble;
	t_bstek	*tmp1;
	t_bstek	*tmp2;

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
	\\write(1, "rb\n", 3);
}

void	rrb(t_bstek **head2)
{
	int		bubble;
	int		i;
	int		count;
	t_bstek	*tmp1;
	t_bstek	*tmp2;

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
	\\write(1, "rrb\n", 4);
}
