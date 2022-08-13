#include	"push_swap.h"

void	ps_set_a_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	stack->len = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->stack = A_STACK;
}

void	ps_set_b_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	stack->len = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->stack = B_STACK;
}

void	ps_set_cmd_stack(t_cmd_stack *stack) // NULL 가드 해주어야 하나?왜
{
	stack->a = (t_cmd_ab_stack *)malloc(sizeof(t_cmd_ab_stack));
	if (stack->a == NULL)
		exit (1);
	stack->b = (t_cmd_ab_stack *)malloc(sizeof(t_cmd_ab_stack));
	if (stack->b == NULL)
		exit (1);
	stack->a->top = NULL;
	stack->a->bottom = NULL;
	stack->b->top = NULL;
	stack->b->bottom = NULL;
	stack->a->len = 0;
	stack->b->len = 0;
}
