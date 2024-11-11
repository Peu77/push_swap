/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:30:10 by eebert            #+#    #+#             */
/*   Updated: 2024/11/11 11:01:36 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "libft.h"
# ifndef DELAY
#  define DELAY 500000
# endif

void	print_stacks(t_list *stack_a, t_list *stack_b);

#endif