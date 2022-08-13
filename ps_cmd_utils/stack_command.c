#include	"push_swap.h"

int	combine_cmd(t_cmd_stack *cmd_stack)
{
	t_cmd_list *a_list;
	t_cmd_list *b_list;
	enum e_command	cmd;

	a_list = cmd_stack->a->top;
	b_list = cmd_stack->b->top;
	cmd = 0;
	while (a_list && b_list)
	{
		cmd = ps_check_combine_cmd(a_list->cmd, b_list->cmd);
		if (cmd != 0 || a_list->cmd == b_list->cmd)
		{
			if (cmd != 0)
			{
				a_list->cmd = cmd;
				b_list->cmd = cmd;
			}
			a_list = a_list->next;
			b_list = b_list->next;
		}
		else if (a_list->cmd != CMD_PA && a_list->cmd != CMD_PB)
				a_list = a_list->next;
		else if (b_list->cmd != CMD_PA && b_list->cmd != CMD_PB)
				b_list = b_list->next;
	}
	return (1);
}

int	ps_check_combine_cmd(enum e_command a_cmd, enum e_command b_cmd)
{
	int cmd;

	if (a_cmd == CMD_SA && b_cmd == CMD_SB) 
		cmd = CMD_SS;
	else if (a_cmd == CMD_RA && b_cmd == CMD_RB) 
		cmd = CMD_RR;
	else if (a_cmd == CMD_RRA && b_cmd == CMD_RRB) 
		cmd = CMD_RRR;
	else
		return (0);
	return (cmd);
}




int	check_cmd(enum e_command cmd, enum e_stack stack, t_cmd_stack *cmd_stack) // push해도 되나요?를 묻는 함수
{
	t_cmd_list *cmd_list;
	t_cmd_list *pop;

	if ((cmd_stack->a->len == 0 && stack == A_STACK) \
		|| (cmd_stack->b->len == 0 && stack == B_STACK) \
		|| ((cmd_stack->a->len == 0 || cmd_stack->b->len == 0) && stack == AB_STACK))
		return (1);
	if (stack == A_STACK)
	{
		cmd_list = cmd_stack->a->top;
		if ((cmd == CMD_SA && cmd_list->cmd == CMD_SA) \
			|| (cmd == CMD_RA && cmd_list->cmd == CMD_RRA) \
			|| (cmd == CMD_RRA && cmd_list->cmd == CMD_RA)) // pa+pb = 0  (((ra + rra = 0))) sa + sa
		{
			pop = ps_pop_cmd_stack(cmd_stack->a); // top 삭제 
			free(pop);
			return (0);
		} // 왜 while 로 돌지 ? 어차피 return 하는데 ?
	}
	else if (stack == B_STACK)
	{
		cmd_list = cmd_stack->b->top;
		if ((cmd == CMD_SB && cmd_list->cmd == CMD_SB) \
			|| (cmd == CMD_RB && cmd_list->cmd == CMD_RRB) \
			|| (cmd == CMD_RRB && cmd_list->cmd == CMD_RB)) // pa+pb = 0  (((rb + rrb =0 )) sb + sb
		{
			pop = ps_pop_cmd_stack(cmd_stack->b); // top 삭제 
			free(pop);
			return (0);
		}
	}
	else if (stack == AB_STACK)
	{
		if ((cmd == CMD_PA && cmd_stack->a->top->cmd == CMD_PB && cmd_stack->b->top->cmd == CMD_PB) \
			|| (cmd == CMD_PB && cmd_stack->a->top->cmd == CMD_PA &&  cmd_stack->b->top->cmd == CMD_PA)) // pa+pb == 0 // a ㅏㅁ만 검사하면 안되지..;;
		{
			pop = ps_pop_cmd_stack(cmd_stack->a); // top 삭제 
			free(pop);
			pop = ps_pop_cmd_stack(cmd_stack->b); // top 삭제 
			free(pop);
			return (0);
		}
	}
	return (1);
}



int	check_print_cmd(t_cmd_stack *cmd_stack)
{
	t_cmd_list	*a_pop;
	t_cmd_list	*b_pop;
	

	combine_cmd(cmd_stack);
	while (cmd_stack->a->len && cmd_stack->b->len)
	{
		if (cmd_stack->a->bottom->cmd == cmd_stack->b->bottom->cmd) // 두개가 같을때 하나만 출력
		{
			a_pop = ps_pop_bottom_cmd_stack(cmd_stack->a); // ps_pop_both_print()
			b_pop = ps_pop_bottom_cmd_stack(cmd_stack->b);
			ps_print_cmd(a_pop->cmd);
			free(a_pop);
			free(b_pop);
		}
		else if (cmd_stack->a->len && cmd_stack->a->bottom->cmd != CMD_PA \
				&& cmd_stack->a->bottom->cmd != CMD_PB && cmd_stack->a->bottom->cmd != CMD_RR \
				&& cmd_stack->a->bottom->cmd != CMD_RRR && cmd_stack->a->bottom->cmd != CMD_SS)
		{
			a_pop = ps_pop_bottom_cmd_stack(cmd_stack->a); // 함수화 하기 ps_pop_one_print()
			ps_print_cmd(a_pop->cmd);
			free(a_pop);
		}
		else if (cmd_stack->b->len)
		{
			b_pop = ps_pop_bottom_cmd_stack(cmd_stack->b);
			ps_print_cmd(b_pop->cmd);
			free(b_pop);
		}
	}
	while (cmd_stack->a->len)
	{
		a_pop = ps_pop_bottom_cmd_stack(cmd_stack->a);
		ps_print_cmd(a_pop->cmd);
		free(a_pop);
	}
	while (cmd_stack->b->len)
	{
		b_pop = ps_pop_bottom_cmd_stack(cmd_stack->b);
		ps_print_cmd(b_pop->cmd);
		free(b_pop);
	}
	return (0);
}

int	ps_print_cmd(enum e_command cmd)
{
	if (cmd == CMD_SA)
		write(1, "sa\n", 3);
	else if (cmd == CMD_SB)
		write(1, "sb\n", 3);
	else if (cmd == CMD_SS)
		write(1, "ss\n", 3);
	else if (cmd == CMD_PA)
		write(1, "pa\n", 3);
	else if (cmd == CMD_PB)
		write(1, "pb\n", 3);
	else if (cmd == CMD_RA)
		write(1, "ra\n", 3);
	else if (cmd == CMD_RB)
		write(1, "rb\n", 3);
	else if (cmd == CMD_RR)
		write(1, "rr\n", 3);
	else if (cmd == CMD_RRA)
		write(1, "rra\n", 4);
	else if (cmd == CMD_RRB)
		write(1, "rrb\n", 4);
	else if (cmd == CMD_RRR)
		write(1, "rrr\n", 4);
	else
		write(2, "Error\n", 6);
	return (1);
}
