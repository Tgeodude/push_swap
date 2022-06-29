/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:09:41 by tgeodude          #+#    #+#             */
/*   Updated: 2022/03/15 18:09:47 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_astek **head1)
{
	int		bubble;
	t_astek	*tmp;

	tmp = (*head1);
	bubble = (*head1)->index;
	tmp = tmp->next;
	(*head1)->index = tmp->index;
	tmp->index = bubble;
}

void	ra(t_astek **head1)
{
	int		bubble;
	t_astek	*tmp1;
	t_astek	*tmp2;

	tmp1 = (*head1);
	tmp2 = (*head1)->next;
	while (tmp1->next)
	{
		bubble = tmp1->index;
		tmp1->index = tmp2->index;
		tmp2->index = bubble;
		tmp2 = tmp2->next;
		tmp1 = tmp1->next;
	}
}

void	pa(t_astek **head1, t_bstek **head2)
{
	t_astek	*tmp;

	tmp = (t_astek *)malloc(sizeof(t_astek));
	if (!(*head2))
	{
		write(2, "Error: stek b is empty\n", 23);
		exit(1);
	}
	tmp->index = (*head2)->index;
	tmp->next = (*head1);
	(*head1) = tmp;
	pop_b(head2);
}

void	pop_a(t_astek **head1)
{
	t_astek	*prev;

	if (head1 == NULL)
		exit(-1);
	prev = (*head1);
	(*head1) = (*head1)->next;
	free(prev);
}

void	rra(t_astek **head1)
{
	int		bubble;
	int		i;
	int		count;
	t_astek	*tmp1;
	t_astek	*tmp2;

	tmp1 = (*head1);
	i = -1;
	while (i++, tmp1->next)
		tmp1 = tmp1->next;
	bubble = tmp1->index;
	while (i > -1)
	{
		count = -1;
		tmp2 = (*head1);
		while (count++, count < i)
			tmp2 = tmp2->next;
		tmp1->index = tmp2->index;
		tmp2->index = bubble;
		tmp1 = tmp2;
		i--;
	}
}
