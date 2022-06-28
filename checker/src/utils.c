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

int	parse_argv(const char *s, int count, t_data *push_swap)
{
	int		i;
	char	**s1;

	i = -1;
	while (i++, s[i])
		chech_valid(&s[i]);
	s1 = ft_split(s, ' ');
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

static size_t	ft_quantity(char const *s, char c)
{
	size_t	k;
	size_t	i;

	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			return (k);
		while (s[i] != c && s[i])
			i++;
		k++;
	}
	return (k);
}

static size_t	ft_word(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
		{
			i++;
			j++;
		}
		while (s[i] != c && s[i])
			i++;
		return (i - j);
	}
	return (0);
}

static void	*ft_free(char **s1)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		free(s1[i]);
		i++;
	}
	free(s1);
	return (NULL);
}

static void	*ft_splt(char const *s, char c, char **s1, size_t j)
{
	size_t	k;
	size_t	i;

	k = -1;
	while (k++, k < j)
	{
		i = -1;
		s1[k] = malloc((ft_word(s, c) + 1));
		if (!s1[k])
			return (ft_free(s1));
		while (i++, i < ft_word(s, c))
		{
			while (*s == c && *s)
				s++;
			s1[k][i] = s[i];
		}
		s1[k][i] = '\0';
		while (*s != c && *s)
			s++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**s1;
	size_t	j;

	if (!s)
		return (NULL);
	j = ft_quantity(s, c);
	s1 = malloc((j + 1) * sizeof(char *));
	if (!s1)
		return (NULL);
	ft_splt(s, c, s1, j);
	s1[j] = NULL;
	return (s1);
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
		if (s[i] != 45 && s[i] != 32)
		{
			if (s[i] < 48 || s[i] > 57)
			{
				write(2, "Error\n", 6);
				exit(0);
			}
		}
	}
}

void	free_line(char **s)
{
	int	i;

	i = -1;
	while (i++, s[i])
		free(s[i]);
	free(s);
}