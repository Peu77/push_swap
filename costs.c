/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:11:29 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 15:27:52 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>

static int	find_best_target(t_list *stack_a, int value_b)
{
	t_list	*current;
	int		target;
	int		value_a;

	current = stack_a;
	target = INT_MAX;
	while (current)
	{
		value_a = ((t_stack_item *)current->content)->value;
		if (value_a > value_b && value_a < target)
			target = value_a;
		current = current->next;
	}
	if (target == INT_MAX)
	{
		current = stack_a;
		target = ((t_stack_item *)current->content)->value;
		while (current)
		{
			if (((t_stack_item *)current->content)->value < target)
				target = ((t_stack_item *)current->content)->value;
			current = current->next;
		}
	}
	return (target);
}

static int	get_position(t_list *stack, int value)
{
	t_list	*current;
	int		pos;

	current = stack;
	pos = 0;
	while (current)
	{
		if (((t_stack_item *)current->content)->value == value)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

static int	cheapest_rotation(int pos, int len)
{
	if (pos <= len / 2)
		return (pos);
	return (-(len - pos));
}

void	calculate_costs(t_list *stack_a, t_list *stack_b)
{
	t_list		*current;
	const int	len_a = ft_lstsize(stack_a);
	const int	len_b = ft_lstsize(stack_b);
	int			pos_b;
	int			pos_a;

	pos_b = 0;
	current = stack_b;
	while (current)
	{
		pos_a = get_position(stack_a, find_best_target(stack_a,
					((t_stack_item *)current->content)->value));
		((t_stack_item *)current->content)->cost_a = cheapest_rotation(pos_a,
				len_a);
		((t_stack_item *)current->content)->cost_b = cheapest_rotation(pos_b,
				len_b);
		current = current->next;
		pos_b++;
	}
}
