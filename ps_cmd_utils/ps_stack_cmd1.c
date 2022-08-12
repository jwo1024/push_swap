#include	"push_swap.h"

int	ps_insert_cmd(enum e_command cmd, enum e_stack stack, t_cmd_stack *cmd_stack)
{
	if (stack == A_STACK)
	{
		if (check_cmd(cmd, stack, cmd_stack))
			ps_push_cmd_stack(cmd, cmd_stack->a);
	}
	else if (stack == B_STACK)
	{
		if (check_cmd(cmd, stack, cmd_stack))
			ps_push_cmd_stack(cmd, cmd_stack->b);
	}
	else if (stack == AB_STACK)
	{
		if (check_cmd(cmd, stack, cmd_stack))
		{
			ps_push_cmd_stack(cmd, cmd_stack->a);
			ps_push_cmd_stack(cmd, cmd_stack->b);
		}
	}
	return (0);
}

int	ps_push_cmd_stack(enum e_command cmd, t_cmd_ab_stack *ab)
{
	t_cmd_list	*new;

	new = (t_cmd_list *)malloc(sizeof(t_cmd_list));
	new->cmd = cmd;
	new->next = ab->top;
	ab->top = new;
	new->prev = NULL;
	if (ab->len == 0)
		ab->bottom = new;
	else if (new->next != NULL)
		new->next->prev = new;
	ab->len++;
	return (1);
}

t_cmd_list	*ps_pop_cmd_stack(t_cmd_ab_stack *ab) // free 는 밖에서 해줘야 함
{
	t_cmd_list	*pop;

	pop = ab->top;
	ab->top = ab->top->next;
	ab->len--;
	if (ab->len)
		ab->top->prev = NULL;
	return (pop);
}

t_cmd_list *ps_pop_bottom_cmd_stack(t_cmd_ab_stack *ab)
{
	t_cmd_list	*pop;

	pop = ab->bottom; //pop == NULL??????????
	ab->bottom = ab->bottom->prev;
	if (ab->bottom != NULL)
		ab->bottom->next = NULL;
	ab->len--;
	if (ab->len == 0)
		ab->top = NULL;
	return (pop);
}
