/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:00:23 by tgeodude          #+#    #+#             */
/*   Updated: 2022/06/30 23:00:25 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	alone_number(const char *s)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i, s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			count++;
	}
	if (count == 1)
		return (1);
	return (0);
}
