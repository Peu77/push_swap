/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:28:17 by eebert            #+#    #+#             */
/*   Updated: 2024/11/11 11:03:13 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include "visualizer.h"
#include <stdio.h>

#ifdef BONUS_BONUS

static void	helper_print(t_list **current_a, t_list **current_b)
{
	if (*current_a)
	{
		ft_printf("%d\t", ((t_stack_item *)(*current_a)->content)->value);
		*current_a = (*current_a)->next;
	}
	else
		ft_printf("\t");
	if (*current_b)
	{
		ft_printf("%d\n", ((t_stack_item *)(*current_b)->content)->value);
		*current_b = (*current_b)->next;
	}
	else
		ft_printf("\n");
}

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = stack_a;
	current_b = stack_b;
	usleep(DELAY);
	write(STDOUT_FILENO, "\033[2J\033[H", 7);
	while (current_a || current_b)
	{
		helper_print(&current_a, &current_b);
	}
	ft_printf("a\tb\n");
}
#endif

#ifndef BONUS_BONUS

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	(void)stack_a;
	(void)stack_b;
}
#endif
