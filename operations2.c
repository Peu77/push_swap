/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:24:13 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 19:27:26 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "operations.h"

void	ra(t_list **stack_a)
{
	shift_up(stack_a);
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	shift_up(stack_b);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	shift_up(stack_a);
	shift_up(stack_b);
	ft_printf("rr\n");
}

void	rra(t_list **stack_a)
{
	shift_down(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	shift_down(stack_b);
	ft_printf("rrb\n");
}
