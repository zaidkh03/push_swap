/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:57:36 by zalkhali          #+#    #+#             */
/*   Updated: 2025/02/10 19:56:43 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_and_exit_with_message(t_stacks *stacks, char *message)
{
	if (message)
		write(2, message, ft_strlen(message));
	if (stacks != NULL)
	{
		if (stacks->stack_a != NULL)
			free(stacks->stack_a);
		if (stacks->stack_b != NULL)
			free(stacks->stack_b);
		if (stacks->joined_args != NULL)
			free(stacks->joined_args);
		free(stacks);
	}
	exit(1);
}

int	check_strncmp(int k, char *av)
{
	if (k == 11 && av[0] == '-' && ft_strncmp(av, "-2147483648", 11) <= 0)
		return (1);
	else if (k == 11 && av[0] == '+' && ft_strncmp(av, "+2147483647", 11) <= 0)
		return (1);
	else if (k == 10 && ft_strncmp(av, "2147483647", 10) <= 0)
		return (1);
	return (0);
}

int	is_atoi_valid(char *av)
{
	int	k;
	int	len;

	k = 0;
	len = 0;
	if (av[0] == '-' || av[0] == '+')
		k++;
	while (av[k] == '0' && av[k + 1] == '0')
		k++;
	if (av[k] == '\0')
		return (0);
	while (av[k] != '\0')
	{
		if (!ft_isdigit(av[k++]))
			return (0);
		len++;
	}
	if (len > 11)
		return (0);
	if (len < 10)
		return (1);
	if (check_strncmp(k, av) == 1)
		return (1);
	return (0);
}

void	validate_args(char **av, t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (!is_atoi_valid(av[i]))
		{
			while (av[j])
			{
				free(av[j]);
				j++;
			}
			free(av);
			free_and_exit_with_message(stacks, "Error\n");
		}
		i++;
	}
}

void	joined_args(int ac, char **av, t_stacks *stacks)
{
	char	*joined;
	int		total_len;
	int		i;
	int		pos;

	total_len = 0;
	i = 0;
	while (++i < ac)
		total_len += ft_strlen(av[i]) + 1;
	joined = (char *)malloc(total_len * sizeof(char));
	if (!joined)
		free_and_exit_with_message(stacks, "Error\n");
	pos = 0;
	i = 0;
	while (++i < ac)
	{
		ft_strlcpy(joined + pos, av[i], ft_strlen(av[i]) + 1);
		pos += ft_strlen(av[i]);
		if (i != ac - 1)
			joined[pos++] = ' ';
	}
	joined[pos] = '\0';
	stacks->joined_args = joined;
}
