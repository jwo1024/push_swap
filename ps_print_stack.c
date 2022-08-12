#include	"push_swap.h"

int	print_ab_stack(t_stack *stack1, t_stack *stack2)
{
	printf("\n\n");
	if (stack1->stack == A_STACK)
	{
		printf("--A--------\n");
		print_stack(stack1);
		printf("--B--------\n");
		print_stack(stack2);
	}
	else
	{
		printf("--A--------\n");
		print_stack(stack2);
		printf("--B--------\n");
		print_stack(stack1);
	}
	return (0); //return 없애기? 아니 이 거 자체 삭제..
}

int	print_stack(t_stack *stack)
{
	int	i;
	t_list *list;

	if (stack->len == 0)
	{
		printf("stack is empty\n");
		return (1);
	}
	i = 0;
	list = stack->top;
	while (list)
	{
		printf("stack[%d] %d \n", i, list->data);
		list = list->next;
		i++;
	}
	return (1);
}
