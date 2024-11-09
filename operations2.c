/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:24:13 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 22:15:41 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "operations.h"

void	ra(t_list **stack_a, bool print)
{
	shift_up(stack_a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_list **stack_b, bool print)
{
	shift_up(stack_b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b, bool print)
{
	shift_up(stack_a);
	shift_up(stack_b);
	if (print)
		ft_printf("rr\n");
}

void	rra(t_list **stack_a, bool print)
{
	shift_down(stack_a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_list **stack_b, bool print)
{
	shift_down(stack_b);
	if (print)
		ft_printf("rrb\n");
}
