/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:33:30 by eebert            #+#    #+#             */
/*   Updated: 2024/11/10 16:59:15 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdbool.h>
#include <stdlib.h>

static int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

static bool	did_overflow(int value, char *str)
{
	size_t	len;

	if (*str == '-' || *str == '+')
	{
		if (*str == '-' && value > 0)
			return (true);
		str++;
	}
	else if (value < 0)
	{
		return (true);
	}
	len = ft_strlen(str);
	if (!len)
		return (true);
	while (len--)
	{
		if (str[len] != ft_abs(value % 10) + '0')
		{
			return (true);
		}
		value /= 10;
	}
	return (false);
}

bool	is_invalid_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				j++;
				continue ;
			}
			if (!ft_isdigit(argv[i][j]))
				return (true);
			j++;
		}
		if (j > 11 || did_overflow(ft_atoi(argv[i]), argv[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	exist_duplicates(t_list *stack)
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

bool	parse_args_to_stack(int argc, char **argv, t_list **stack_a)
{
	int				i;
	t_stack_item	*item;

	i = 1;
	while (i < argc)
	{
		item = malloc(sizeof(t_stack_item));
		if (!item)
			return (false);
		item->value = ft_atoi(argv[i]);
		item->cost_a = 0;
		item->cost_b = 0;
		ft_lstadd_back(stack_a, ft_lstnew(item));
		i++;
	}
	return (true);
}
