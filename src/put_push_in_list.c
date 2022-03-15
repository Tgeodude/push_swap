/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_push_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:55:21 by tgeodude          #+#    #+#             */
/*   Updated: 2022/03/15 18:55:22 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_in_list(t_astek **head1, int value)
{
	t_astek	*tmp;

	tmp = (t_astek *)malloc(sizeof(t_astek));
	tmp->index = value;
	tmp->next = (*head1);
	(*head1) = tmp;
}

void	put_in_list(t_data *push_swap, t_astek **head1)
{
	int	i;
	int	count;

	i = -1;
	count = push_swap->count;
	while (count--, i < count)
		push_in_list(head1, push_swap->stek_a[count]);
}
