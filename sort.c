/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:35:44 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 19:28:15 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include "operations.h"

static void	push_to_b(t_list **stack_a, t_list **stack_b, t_array lis,
		t_array array)
{
	t_list	*current;
	int		value;

	current = *stack_a;
	while (ft_lstsize(*stack_a) > (int)lis.length)
	{
		value = ((t_stack_item *)current->content)->value;
		if (!is_in_array(value, lis.array, lis.length))
		{
			pb(stack_a, stack_b);
			if (value > array.array[array.length / 2])
				rb(stack_b);
		}
		else
		{
			ra(stack_a);
		}
		current = *stack_a;
	}
}

static int	get_min_pos(t_list *stack_a)
{
	int		min_pos;
	int		min_val;
	t_list	*current;
	int		pos;
	int		val;

	min_pos = 0;
	min_val = ((t_stack_item *)stack_a->content)->value;
	current = stack_a;
	pos = 0;
	while (current)
	{
		val = ((t_stack_item *)current->content)->value;
		if (val < min_val)
		{
			min_val = val;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

static void	final_rotation(t_list **stack_a)
{
	const int	size = ft_lstsize(*stack_a);
	int			min_pos;

	min_pos = get_min_pos(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos--)
			ra(stack_a);
	}
	else
	{
		while (min_pos++ < size)
			rra(stack_a);
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	size_t			length;
	int				*array;
	size_t			lis_length;
	int				*lis;
	t_stack_item	*cheapest;

	length = ft_lstsize(*stack_a);
	array = list_to_array(*stack_a, length);
	lis = get_longest_sequence(array, length, &lis_length);
	push_to_b(stack_a, stack_b, (t_array){.array = lis, .length = lis_length},
		(t_array){.array = array, .length = length});
	while (*stack_b)
	{
		calculate_costs(*stack_a, *stack_b);
		cheapest = find_cheapest_move(*stack_b);
		execute_move(stack_a, stack_b, cheapest);
		pa(stack_a, stack_b);
	}
	final_rotation(stack_a);
	free(lis);
	free(array);
}
