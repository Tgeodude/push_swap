#include "checker.h"

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
		++str;
	if ((*str) == '-' || (*str) == '+')
	{
		if ((*str == '-'))
			i = -1;
		++str;
	}
	while ((*str) >= '0' && (*str) <= '9')
	{
		chech_atoi_one(str, h, i);
		check_atoi(str, h, i);
		h = (h * 10) + ((*str) - '0');
		++str;
	}
	return (h * i);
}

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
