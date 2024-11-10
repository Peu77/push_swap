/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:56:03 by eebert            #+#    #+#             */
/*   Updated: 2024/11/10 17:19:41 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		result;

	result = 0;
	if (argc < 2)
		return (1);
	if (is_invalid_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = NULL;
	stack_b = NULL;
	if (!parse_args_to_stack(argc, argv, &stack_a) || exist_duplicates(stack_a)
		|| !sort_stack(&stack_a, &stack_b))
	{
		write(2, "Error\n", 6);
		result = 1;
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (result);
}
