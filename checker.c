/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:57:00 by eebert            #+#    #+#             */
/*   Updated: 2024/11/10 19:10:12 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "operations.h"
#include "parse.h"
#include <stdlib.h>
#include <unistd.h>

static int	get_next_operation(char *operation)
{
	char	buffer[1];
	int		i;

	i = 0;
	while (read(STDIN_FILENO, buffer, 1) > 0 && i < 4)
	{
		if (*buffer == '\n')
		{
            if(i <= 1)
                return (0);
			break ;
		}
		*operation = *buffer;
		i++;
		operation++;
	}
	return (i < 4);
}

static bool	is_sorted(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current->next)
	{
		if (*(int *)current->content > *(int *)current->next->content)
		{
			return (false);
		}
		current = current->next;
	}
	return (true);
}

static bool	exec_operation(char operation[4], t_list **stack_a,
		t_list **stack_b)
{
	if (ft_strncmp(operation, "sa", 3) == 0)
		return (sa(stack_a, false), true);
	if (ft_strncmp(operation, "sb", 3) == 0)
		return (sb(stack_b, false), true);
	if (ft_strncmp(operation, "ss", 3) == 0)
		return (ss(stack_a, stack_b, false), true);
	if (ft_strncmp(operation, "pa", 3) == 0)
		return (pa(stack_a, stack_b, false), true);
	if (ft_strncmp(operation, "pb", 3) == 0)
		return (pb(stack_a, stack_b, false), true);
	if (ft_strncmp(operation, "ra", 3) == 0)
		return (ra(stack_a, false), true);
	if (ft_strncmp(operation, "rb", 3) == 0)
		return (rb(stack_b, false), true);
	if (ft_strncmp(operation, "rr", 3) == 0)
		return (rr(stack_a, stack_b, false), true);
	if (ft_strncmp(operation, "rra", 4) == 0)
		return (rra(stack_a, false), true);
	if (ft_strncmp(operation, "rrb", 4) == 0)
		return (rrb(stack_b, false), true);
	if (ft_strncmp(operation, "rrr", 4) == 0)
		return (rrr(stack_a, stack_b, false), true);
	return (false);
}

static void	parse_exec_operations(t_list **stack_a, t_list **stack_b)
{
	char	operation[4];
	int		result;

	while (1)
	{
		ft_bzero(operation, 4);
		result = get_next_operation(operation);
		if (result == 0)
		{
			write(2, "Error\n", 6);
			ft_lstclear(stack_a, free);
			exit(1);
		}
		if (operation[0] == 0)
			break ;
		if (!exec_operation(operation, stack_a, stack_b))
		{
			write(2, "Error\n", 6);
			ft_lstclear(stack_a, free);
			exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc <= 1)
		return (0);
	if (is_invalid_args(argc, argv))
		return (write(2, "Error\n", 6), 1);
	stack_a = NULL;
	stack_b = NULL;
	parse_args_to_stack(argc, argv, &stack_a);
	if (exist_duplicates(stack_a))
	{
		write(2, "Error\n", 6);
		return (ft_lstclear(&stack_a, free), 1);
	}
	parse_exec_operations(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a, free);
	return (0);
}
