#include "checker.h"

void	do_command(t_astek **a_stek, t_bstek **b_stek, int command)
{
	if (command == 1)
		sa(a_stek);
	else if (command == 2)
		sb(b_stek);
	else if (command == 3)
		ss(a_stek, b_stek);
	else if (command == 4)
		pa(a_stek, b_stek);
	else if (command == 5)
		pb(a_stek, b_stek);
	else if (command == 6)
		ra(a_stek);
	else if (command == 7)
		rb(b_stek);
	else if (command == 8)
		rr(a_stek, b_stek);
	else if (command == 9)
		rra(a_stek);
	else if (command == 10)
		rrb(b_stek);
	else if (command == 11)
		rrr(a_stek, b_stek);
}

int	choose_command(char *str)
{
	if (ft_strcmp(str, "sa\n"))
		return (1);
	if (ft_strcmp(str, "sb\n"))
		return (2);
	if (ft_strcmp(str, "ss\n"))
		return (3);
	if (ft_strcmp(str, "pa\n"))
		return (4);
	if (ft_strcmp(str, "pb\n"))
		return (5);
	if (ft_strcmp(str, "ra\n"))
		return (6);
	if (ft_strcmp(str, "rb\n"))
		return (7);
	if (ft_strcmp(str, "rr\n"))
		return (8);
	if (ft_strcmp(str, "rra\n"))
		return (9);
	if (ft_strcmp(str, "rrb\n"))
		return (10);
	if (ft_strcmp(str, "rrr\n"))
		return (11);
	return (-1);
}

int first_word(char *str)
{
	int	i;

	i = -1;
	while (++i, str[i])
		if (str[i] == 0 && !str[++i])
			return(-2);
	return (ft_atoi(str));
}

int	parse_command(void)
{
	int		command;
	char	*line;

	line = get_next_line(0);
	if (!line)
		return (0);
	command = choose_command(line);
	free(line);
	return (command);
}

int main(int argc, char **argv)
{
    t_astek	*a_stek;
    t_bstek	*b_stek;
	t_data	checker;
	int		command;
	
	a_stek = NULL;
	if (argc == 1)
		return (write(2, "Error with argc\n", 16) - 15);
    if (argc == 2 && first_word(argv[1]))
		return (write(2, "Error with input\n", 17) - 16);
	parsing_line(&checker, argc, argv);
	put_in_list(&checker, &a_stek);
	b_stek = NULL;
	while (1)
	{
		command = parse_command();
		if (command == -1)
			return (write(2, "Error with command\n", 18) - 17);
		if (command == 0)
			break ;
		do_command(&a_stek, &b_stek, command);
	}
	check_is_sort(a_stek);
	return (0);
}