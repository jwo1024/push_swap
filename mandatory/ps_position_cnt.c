/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_position_cnt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:48:48 by jiwolee           #+#    #+#             */
/*   Updated: 2022/08/13 17:57:46 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ps_get_min_rotate_cnt(t_stack *stack, int num)
{
	int	cnt;

	if (stack->stack == A_STACK)
		cnt = ps_cnt_position_astack(stack, num);
	else
		cnt = ps_cnt_position_bstack(stack, num);
	if (cnt <= stack->len / 2)
		return (cnt);
	else
		return (stack->len - cnt);
	return (1);
}

int	ps_cnt_position_astack(t_stack *a, int num)
{
	int		cnt;
	t_list	*list;

	cnt = 1;
	list = a->top;
	while (1)
	{
		if ((list->next == NULL || list->data > list->next->data) \
			&& (list->data < num || (list->next == NULL || \
			list->next->data > num)))
			break ;
		else if ((list->next == NULL || list->data < list->next->data) \
				&& list->data < num && (list->next == NULL || \
				list->next->data > num))
			break ;
		list = list->next;
		cnt++;
	}
	return (cnt);
}

int	ps_cnt_position_bstack(t_stack *a, int num)
{
	int		cnt;
	t_list	*list;

	cnt = 0;
	list = a->top;
	while (list->data != num)
	{
		list = list->next;
		cnt++;
	}
	return (cnt);
}
