
#include	"push_swap.h"


void	delete_cmd_stack(t_cmd_stack *stack)
{
	if (stack->a->len)
	{
		;
	}
	if (stack->b->len)
	{
		;
	}
	free(stack->a);
	free(stack->b);
}