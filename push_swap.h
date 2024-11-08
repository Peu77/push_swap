/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:34:26 by eebert            #+#    #+#             */
/*   Updated: 2024/11/08 22:22:32 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct s_moves {
    int shifts;
    int up;
} t_moves;

typedef struct s_stack_item {
    int value;
    int cost_a;
    int cost_b;
    int target;
} t_stack_item;


void parse_args_to_stack(int argc, char **argv, t_list **stack_a);

void sort_stack(t_list **stack_a, t_list **stack_b);

void sa(t_list **stack_a);

void sb(t_list **stack_b);

void ss(t_list **stack_a, t_list **stack_b);

void pa(t_list **stack_a, t_list **stack_b);

void pb(t_list **stack_a, t_list **stack_b);

void ra(t_list **stack_a);

void rb(t_list **stack_b);

void rr(t_list **stack_a, t_list **stack_b);

void rra(t_list **stack_a);

void rrb(t_list **stack_b);

void rrr(t_list **stack_a, t_list **stack_b);

#endif
