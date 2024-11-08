/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:31:33 by eebert            #+#    #+#             */
/*   Updated: 2024/11/06 19:33:19 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void push_first(t_list **stack_a, t_list **stack_b) {
    if (!*stack_a) {
        return;
    }

    t_list *next = (*stack_a)->next;
    (*stack_a)->next = *stack_b;
    *stack_b = *stack_a;
    *stack_a = next;
}

void swap_first_two(t_list **stack) {
    if (!*stack || !(*stack)->next) {
        return;
    }

    t_list *next = (*stack)->next;
    (*stack)->next = next->next;
    next->next = *stack;
    *stack = next;
}

void shift_up(t_list **stack) {
    if (!*stack || !(*stack)->next) {
        return;
    }

    t_list *last = ft_lstlast(*stack);

    last->next = *stack;
    *stack = (*stack)->next;
    last->next->next = NULL;
}

void shift_down(t_list **stack) {
    if (!*stack || !(*stack)->next) {
        return;
    }

    t_list *last = ft_lstlast(*stack);

    t_list *prev = *stack;
    while (prev->next != last) {
        prev = prev->next;
    }

    prev->next = NULL;

    prev->next = NULL;
    last->next = *stack;
    *stack = last;
}


void sa(t_list **stack_a) {
    swap_first_two(stack_a);
    ft_printf("sa\n");
}

void sb(t_list **stack_b) {
    swap_first_two(stack_b);
    ft_printf("sb\n");
}

void ss(t_list **stack_a, t_list **stack_b) {
    swap_first_two(stack_a);
    swap_first_two(stack_b);
    ft_printf("ss\n");
}

void pa(t_list **stack_a, t_list **stack_b) {
    push_first(stack_b, stack_a);
    ft_printf("pa\n");
}

void pb(t_list **stack_a, t_list **stack_b) {
    push_first(stack_a, stack_b);
    ft_printf("pb\n");
}

void ra(t_list **stack_a) {
    shift_up(stack_a);
    ft_printf("ra\n");
}

void rb(t_list **stack_b) {
    shift_up(stack_b);
    ft_printf("rb\n");
}

void rr(t_list **stack_a, t_list **stack_b) {
    shift_up(stack_a);
    shift_up(stack_b);
    ft_printf("rr\n");
}

void rra(t_list **stack_a) {
    shift_down(stack_a);
    ft_printf("rra\n");
}

void rrb(t_list **stack_b) {
    shift_down(stack_b);
    ft_printf("rrb\n");
}

void rrr(t_list **stack_a, t_list **stack_b) {
    shift_down(stack_a);
    shift_down(stack_b);
    ft_printf("rrr\n");
}

