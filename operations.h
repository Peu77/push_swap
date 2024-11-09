/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:22:20 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 22:14:23 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft.h"
# include <stdbool.h>

void	shift_down(t_list **stack);

void	shift_up(t_list **stack);

void	swap_first_two(t_list **stack);

void	push_first(t_list **stack_a, t_list **stack_b);

void	sa(t_list **stack_a, bool print);

void	sb(t_list **stack_b, bool print);

void	ss(t_list **stack_a, t_list **stack_b, bool print);

void	pa(t_list **stack_a, t_list **stack_b, bool print);

void	pb(t_list **stack_a, t_list **stack_b, bool print);

void	ra(t_list **stack_a, bool print);

void	rb(t_list **stack_b, bool print);

void	rr(t_list **stack_a, t_list **stack_b, bool print);

void	rra(t_list **stack_a, bool print);

void	rrb(t_list **stack_b, bool print);

void	rrr(t_list **stack_a, t_list **stack_b, bool print);

#endif