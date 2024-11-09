/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:25:40 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 19:26:42 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "operations.h"

void	rrr(t_list **stack_a, t_list **stack_b)
{
	shift_down(stack_a);
	shift_down(stack_b);
	ft_printf("rrr\n");
}
