/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:12:48 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 22:17:55 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include "operations.h"

static int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

t_stack_item	*find_cheapest_move(t_list *stack_b)
{
	t_list			*current;
	t_stack_item	*cheapest;
	int				min_cost;
	int				cost;
	t_stack_item	*item;

	current = stack_b;
	cheapest = NULL;
	min_cost = INT_MAX;
	while (current)
	{
		item = (t_stack_item *)current->content;
		cost = ft_abs(item->cost_a) + ft_abs(item->cost_b);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = item;
		}
		current = current->next;
	}
	return (cheapest);
}

static void	execute_double_moves(t_list **stack_a, t_list **stack_b,
		t_stack_item *item)
{
	while (item->cost_a > 0 && item->cost_b > 0)
	{
		rr(stack_a, stack_b, true);
		item->cost_a--;
		item->cost_b--;
	}
	while (item->cost_a < 0 && item->cost_b < 0)
	{
		rrr(stack_a, stack_b, true);
		item->cost_a++;
		item->cost_b++;
	}
}

void	execute_move(t_list **stack_a, t_list **stack_b, t_stack_item *item)
{
	execute_double_moves(stack_a, stack_b, item);
	while (item->cost_a > 0)
	{
		ra(stack_a, true);
		item->cost_a--;
	}
	while (item->cost_a < 0)
	{
		rra(stack_a, true);
		item->cost_a++;
	}
	while (item->cost_b > 0)
	{
		rb(stack_b, true);
		item->cost_b--;
	}
	while (item->cost_b < 0)
	{
		rrb(stack_b, true);
		item->cost_b++;
	}
}
