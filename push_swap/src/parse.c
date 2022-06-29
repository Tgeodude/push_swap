/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:25:56 by tgeodude          #+#    #+#             */
/*   Updated: 2022/06/29 23:51:11 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		chech_valid_two(argv[i]);
		if (ft_strchr(argv[i], ' '))
			count = parse_argv(argv[i], count, push_swap);
		else
			push_swap->stek_a[count++] = ft_atoi(argv[i]);
	}
	push_swap->count = count;
}
