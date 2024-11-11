/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:34:26 by eebert            #+#    #+#             */
/*   Updated: 2024/11/11 09:22:39 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>

typedef struct s_stack_item
{
	int			value;
	int			cost_a;
	int			cost_b;
}				t_stack_item;

typedef struct t_array
{
	int			*array;
	size_t		length;
}				t_array;

int				get_min_pos(t_list *stack_a);

void			final_rotation(t_list **stack_a);

void			sort_five(t_list **stack_a, t_list **stack_b);

void			sort_three(t_list **stack_a);

bool			optimized_sort(t_list **stack_a, t_list **stack_b);

int				is_in_array(int value, int *array, size_t length);

int				*list_to_array(t_list *stack, size_t length);

t_stack_item	*find_cheapest_move(t_list *stack_b);

void			execute_move(t_list **stack_a, t_list **stack_b,
					t_stack_item *item);

int				*get_longest_sequence(int *array, size_t length,
					size_t *seq_length);

void			calculate_costs(t_list *stack_a, t_list *stack_b);

bool			sort_stack(t_list **stack_a, t_list **stack_b);

#endif
