/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:16:45 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 19:17:50 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	*list_to_array(t_list *stack, size_t length)
{
	int		*array;
	int		i;
	t_list	*tmp;

	array = (int *)malloc(sizeof(int) * length);
	i = 0;
	tmp = stack;
	while (tmp)
	{
		array[i] = *(int *)tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (array);
}

int	is_in_array(int value, int *array, size_t length)
{
	while (length--)
	{
		if (array[length] == value)
			return (1);
	}
	return (0);
}
