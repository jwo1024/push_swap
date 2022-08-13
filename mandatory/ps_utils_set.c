#include	"push_swap.h"

//int	ps_set_a_stack(t_stack *stack, char *argv[]) // 함수 나누기

int	ps_set_a_stack(t_stack *stack) // void 
{
	stack->len = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->stack = A_STACK;
	return (1);
}

int	ps_set_b_stack(t_stack *stack)
{
	stack->len = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->stack = B_STACK;
	return (0);
}

void ps_set_cmd_stack(t_cmd_stack *stack)
{
	stack->a = (t_cmd_ab_stack *)malloc(sizeof(t_cmd_ab_stack));
	stack->b = (t_cmd_ab_stack *)malloc(sizeof(t_cmd_ab_stack));
	stack->a->top = NULL;
	stack->a->bottom = NULL;
	stack->b->top = NULL;
	stack->b->bottom = NULL;
	stack->a->len = 0;
	stack->b->len = 0;
}
