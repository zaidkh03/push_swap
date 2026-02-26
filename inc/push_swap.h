/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:08:22 by zalkhali          #+#    #+#             */
/*   Updated: 2025/02/10 20:09:33 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_stacks
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
	char	*joined_args;
}			t_stacks;

void		check_args(int argc, char **argv);
void		free_and_exit_with_message(t_stacks *stacks, char *message);
void		initialize_stacks(int ac, char **av, t_stacks *stacks);
void		joined_args(int ac, char **av, t_stacks *stacks);
void		parse_numbers(t_stacks *stacks);
void		validate_args(char **args, t_stacks *stacks);
void		exit_if_sorted_or_has_duplicates(t_stacks *stacks, int i);
int			is_array_sorted(t_stacks *stacks);
void		create_index(t_stacks *stacks);
void		swap(int *stack, int size, char *str);
void		push(t_stacks *stacks, char *str);
void		rotate(int *stack, int size, char *direction, char *list);
void		sort_three_numbers(t_stacks *stacks);
void		sort_four_to_five_numbers(t_stacks *stacks);
void		radix_sort(t_stacks *stacks);
int			find_max(int *stack, int size);
void		sort_by_bit(t_stacks *stacks, int cur_bit);
void		radix_sort_stack_b(t_stacks *stacks, int size_b, int bit_size,
				int cur_bit);
int			is_atoi_valid(char *av);
int			check_strncmp(int k, char *av);

#endif
