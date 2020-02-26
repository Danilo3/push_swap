//
// Created by Aletha Yellin on 26/02/2020.
//
#include "push_swap.h"

t_stack	*make_stack(int arr[], int size)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = init_stack();
	while (i < size)
		add_to_stack(stack, arr[i++]);
	return (stack);
}


int     check_apps(t_app *app1, t_app *app2)
{
    return (check_stacks(app1->a, app2->a) && check_stacks(app1->b, app2->b);
}

int     check_stacks(t_stack *stack1, t_stack* stack2)
{
   
   t_stack_elem *a;
   t_stack_elem *b;

   a = stack1->head;
   b = stack2->head;
   while (a || b)
   {
       
   }
}


int		main()
{
	t_stack		*a_stack;
	t_stack		*b_stack;
	int			test_arr[] = {1, 2, 3, 4, 5};

	a_stack = make_stack(test_arr, 5);
	b_stack = init_stack();
	ft_printf("min = %d\n", find_min(a_stack));
	print_values(a_stack, b_stack, NULL);
	free_stack(a_stack);
}
