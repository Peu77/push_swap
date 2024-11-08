/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:35:44 by eebert            #+#    #+#             */
/*   Updated: 2024/11/08 22:24:44 by eebert           ###   ########.fr       */
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

int *get_longest_sequence(int *array, size_t length, size_t *seq_length) {
    int *dp = (int *) malloc(sizeof(int) * length);
    int *prev = (int *) malloc(sizeof(int) * length);
    int *result;
    int max_length = 0;
    int max_index = 0;

    for (size_t i = 0; i < length; i++) {
        dp[i] = 1;
        prev[i] = -1;
        for (size_t j = 0; j < i; j++) {
            if (array[j] < array[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > max_length) {
            max_length = dp[i];
            max_index = i;
        }
    }

    *seq_length = max_length;
    result = (int *) malloc(sizeof(int) * max_length);
    for (int i = max_length - 1; i >= 0; i--) {
        result[i] = array[max_index];
        max_index = prev[max_index];
    }

    free(dp);
    free(prev);

    return result;
}

static int find_best_target(t_list *stack_a, int value_b) {
    t_list *current = stack_a;
    int target = INT_MAX;

    while (current) {
        int value_a = ((t_stack_item *)current->content)->value;
        if (value_a > value_b && value_a < target)
            target = value_a;
        current = current->next;
    }

    if (target == INT_MAX) {
        current = stack_a;
        target = ((t_stack_item *)current->content)->value;
        while (current) {
            int value_a = ((t_stack_item *)current->content)->value;
            if (value_a < target)
                target = value_a;
            current = current->next;
        }
    }

    return target;
}

static void calculate_costs(t_list *stack_a, t_list *stack_b) {
    t_list *current = stack_b;
    int len_a = ft_lstsize(stack_a);
    int len_b = ft_lstsize(stack_b);
    int pos_b = 0;

    while (current) {
        t_stack_item *item = (t_stack_item *)current->content;
        int target = find_best_target(stack_a, item->value);
        int pos_a = 0;
        t_list *temp = stack_a;

        while (temp && ((t_stack_item *)temp->content)->value != target) {
            pos_a++;
            temp = temp->next;
        }

        item->cost_a = pos_a <= len_a / 2 ? pos_a : -(len_a - pos_a);
        item->cost_b = pos_b <= len_b / 2 ? pos_b : -(len_b - pos_b);
        item->target = target;

        current = current->next;
        pos_b++;
    }
}

static t_stack_item *find_cheapest_move(t_list *stack_b) {
    t_list *current = stack_b;
    t_stack_item *cheapest = NULL;
    int min_cost = INT_MAX;

    while (current) {
        t_stack_item *item = (t_stack_item *)current->content;
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

    while (item->cost_a > 0) { ra(stack_a); item->cost_a--; }
    while (item->cost_a < 0) { rra(stack_a); item->cost_a++; }
    while (item->cost_b > 0) { rb(stack_b); item->cost_b--; }
    while (item->cost_b < 0) { rrb(stack_b); item->cost_b++; }
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
    while (ft_lstsize(*stack_a) > (int)lis_length) {
        int value = ((t_stack_item *)current->content)->value;
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
    int min_val = ((t_stack_item *)(*stack_a)->content)->value;
    current = *stack_a;
    int pos = 0;

    while (current) {
        int val = ((t_stack_item *)current->content)->value;
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