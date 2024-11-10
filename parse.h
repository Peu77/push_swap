/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:42:59 by eebert            #+#    #+#             */
/*   Updated: 2024/11/10 16:55:41 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include <stdbool.h>

bool	parse_args_to_stack(int argc, char **argv, t_list **stack_a);

bool	is_invalid_args(int argc, char **argv);

bool	exist_duplicates(t_list *stack);

#endif