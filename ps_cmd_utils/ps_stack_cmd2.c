/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_cmd2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:33:47 by jiwolee           #+#    #+#             */
/*   Updated: 2022/08/13 19:54:41 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	combine_cmd(t_cmd_stack *cmd_stack)
{
	t_cmd_list		*a_list;
	t_cmd_list		*b_list;
	enum e_command	cmd;

	a_list = cmd_stack->a->top;
	b_list = cmd_stack->b->top;
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
	int	cmd;

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

int	ps_check_cmd(enum e_command cmd, enum e_stack stack, t_cmd_stack *cmd_stack)
{
	t_cmd_list		*cmd_list;
	t_cmd_ab_stack	*a;
	t_cmd_ab_stack	*b;

	a = cmd_stack->a;
	b = cmd_stack->b;
	if ((a->len == 0 && stack == A_STACK) || (b->len == 0 && stack == B_STACK) \
		|| ((a->len == 0 || b->len == 0) && stack == AB_STACK))
		return (1);
	if (stack == A_STACK)
		cmd_list = a->top;
	else if (stack == B_STACK)
		cmd_list = b->top;
	if (stack == A_STACK && ps_check_delete_cmd_a(cmd, cmd_list->cmd))
		ps_cmd_pop_free_one(cmd_stack, A_STACK);
	else if (stack == B_STACK && ps_check_delete_cmd_a(cmd, cmd_list->cmd))
		ps_cmd_pop_free_one(cmd_stack, B_STACK);
	else if (stack == AB_STACK && ((cmd == CMD_PA && a->top->cmd == CMD_PB \
			&& b->top->cmd == CMD_PB) || (b->top->cmd == CMD_PA \
			&& cmd == CMD_PB && a->top->cmd == CMD_PA)))
		ps_cmd_pop_free_two(cmd_stack);
	else
		return (1);
	return (0);
}

int	ps_check_print_cmd(t_cmd_stack *cmd_stack)
{
	if (cmd_stack == NULL || cmd_stack->a == NULL || cmd_stack->b == NULL)
		return (-1);
	combine_cmd(cmd_stack);
	while (cmd_stack->a->len && cmd_stack->b->len)
	{
		if (cmd_stack->a->bottom->cmd == cmd_stack->b->bottom->cmd)
			ps_cmd_pop_free_print_two(cmd_stack->a, cmd_stack->b);
		else if (cmd_stack->a->len && cmd_stack->a->bottom->cmd != CMD_PA \
				&& cmd_stack->a->bottom->cmd != CMD_PB \
				&& cmd_stack->a->bottom->cmd != CMD_RR \
				&& cmd_stack->a->bottom->cmd != CMD_RRR \
				&& cmd_stack->a->bottom->cmd != CMD_SS)
			ps_cmd_pop_free_print_one(cmd_stack->a);
		else if (cmd_stack->b->len)
			ps_cmd_pop_free_print_one(cmd_stack->b);
	}
	while (cmd_stack->a->len)
		ps_cmd_pop_free_print_one(cmd_stack->a);
	while (cmd_stack->b->len)
		ps_cmd_pop_free_print_one(cmd_stack->b);
	return (1);
}

void	ps_print_cmd(enum e_command cmd)
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
}
