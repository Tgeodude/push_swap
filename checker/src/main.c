#include "checker.h"

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
	
	if (argc == 1)
		return (write(2, "Error with argc\n", 16) - 15);
    if (argc == 2 && first_word(argv[1]))
		return (write(2, "Error with input\n", 17) - 16);
	parsing_line(&checker, argc, argv);
	put_in_list(&checker, a_stek);
	while (1)
	{
		command = parse_command();
		if (command == -1)
			print_error();
		if (command == 0)
			break ;
		do_command(a_stek, b_stek, command);
	}

}