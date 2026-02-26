/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:09:34 by zalkhali          #+#    #+#             */
/*   Updated: 2025/02/08 03:38:35 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(int *stack, int size, char *str)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	ft_putendl_fd(str, 1);
}

void	push(t_stacks *s, char *str)
{
	int	tmp;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (s->size_b <= 0)
			return ;
		tmp = s->stack_b[0];
		ft_memmove(s->stack_a + 1, s->stack_a, sizeof(int) * s->size_a);
		s->stack_a[0] = tmp;
		s->size_b--;
		ft_memmove(s->stack_b, s->stack_b + 1, sizeof(int) * s->size_b);
		s->size_a++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (s->size_a <= 0)
			return ;
		tmp = s->stack_a[0];
		ft_memmove(s->stack_b + 1, s->stack_b, sizeof(int) * s->size_b);
		s->stack_b[0] = tmp;
		s->size_a--;
		ft_memmove(s->stack_a, s->stack_a + 1, sizeof(int) * s->size_a);
		s->size_b++;
	}
	ft_putendl_fd(str, 1);
}

void	rotate(int *stack, int size, char *direction, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "up", 5) == 0)
	{
		tmp = stack[0];
		ft_memmove(stack, stack + 1, sizeof(int) * (size - 1));
		stack[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp = stack[size - 1];
		ft_memmove(stack + 1, stack, sizeof(int) * (size - 1));
		stack[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}

int	find_max(int *stack, int size)
{
	int	max;
	int	i;

	if (size <= 0)
		return (0);
	max = stack[0];
	i = 1;
	while (i < size)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

int	is_array_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size_a - 1)
	{
		if (stacks->stack_a[i] > stacks->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
