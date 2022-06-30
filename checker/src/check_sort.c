/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:46:11 by tgeodude          #+#    #+#             */
/*   Updated: 2022/06/30 15:01:45 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_is_sort(t_astek *a_stek, t_bstek *b_stek)
{
	t_astek	*tmp1;

	tmp1 = (a_stek);
	if (b_stek)
		return (write(1, "KO\n", 3) - 2);
	while (tmp1->next != NULL)
	{
		if (!(tmp1->index < tmp1->next->index))
		{
			write(1, "KO\n", 3);
			break ;
		}
		if (tmp1->next->next == NULL && tmp1->next != NULL)
		{
			write(1, "OK\n", 3);
			break ;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int	ft_strlen_ps(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *str_1, char *str_2)
{
	int	i;

	i = 0;
	if (!str_1 || !str_2)
		return (0);
	if (ft_strlen_ps(str_1) == ft_strlen_ps(str_2))
	{
		while (str_1[i] == str_2[i])
			i++;
		i--;
		if (i == ft_strlen_ps(str_1))
			return (1);
	}
	return (0);
}

void	check_duplicate(t_data *push_swap)
{
	int	i;
	int	j;

	i = -1;
	while (i++, i < push_swap->count - 1)
	{
		j = 0;
		while (j++, i + j < push_swap->count)
		{
			if (push_swap->stek_a[i] == push_swap->stek_a[i + j])
			{
				write(2, "Error\n", 6);
				exit(1);
			}
		}
	}
}
