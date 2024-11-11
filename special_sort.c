/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 08:20:25 by eebert            #+#    #+#             */
/*   Updated: 2024/11/11 09:22:33 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "operations.h"
#include "push_swap.h"
#include <stdbool.h>

void	sort_three(t_list **stack_a)
{
	const int	a = ((t_stack_item *)(*stack_a)->content)->value;
	const int	b = ((t_stack_item *)(*stack_a)->next->content)->value;
	const int	c = ((t_stack_item *)(*stack_a)->next->next->content)->value;

	if (a > b && b < c && a < c)
		sa(stack_a, true);
	else if (a > b && b > c)
	{
		sa(stack_a, true);
		rra(stack_a, true);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a, true);
	else if (a < b && b > c && a > c)
	{
		sa(stack_a, true);
		ra(stack_a, true);
		sa(stack_a, true);
	}
	else if (a < b && b > c && a < c)
	{
		rra(stack_a, true);
		sa(stack_a, true);
	}
}

static int	find_min_value(t_list *stack)
{
	int		min;
	t_list	*temp;

	min = ((t_stack_item *)stack->content)->value;
	temp = stack;
	while (temp)
	{
		if (((t_stack_item *)temp->content)->value < min)
			min = ((t_stack_item *)temp->content)->value;
		temp = temp->next;
	}
	return (min);
}

static int	get_position(t_list *stack, int value)
{
	int		pos;
	t_list	*temp;

	pos = 0;
	temp = stack;
	while (temp && ((t_stack_item *)temp->content)->value != value)
	{
		pos++;
		temp = temp->next;
	}
	return (pos);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	i;

	i = 0;
	while (i++ < 2)
	{
		min = find_min_value(*stack_a);
		while (((t_stack_item *)(*stack_a)->content)->value != min)
		{
			if (get_position(*stack_a, min) <= ft_lstsize(*stack_a) / 2)
				ra(stack_a, true);
			else
				rra(stack_a, true);
		}
		pb(stack_a, stack_b, true);
	}
	sort_three(stack_a);
	if (((t_stack_item *)(*stack_b)->content)->value <
	((t_stack_item *)(*stack_b)->next->content)->value)
		sb(stack_b, true);
	pa(stack_a, stack_b, true);
	pa(stack_a, stack_b, true);
}
