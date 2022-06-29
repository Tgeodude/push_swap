/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:47:13 by tgeodude          #+#    #+#             */
/*   Updated: 2022/06/29 22:47:14 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	counter(const char *s)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while ((s[i] < '0' || s[i] > '9') && s[i])
			i++;
		if (s[i] >= '0' && s[i] <= '9')
			counter++;
		while (s[i] >= '0' && s[i] <= '9')
			i++;
	}
	return (counter);
}

int	counter_number(int argc, char **argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i++, i < argc)
		count += counter(argv[i]);
	return (count);
}

int	parse_argv(char *s, int count, t_data *push_swap)
{
	int		i;
	char	**s1;
	char	*s2;

	i = -1;
	s2 = s;
	while (i++, s2[i])
	{
		chech_valid(&s2[i]);
		if (s2[i] == '\t')
			s2[i] = ' ';
	}
	s1 = ft_split(s2, ' ');
	i = -1;
	while (i++, s1[i])
		push_swap->stek_a[count++] = ft_atoi(&s1[i][0]);
	free_line(s1);
	return (count);
}

void	parsing_line(t_data *push_swap, int argc, char **argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (argc <= 1)
	{
		write(2, "Error: input is empty\n", 22);
		exit(1);
	}
	push_swap->stek_a = malloc(sizeof(int *) * counter_number(argc, argv));
	while (i++, i < argc)
	{
		chech_valid(argv[i]);
		if (ft_strchr(argv[i], ' '))
			count = parse_argv(argv[i], count, push_swap);
		else
			push_swap->stek_a[count++] = ft_atoi(argv[i]);
	}
	push_swap->count = count;
}

void	chech_valid(const char *s)
{
	int	i;

	i = -1;
	while (i++, s[i])
	{
		if (s[i] == 45 && (!(s[i + 1] >= '0' && s[i + 1] <= '9')))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		if ((s[i] >= 48 && s[i] <= 57) && s[i + 1] == 45 && s[i + 1])
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		if (s[i] != 45 && s[i] != 32 && (s[i] < '\t' && s[i] > '\r'))
		{
			if (s[i] < 48 || s[i] > 57)
			{
				write(2, "Error\n", 6);
				exit(0);
			}
		}
	}
}
