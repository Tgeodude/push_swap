/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_duble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:24:41 by tgeodude          #+#    #+#             */
/*   Updated: 2022/06/29 23:53:24 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_astek **head1, t_bstek **head2)
{
	sa(head1);
	sb(head2);
}

void	rr(t_astek **head1, t_bstek **head2)
{
	ra(head1);
	rb(head2);
}

void	rrr(t_astek **head1, t_bstek **head2)
{
	rra(head1);
	rrb(head2);
}

void	chech_valid_two(const char *s)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	if (s[0] == ' ')
	{
		while (++i, s[i])
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				flag = 0;
				break ;
			}
			flag = 1;
		}
	}	
	if (flag || s[0] == '\0')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
