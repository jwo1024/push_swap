
#include	"push_swap.h"

int	ps_cmd_sab(t_stack *stack, t_cmd_stack *cmd_stack)
{
	t_list	*list1;
	t_list	*list2;

	if (stack->len < 2)
		return (0);
	list1 = stack->top;
	list2 = stack->top->next;
	list1->next = list2->next;
	list2->next = list1;
	stack->top = list2;
	if (stack->len == 2)
		stack->bottom = list1;

	if (stack->stack == A_STACK)
		ps_insert_cmd(CMD_SA, stack->stack, cmd_stack);
	else
		ps_insert_cmd(CMD_SB, stack->stack, cmd_stack);

	return (1);
}

int ps_cmd_pab(t_stack *from, t_stack *to, t_cmd_stack *cmd_stack)
{
	t_list	*list;

	if (from->len == 0)
		return (0);
	list = from->top;
	from->top = from->top->next;
	from->len--;
	list->next = to->top;
	to->top = list;
	to->len++;
	if (to->len == 1)
		to->bottom = list;
	if (to->stack == A_STACK)
		ps_insert_cmd(CMD_PA, AB_STACK, cmd_stack);
	else
		ps_insert_cmd(CMD_PB, AB_STACK, cmd_stack);
	return (1);
}

int	ps_cmd_rrab(t_stack *stack, t_cmd_stack *cmd_stack)
{
	t_list	*list1;
	t_list	*list2;
	int		i;

	if (stack->len < 2)
		return (0);
	list1 = stack->bottom;
	list1->next = stack->top;
	stack->top = list1;
	i = stack->len;
	list2 = stack->top;
	while (i-- != 1)
		list2 = list2->next;
	list2->next = NULL;
	stack->bottom = list2;
	if (stack->stack == A_STACK)
		ps_insert_cmd(CMD_RRA, stack->stack, cmd_stack);
	else
		ps_insert_cmd(CMD_RRB, stack->stack, cmd_stack);
	return (1);
}

int	ps_cmd_rab(t_stack *stack, t_cmd_stack *cmd_stack)
{
	if (stack->len < 2)
		return (0);
	stack->bottom->next = stack->top;
	stack->bottom = stack->top;
	stack->top = stack->top->next;
	stack->bottom->next = NULL;
	if (stack->stack == A_STACK)
		ps_insert_cmd(CMD_RA, stack->stack, cmd_stack);
	else
		ps_insert_cmd(CMD_RB, stack->stack, cmd_stack);
	return (1);
}
