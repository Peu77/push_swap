/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:57:00 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 22:57:43 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "parse.h"
#include "operations.h"
#include "ft_printf.h"

int get_next_operation(char *operation) {
    char buffer[1];
    int i = 0;
    while (read(STDIN_FILENO, buffer, 1) > 0) {
        if (*buffer == '\n') {
            break;
        }
        *operation = *buffer;
        i++;
        operation++;
    }

    return i < 4;
}

void output_stack(t_list *stack) {
    t_list *current = stack;
    while (current) {
        ft_printf("%d\n", *(int *) current->content);
        current = current->next;
    }
}

bool is_sorted(t_list *stack) {
    t_list *current = stack;
    while (current->next) {
        if (*(int *) current->content > *(int *) current->next->content) {
            return false;
        }
        current = current->next;
    }
    return true;
}

int main(int argc, char **argv) {
    t_list *stack_a;
    t_list *stack_b;

    if (argc <= 2) {
        return 0;
    }
    if (is_invalid_args(argc, argv)) {
        write(2, "Error\n", 6);
        return (1);
    }
    stack_a = NULL;
    stack_b = NULL;
    parse_args_to_stack(argc, argv, &stack_a);
    if (exist_duplicates(stack_a)) {
        write(2, "Error\n", 6);
        ft_lstclear(&stack_a, free);
        return (1);
    }
    char operation[4];

    while (1) {
        ft_bzero(operation, 4);
        int result = get_next_operation(operation);
        if (result == 0) {
            write(2, "Error\n", 6);
            exit(1);
        }
        if (operation[0] == 0) {
            break;
        }

        if (ft_strncmp(operation, "sa", 2) == 0) {
            sa(&stack_a, false);
        } else if (ft_strncmp(operation, "sb", 3) == 0) {
            sb(&stack_b, false);
        } else if (ft_strncmp(operation, "ss", 3) == 0) {
            ss(&stack_a, &stack_b, false);
        } else if (ft_strncmp(operation, "pa", 3) == 0) {
            pa(&stack_a, &stack_b, false);
        } else if (ft_strncmp(operation, "pb", 3) == 0) {
            pb(&stack_a, &stack_b, false);
        } else if (ft_strncmp(operation, "ra", 3) == 0) {
            ra(&stack_a, false);
        } else if (ft_strncmp(operation, "rb", 3) == 0) {
            rb(&stack_b, false);
        } else if (ft_strncmp(operation, "rr", 3) == 0) {
            rr(&stack_a, &stack_b, false);
        } else if (ft_strncmp(operation, "rra", 4) == 0) {
            rra(&stack_a, false);
        } else if (ft_strncmp(operation, "rrb", 4) == 0) {
            rrb(&stack_b, false);
        } else if (ft_strncmp(operation, "rrr", 4) == 0) {
            rrr(&stack_a, &stack_b, false);
        } else {
            write(2, "Error\n", 6);
            ft_lstclear(&stack_a, free);
            exit(1);
        }
    }

    if (is_sorted(stack_a) && !stack_b) {
        write(1, "OK\n", 3);
    } else {
        write(1, "KO\n", 3);
    }

    ft_lstclear(&stack_a, free);
    return 0;
}