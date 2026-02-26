/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:09:57 by zalkhali          #+#    #+#             */
/*   Updated: 2025/02/10 20:12:52 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three_numbers(t_stacks *stacks)
{
	if (stacks->stack_a[2] != 2)
	{
		if (stacks->stack_a[0] == 2)
			rotate(stacks->stack_a, stacks->size_a, "up", "a");
		else
			rotate(stacks->stack_a, stacks->size_a, "down", "a");
	}
	if (stacks->stack_a[0] > stacks->stack_a[1])
		swap(stacks->stack_a, stacks->size_a, "sa");
}

void	sort_four_to_five_numbers(t_stacks *stacks)
{
	while (stacks->size_b <= 1)
	{
		if (stacks->stack_a[0] == 0 || stacks->stack_a[0] == 1)
			push(stacks, "pb");
		else
			rotate(stacks->stack_a, stacks->size_a, "up", "a");
	}
	if (stacks->stack_b[0] == 0)
		swap(stacks->stack_b, stacks->size_a, "sb");
	if (stacks->stack_a[2] != 4)
	{
		if (stacks->stack_a[0] == 4)
			rotate(stacks->stack_a, stacks->size_a, "up", "a");
		else
			rotate(stacks->stack_a, stacks->size_a, "down", "a");
	}
	if (stacks->stack_a[0] > stacks->stack_a[1])
		swap(stacks->stack_a, stacks->size_a, "sa");
	push(stacks, "pa");
	push(stacks, "pa");
}

void	sort_by_bit(t_stacks *stacks, int cur_bit)
{
	int	size;

	size = stacks->size_a;
	while (size-- && !is_array_sorted(stacks))
	{
		if (((stacks->stack_a[0] >> cur_bit) & 1) == 0)
			push(stacks, "pb");
		else
			rotate(stacks->stack_a, stacks->size_a, "up", "a");
	}
}

void	radix_sort_stack_b(t_stacks *stacks, int size_b, int bit_size, int bit)
{
	while (size_b-- && bit <= bit_size && !is_array_sorted(stacks))
	{
		if (((stacks->stack_b[0] >> bit) & 1) == 0)
			rotate(stacks->stack_b, stacks->size_b, "up", "b");
		else
			push(stacks, "pa");
	}
	if (is_array_sorted(stacks))
		while (stacks->size_b != 0)
			push(stacks, "pa");
}

void	radix_sort(t_stacks *stacks)
{
	int	i;
	int	bit_size;
	int	max_number;

	bit_size = 0;
	max_number = find_max(stacks->stack_a, stacks->size_a);
	while (max_number > 0)
	{
		max_number /= 2;
		bit_size++;
	}
	i = -1;
	while (++i <= bit_size)
	{
		sort_by_bit(stacks, i);
		radix_sort_stack_b(stacks, stacks->size_b, bit_size, i + 1);
	}
	while (stacks->size_b != 0)
		push(stacks, "pa");
}
