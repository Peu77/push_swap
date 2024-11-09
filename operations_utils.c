/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:20:48 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 19:21:47 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_first(t_list **stack_a, t_list **stack_b)
{
	t_list	*next;

	if (!*stack_a)
	{
		return ;
	}
	next = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = next;
}

void	swap_first_two(t_list **stack)
{
	t_list	*next;

	if (!*stack || !(*stack)->next)
	{
		return ;
	}
	next = (*stack)->next;
	(*stack)->next = next->next;
	next->next = *stack;
	*stack = next;
}

void	shift_up(t_list **stack)
{
	t_list	*last;

	if (!*stack || !(*stack)->next)
	{
		return ;
	}
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	shift_down(t_list **stack)
{
	t_list	*last;
	t_list	*prev;

	if (!*stack || !(*stack)->next)
	{
		return ;
	}
	last = ft_lstlast(*stack);
	prev = *stack;
	while (prev->next != last)
	{
		prev = prev->next;
	}
	prev->next = NULL;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}
