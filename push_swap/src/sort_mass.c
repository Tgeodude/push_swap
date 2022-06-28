/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:56:20 by tgeodude          #+#    #+#             */
/*   Updated: 2022/03/15 20:01:20 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_data *push_swap)
{
	int	i;
	int	bubble;

	i = -1;
	while (i++, i < push_swap->count)
	{
		if (push_swap->stek_a[i] > push_swap->stek_a[i + 1] \
				&& i < (push_swap->count - 1))
		{
			bubble = push_swap->stek_a[i];
			push_swap->stek_a[i] = push_swap->stek_a[i + 1];
			push_swap->stek_a[i + 1] = bubble;
			bubble = push_swap->stek_b[i];
			push_swap->stek_b[i] = push_swap->stek_b[i + 1];
			push_swap->stek_b[i + 1] = bubble;
			i = -1;
		}
	}
}

void	check_duplicate(t_data *push_swap)
{
	int	i;

	i = -1;
	while (i++, push_swap->stek_a[i])
	{
		if (push_swap->stek_a[i] == push_swap->stek_a[i + 1] \
				&& push_swap->stek_a[i + 1])
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
}

void	sorting_mass(t_data *push_swap)
{
	int	i;

	i = -1;
	push_swap->stek_b = malloc(sizeof(int) * push_swap->count);
	while (i++, i < push_swap->count)
		push_swap->stek_b[i] = i;
	push_swap->min = push_swap->stek_b[0];
	push_swap->max = push_swap->stek_b[(push_swap->count) - 1];
	bubble_sort(push_swap);
	i = -1;
	check_duplicate(push_swap);
	while (i++, i < push_swap->count)
		push_swap->stek_a[i] = push_swap->stek_b[i];
	i = -1;
	while (i++, i < push_swap->count)
		push_swap->stek_b[i] = i;
	bubble_sort(push_swap);
	i = -1;
	while (i++, i < push_swap->count)
		push_swap->stek_a[i] = push_swap->stek_b[i];
	free(push_swap->stek_b);
}
