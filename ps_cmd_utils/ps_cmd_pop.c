/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmd_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:42:36 by jiwolee           #+#    #+#             */
/*   Updated: 2022/08/13 19:45:33 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ps_cmd_pop_free_one(t_cmd_stack *cmd_stack, enum e_stack stack)
{
	t_cmd_list	*pop;

	if (stack == A_STACK)
		pop = ps_pop_cmd_stack(cmd_stack->a);
	else if (stack == B_STACK)
		pop = ps_pop_cmd_stack(cmd_stack->b);
	else
		return ;
	free(pop);
}

void	ps_cmd_pop_free_two(t_cmd_stack *cmd_stack)
{
	t_cmd_list	*pop;

	pop = ps_pop_cmd_stack(cmd_stack->a);
	free(pop);
	pop = ps_pop_cmd_stack(cmd_stack->b);
	free(pop);
}

void	ps_cmd_pop_free_print_one(t_cmd_ab_stack *ab)
{
	t_cmd_list	*pop;

	pop = ps_pop_bottom_cmd_stack(ab);
	ps_print_cmd(pop->cmd);
	free(pop);
}

void	ps_cmd_pop_free_print_two(t_cmd_ab_stack *a, t_cmd_ab_stack *b)
{
	t_cmd_list	*a_pop;
	t_cmd_list	*b_pop;

	a_pop = ps_pop_bottom_cmd_stack(a);
	b_pop = ps_pop_bottom_cmd_stack(b);
	ps_print_cmd(a_pop->cmd);
	free(a_pop);
	free(b_pop);
}
