/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:33:30 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 15:15:27 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdbool.h>
#include "ft_printf.h"

static int ft_abs(int value) {
    return value < 0 ? -value : value;
}

static bool did_overflow(int value, char *str) {
    if (*str == '-' || *str == '+') {
        if (*str == '-' && value > 0)
            return true;
        str++;
    } else if (value < 0) {
        return true;
    }

    size_t len = ft_strlen(str);
    if (!len)
        return true;

    while (len--) {
        if (str[len] != ft_abs(value % 10) + '0') {
            return true;
        }
        value /= 10;
    }
    return false;
}

bool is_invalid_args(int argc, char **argv) {
    int i;
    int j;

    i = 1;
    while (i < argc) {
        j = 0;
        while (argv[i][j]) {
            if (argv[i][j] == '-' || argv[i][j] == '+') {
                j++;
                continue;
            }

            if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ') {
                return true;
            }
            j++;
        }

        if (j > 11 || did_overflow(ft_atoi(argv[i]), argv[i])) {
            return true;
        }
        i++;
    }
    return false;
}

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
            item->cost_a = 0;
            item->cost_b = 0;

            free(split[j]);
            ft_lstadd_back(stack_a, ft_lstnew(item));
            j++;
        }
        free(split);
        i++;
    }
}

