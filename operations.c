/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:31:33 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 19:24:09 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "operations.h"

void	sa(t_list **stack_a)
{
	swap_first_two(stack_a);
	ft_printf("sa\n");
}

void	sb(t_list **stack_b)
{
	swap_first_two(stack_b);
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap_first_two(stack_a);
	swap_first_two(stack_b);
	ft_printf("ss\n");
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push_first(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push_first(stack_a, stack_b);
	ft_printf("pb\n");
}
