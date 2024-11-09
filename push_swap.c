/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:56:03 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 19:31:54 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static bool	exist_duplicates(t_list *stack)
{
	t_list	*current;
	t_list	*tmp;

	current = stack;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (*(int *)current->content == *(int *)tmp->content)
			{
				return (true);
			}
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (1);
	if (is_invalid_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = NULL;
	stack_b = NULL;
	parse_args_to_stack(argc, argv, &stack_a);
	if (exist_duplicates(stack_a))
	{
		write(2, "Error\n", 6);
		ft_lstclear(&stack_a, free);
		return (1);
	}
	sort_stack(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
