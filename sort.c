/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:35:44 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 15:12:24 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

int *list_to_array(t_list *stack, size_t length) {
    int *array;
    int i;
    t_list *tmp;

    array = (int *) malloc(sizeof(int) * length);
    i = 0;
    tmp = stack;
    while (tmp) {
        array[i] = *(int *) tmp->content;
        tmp = tmp->next;
        i++;
    }
    return array;
}

static t_stack_item *find_cheapest_move(t_list *stack_b) {
    t_list *current = stack_b;
    t_stack_item *cheapest = NULL;
    int min_cost = INT_MAX;

    while (current) {
        t_stack_item *item = (t_stack_item *) current->content;
        int cost = abs(item->cost_a) + abs(item->cost_b);

        if (cost < min_cost) {
            min_cost = cost;
            cheapest = item;
        }
        current = current->next;
    }

    return cheapest;
}

static void execute_move(t_list **stack_a, t_list **stack_b, t_stack_item *item) {
    while (item->cost_a > 0 && item->cost_b > 0) {
        rr(stack_a, stack_b);
        item->cost_a--;
        item->cost_b--;
    }
    while (item->cost_a < 0 && item->cost_b < 0) {
        rrr(stack_a, stack_b);
        item->cost_a++;
        item->cost_b++;
    }

    while (item->cost_a > 0) {
        ra(stack_a);
        item->cost_a--;
    }
    while (item->cost_a < 0) {
        rra(stack_a);
        item->cost_a++;
    }
    while (item->cost_b > 0) {
        rb(stack_b);
        item->cost_b--;
    }
    while (item->cost_b < 0) {
        rrb(stack_b);
        item->cost_b++;
    }
}

static int is_in_array(int value, int *array, size_t length) {
    for (size_t i = 0; i < length; i++) {
        if (array[i] == value)
            return 1;
    }
    return 0;
}

void sort_stack(t_list **stack_a, t_list **stack_b) {
    size_t length = ft_lstsize(*stack_a);
    int *array = list_to_array(*stack_a, length);
    size_t lis_length;
    int *lis = get_longest_sequence(array, length, &lis_length);

    t_list *current = *stack_a;
    while (ft_lstsize(*stack_a) > (int) lis_length) {
        int value = ((t_stack_item *) current->content)->value;
        if (!is_in_array(value, lis, lis_length)) {
            pb(stack_a, stack_b);
            if (value > array[length / 2])
                rb(stack_b);
        } else {
            ra(stack_a);
        }
        current = *stack_a;
    }

    while (*stack_b) {
        calculate_costs(*stack_a, *stack_b);
        t_stack_item *cheapest = find_cheapest_move(*stack_b);
        execute_move(stack_a, stack_b, cheapest);
        pa(stack_a, stack_b);
    }

    int min_pos = 0;
    int min_val = ((t_stack_item *) (*stack_a)->content)->value;
    current = *stack_a;
    int pos = 0;

    while (current) {
        int val = ((t_stack_item *) current->content)->value;
        if (val < min_val) {
            min_val = val;
            min_pos = pos;
        }
        pos++;
        current = current->next;
    }

    int size = ft_lstsize(*stack_a);
    if (min_pos <= size / 2) {
        while (min_pos--)
            ra(stack_a);
    } else {
        while (min_pos++ < size)
            rra(stack_a);
    }

    free(lis);
    free(array);
}