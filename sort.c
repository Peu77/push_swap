/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:35:44 by eebert            #+#    #+#             */
/*   Updated: 2024/11/08 16:23:11 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

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

void sort_array(int *array, size_t length) {
    for (size_t i = 0; i < length; i++) {
        for (size_t j = i + 1; j < length; j++) {
            if (array[i] > array[j]) {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

void push_values_to_pile_b(t_list **stack_a, t_list **stack_b, int pivot, int *lis, size_t lis_length) {
    t_list *current = *stack_a;
    int value;
    int is_in_lis;

    while (current && ft_lstsize(*stack_a) > (int) lis_length) {
        value = *(int *) current->content;
        is_in_lis = 0;

        // Check if the value is in the LIS
        for (size_t i = 0; i < lis_length; i++) {
            if (value == lis[i]) {
                is_in_lis = 1;
                break;
            }
        }

        if (!is_in_lis) {
            if (value > pivot) {
                pb(stack_a, stack_b);
            } else {
                pb(stack_a, stack_b);
                rrb(stack_b);
            }
        } else {
            ra(stack_a);
        }

        current = *stack_a;
    }
}

int get_index_of_value(int *array, int value, size_t length) {
    for (size_t i = 0; i < length; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

void apply_target_values(t_list *stack_a, int *sorted_array, size_t length) {
    t_list *current = stack_a;
    int index;

    while (current) {
        t_stack_item *item = (t_stack_item *) current->content;
        index = get_index_of_value(sorted_array, item->value, length);
        ((t_stack_item *) current->content)->target_value = sorted_array[(index + 1) % length];
        current = current->next;
    }
}

int get_position_of_value(t_list *stack, int value) {
    t_list *current = stack;
    int position = 0;

    while (current) {
        if (((t_stack_item *) current->content)->value == value) {
            return position;
        }
        position++;
        current = current->next;
    }

    return -1;
}

int calculate_shifts_to_top(t_list *stack, int stack_size, int target_value, int *up) {
    int position = get_position_of_value(stack, target_value);
    int shifts = position;
    if (position > stack_size / 2) {
        *up = 0;
        shifts = stack_size - position;
    } else {
        *up = 1;
    }
    return shifts;
}

void calculate_moves(t_list *stack_a, t_list *stack_b) {
    t_list *current = stack_b;
    int up;
    int shifts;

    while (current) {
        t_stack_item *item = (t_stack_item *) current->content;
        shifts = calculate_shifts_to_top(stack_a, ft_lstsize(stack_a), item->target_value, &up);
        item->moves_a.shifts = shifts;
        item->moves_a.up = up;

        shifts = calculate_shifts_to_top(stack_b, ft_lstsize(stack_b), item->value, &up);
        item->moves_b.shifts = shifts;
        item->moves_b.up = up;

        current = current->next;
    }
}

int calculate_total_moves(t_stack_item *item) {
    if (item->moves_a.up == item->moves_b.up) {
        return item->moves_a.shifts > item->moves_b.shifts ? item->moves_a.shifts : item->moves_b.shifts;
    }

    return item->moves_a.shifts + item->moves_b.shifts;
}

t_stack_item *get_cheapest_item(t_list *stack) {
    t_list *current = stack;
    t_stack_item *cheapest = (t_stack_item *) current->content;
    int cheapest_cost = -1;

    while (current) {
        t_stack_item *item = (t_stack_item *) current->content;
        if (item->moves_a.shifts == -1 || item->moves_b.shifts == -1) {
            current = current->next;
            continue;
        }
        int cost = calculate_total_moves(item);
        if (cost < cheapest_cost || cheapest_cost == -1) {
            cheapest = item;
            cheapest_cost = cost;
        }
        current = current->next;
    }

    return cheapest;
}

void move_item_back(t_list **stack_a, t_list **stack_b, t_stack_item *cheapest) {
    if (cheapest->moves_a.up == cheapest->moves_b.up) {
        while (cheapest->moves_a.shifts > 0 && cheapest->moves_b.shifts > 0) {
            if (cheapest->moves_a.up) {
                rr(stack_a, stack_b);
            } else {
                rrr(stack_a, stack_b);
            }
            cheapest->moves_a.shifts--;
            cheapest->moves_b.shifts--;
        }
    }

    for (int i = 0; i < cheapest->moves_a.shifts; i++) {
        if (cheapest->moves_a.up) {
            ra(stack_a);
        } else {
            rra(stack_a);
        }
    }

    for (int i = 0; i < cheapest->moves_b.shifts; i++) {
        if (cheapest->moves_b.up) {
            rb(stack_b);
        } else {
            rrb(stack_b);
        }
    }
}

void sort_stack(t_list **stack_a, t_list **stack_b) {
    (void) stack_b;
    size_t length = ft_lstsize(*stack_a);
    int *array = list_to_array(*stack_a, length);
    size_t sequence_length;
    int *seq = get_longest_sequence(array, length, &sequence_length);
    sort_array(array, length);

    apply_target_values(*stack_a, array, length);

    int pivot = array[length / 2];
    push_values_to_pile_b(stack_a, stack_b, pivot, seq, sequence_length);


    while (ft_lstsize(*stack_b) > 0) {
        calculate_moves(*stack_a, *stack_b);
        t_stack_item *cheapest = get_cheapest_item(*stack_b);

        move_item_back(stack_a, stack_b, cheapest);
        pa(stack_a, stack_b);
    }

    int smallest_element = array[0];
    int up;
    int moves_to_top = calculate_shifts_to_top(*stack_a, ft_lstsize(*stack_a), smallest_element, &up);
    for (int i = 0; i < moves_to_top; i++) {
        if (up) {
            ra(stack_a);
        } else {
            rra(stack_a);
        }
    }

    free(seq);
    free(array);
}