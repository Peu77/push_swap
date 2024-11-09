/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:31:33 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 22:12:31 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "operations.h"
#include <stdbool.h>

void	sa(t_list **stack_a, bool print)
{
	swap_first_two(stack_a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_list **stack_b, bool print)
{
	swap_first_two(stack_b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b, bool print)
{
	swap_first_two(stack_a);
	swap_first_two(stack_b);
	if (print)
		ft_printf("ss\n");
}

void	pa(t_list **stack_a, t_list **stack_b, bool print)
{
	push_first(stack_b, stack_a);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b, bool print)
{
	push_first(stack_a, stack_b);
	if (print)
		ft_printf("pb\n");
}
