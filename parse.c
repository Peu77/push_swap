/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:33:30 by eebert            #+#    #+#             */
/*   Updated: 2024/11/08 15:33:54 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void parse_args_to_stack(int argc, char **argv, t_list **stack_a) {
    int i;
    int j;
    t_stack_item *item;
    char **split;

    i = 1;
    while (i < argc) {
        split = ft_split(argv[i], ' ');
        j = 0;
        while (split[j]) {
            item = malloc(sizeof(t_stack_item));
            item->value = ft_atoi(split[j]);
            item->target_value = 0;
            item->moves_a.shifts = 0;
            item->moves_a.up = 0;
            item->moves_b.shifts = 0;
            item->moves_b.up = 0;

            free(split[j]);
            ft_lstadd_back(stack_a, ft_lstnew(item));
            j++;
        }
        free(split);
        i++;
    }
}

