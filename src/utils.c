/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:10:06 by zalkhali          #+#    #+#             */
/*   Updated: 2025/02/10 17:15:35 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exit_if_sorted_or_has_duplicates(t_stacks *stacks, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < stacks->size_a)
		{
			j = i + 1;
			while (j < stacks->size_a)
			{
				if (stacks->stack_a[i] == stacks->stack_a[j])
					free_and_exit_with_message(stacks, "Error\n");
				j++;
			}
			i++;
		}
	}
	if (is_array_sorted(stacks))
		free_and_exit_with_message(stacks, NULL);
}

void	parse_numbers(t_stacks *stacks)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_split(stacks->joined_args, ' ');
	if (!tmp)
		free_and_exit_with_message(stacks, "Error\n");
	validate_args(tmp, stacks);
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		stacks->stack_a[j++] = ft_atoi(tmp[i++]);
		free(tmp[i - 1]);
	}
	free(tmp);
}

void	initialize_stacks(int ac, char **av, t_stacks *stacks)
{
	int	i;
	int	count;

	stacks->joined_args = NULL;
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
	i = 0;
	while (--ac)
	{
		count = ft_countwords(av[i + 1], ' ');
		if (count)
			stacks->size_a += count;
		else
			stacks->size_a++;
		i++;
	}
	stacks->stack_a = malloc(stacks->size_a * sizeof * stacks->stack_a);
	if (stacks->stack_a == NULL)
		free_and_exit_with_message(stacks, "Error\n");
	stacks->stack_b = malloc(stacks->size_a * sizeof * stacks->stack_b);
	if (stacks->stack_b == NULL)
		free_and_exit_with_message(stacks, "Error\n");
}

void	create_index(t_stacks *stacks)
{
	int	i;
	int	j;
	int	k;
	int	*new_a;

	new_a = malloc(stacks->size_a * sizeof * new_a);
	if (new_a == NULL)
		free_and_exit_with_message(stacks, "Error\n");
	i = -1;
	while (++i < stacks->size_a)
	{
		j = -1;
		k = 0;
		while (++j < stacks->size_a)
			if (stacks->stack_a[i] > stacks->stack_a[j])
				k++;
		new_a[i] = k;
	}
	i = stacks->size_a;
	while (i--)
		stacks->stack_a[i] = new_a[i];
	free(new_a);
}

void	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 2)
		free_and_exit_with_message(NULL, "");
	while (++i < ac)
	{
		j = 0;
		if (!av[i][0] || (av[i][0] && av[i][0] == ' '))
			free_and_exit_with_message(NULL, "Error\n");
		while (av[i][j] != '\0')
		{
			if ((!(ft_isdigit(av[i][j])) && (av[i][j] != ' ')
			&& (av[i][j] != '-' && av[i][j] != '+' && av[i][j] != ' '))
			|| (av[i][j] == '-' && av[i][j + 1] == '\0')
			|| (av[i][j] == '+' && av[i][j + 1] == '\0')
			|| (av[i][j] == '-' && av[i][j + 1] == ' ')
			|| (av[i][j] == '+' && av[i][j + 1] == ' '))
				free_and_exit_with_message(NULL, "Error\n");
			j++;
		}
	}
}
