/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:34:12 by tgeodude          #+#    #+#             */
/*   Updated: 2022/03/15 18:34:13 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_atoi(const char *str, int h, int i)
{
	if ((str[0]) == '9' && h == 214748364)
	{
		if (i == -1)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
	if (h > 214748364)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (i != -1 && h == 214748364 && ((*str) - '0') > 7)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	chech_atoi_one(const char *str, int h, int i)
{
	if ((str[0]) == '9' && h == 214748364)
	{
		if (i == -1)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	h;

	h = 0;
	i = 1;
	while ((*str) == ' ' || ((*str) >= '\t' && (*str) <= '\r'))
			str++;
	if ((*str) == '-' || (*str) == '+')
	{
		if ((*str == '-'))
			i = -1;
		str++;
	}
	while ((*str) >= '0' && (*str) <= '9')
	{
		chech_atoi_one(str, h, i);
		check_atoi(str, h, i);
		h = (h * 10) + ((*str) - '0');
		str++;
	}
	return (h * i);
}

char	*ft_strchr(const char *string, int symbol)
{
	unsigned char	tmp;

	tmp = symbol;
	while (*string)
	{
		if (*string == tmp)
			return ((char *)string);
		string++;
	}
	if (symbol == '\0')
		return ((char *)(string + ft_strlen(string)));
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
