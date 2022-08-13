/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:04:31 by jiwolee           #+#    #+#             */
/*   Updated: 2022/08/13 18:05:20 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

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

void	ps_set_cmd_stack(t_cmd_stack *stack)
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

void	ps_error(void)
{
	write(2, "Error\n", 6);
}

int	ps_insert_bottom_stack(t_stack *stack, int data)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		exit(1);
	list->data = data;
	list->next = NULL;
	if (stack->bottom != NULL)
		stack->bottom->next = list;
	stack->bottom = list;
	if (stack->len == 0)
		stack->top = list;
	stack->len++;
	return (1);
}
