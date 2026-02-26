/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:09:24 by zalkhali          #+#    #+#             */
/*   Updated: 2025/02/10 19:00:41 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	check_args(ac, av);
	stacks = malloc(sizeof * stacks);
	if (stacks == NULL)
		exit(1);
	initialize_stacks(ac, av, stacks);
	joined_args(ac, av, stacks);
	parse_numbers(stacks);
	exit_if_sorted_or_has_duplicates(stacks, 0);
	create_index(stacks);
	if (stacks->size_a == 2 && stacks->stack_a[0] > stacks->stack_a[1])
		swap(stacks->stack_a, stacks->size_a, "sa");
	else if (stacks->size_a == 3)
		sort_three_numbers(stacks);
	else if (stacks->size_a >= 4 && stacks->size_a <= 5)
		sort_four_to_five_numbers(stacks);
	else
		radix_sort(stacks);
	exit_if_sorted_or_has_duplicates(stacks, 1);
	free_and_exit_with_message(stacks, "Error\n");
	return (0);
}
