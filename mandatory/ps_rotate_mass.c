/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_mass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:51:41 by jiwolee           #+#    #+#             */
/*   Updated: 2022/08/13 18:19:11 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ps_sort_mass(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int piv)
{
	t_list	*list;
	int		min;
	int		cnt[2];
	int		data;

	min = 2000000000;
	list = b->top;
	data = 0;
	while (list)
	{
		if (list->data >= piv)
		{
			cnt[0] = ps_get_min_rotate_cnt(a, list->data);
			cnt[1] = ps_get_min_rotate_cnt(b, list->data);
			if (min > cnt[0] + cnt[1])
			{
				min = cnt[0] + cnt[1];
				data = list->data;
			}
		}
		list = list->next;
	}
	ps_check_rotate_way(a, b, cmd_stack, data);
	return (1);
}

void	ps_rotate_rab(t_stack *stack, t_cmd_stack *cmd_stack, int cnt)
{
	while (cnt--)
		ps_cmd_rab(stack, cmd_stack);
}

void	ps_rotate_rrab(t_stack *stack, t_cmd_stack *cmd_stack, int cnt)
{
	while (cnt--)
		ps_cmd_rrab(stack, cmd_stack);
}

void	ps_rotate_rrab_both(t_stack *a, t_stack *b, \
					t_cmd_stack *cmd_stack, int rev[2])
{
	ps_rotate_rrab(a, cmd_stack, rev[0]);
	ps_rotate_rrab(b, cmd_stack, rev[1]);
}

void	ps_rotate_rab_both(t_stack *a, t_stack *b, \
					t_cmd_stack *cmd_stack, int cnt[2])
{
	ps_rotate_rab(a, cmd_stack, cnt[0]);
	ps_rotate_rab(b, cmd_stack, cnt[1]);
}
