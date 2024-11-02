#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

void  parse_args_to_stack(int argc, char **argv, t_list **stack_a)
{
    int i;
    int j;
    int* num;
    char **split;

    i = 1;
    while (i < argc)
    {
        split = ft_split(argv[i], ' ');
        j = 0;
        while (split[j])
        {
            num = (int*)malloc(sizeof(int));
            *num = ft_atoi(split[j]);
            free(split[j]);
            ft_lstadd_back(stack_a, ft_lstnew(num));
            j++;
        }
        free(split);
        i++;
    }
}

void swap_first(t_list** stack_a, t_list** stack_b)
{
    // push first element of stack_a to stack_b

    t_list* new_node = ft_lstnew((*stack_a)->content);
    ft_lstadd_front(stack_b, new_node);
    ft_lst
}

void print_stack(void* content)
{
    printf("%d\n", *(int*)content);
}

int main(int argc, char** argv)
{
    t_list *stack_a;
    t_list *stack_b;

    stack_a = NULL;
    stack_b = NULL;

    parse_args_to_stack(argc, argv, &stack_a);
    swap_first( &stack_a, &stack_b);


    printf("stack a:\n");
    ft_lstiter(stack_a, print_stack);


    printf("stack b:\n");
    ft_lstiter(stack_b, print_stack);

    printf("Hello, World!\n");
    return 0;
}
