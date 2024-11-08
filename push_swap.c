/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:56:03 by eebert            #+#    #+#             */
/*   Updated: 2024/11/08 13:49:40 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"
#include "libft.h"

t_list *ft_lstlast(t_list *lst) {
    if (!lst) {
        return NULL;
    }

    while (lst->next) {
        lst = lst->next;
    }

    return lst;
}


void print_stack(t_list *stack) {
    t_list *current;

    current = stack;
    while (current) {
        printf("%d\n", *(int *) current->content);
        current = current->next;
    }
}


int main(int argc, char **argv) {
    t_list *stack_a;
    t_list *stack_b;


    if (argc < 2) {
        printf("Error: no arguments\n");
        return 1;
    }

    stack_a = NULL;
    stack_b = NULL;


    parse_args_to_stack(argc, argv, &stack_a);
    // use sort_stack to sort stack_a
    sort_stack(&stack_a, &stack_b);



    ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);
    return 0;
}
