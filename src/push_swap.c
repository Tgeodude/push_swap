/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <tgeodude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:50:20 by tgeodude          #+#    #+#             */
/*   Updated: 2022/03/15 18:59:16 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	function_count(t_astek **head1, t_data *push_swap)
{
	t_astek	*tmp;
	int		i;

	tmp = (*head1);
	i = 0;
	while (i++, tmp->next && tmp->index < tmp->next->index)
		tmp = tmp->next;
	if (i == push_swap->count)
		exit(3);
}

int	main(int argc, char **argv)
{
	t_data	push_swap;
	t_astek	*head1;
	t_bstek	*head2;

	head1 = NULL;
	head2 = NULL;
	parsing_line(&push_swap, argc, argv);
	sorting_mass(&push_swap);
	put_in_list(&push_swap, &head1);
	function_count(&head1, &push_swap);
	if (push_swap.count <= 3)
		sorting_three(&push_swap, &head1);
	else if (push_swap.count <= 5)
	{
		sorting_five_one(&head1, &head2);
		sorting_five_two(&head1, &head2);
		sorting_three_a(&push_swap, &head1);
		sorting_three_b(&head2, &head1);
		exit(0);
	}
	else if (push_swap.count <= 100)
		sorting_hund(&head1, &head2, 15);
	else if (push_swap.count > 100)
		sorting_hund(&head1, &head2, 30);
	exit (0);
}
