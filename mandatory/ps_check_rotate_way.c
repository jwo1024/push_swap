/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_rotate_way.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:44:38 by jiwolee           #+#    #+#             */
/*   Updated: 2022/08/13 18:18:32 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ps_check_rotate_way(t_stack *a, t_stack *b, \
						t_cmd_stack *cmd_stack, int data)
{
	int	cnt[2];

	cnt[0] = ps_cnt_position_astack(a, data);
	cnt[1] = ps_cnt_position_bstack(b, data);
	if (((cnt[0] <= a->len / 2 && cnt[1] <= b->len / 2) \
		|| (cnt[0] > a->len / 2 && cnt[1] > b->len / 2)) \
		|| ps_rotate_same_way(a, b, cmd_stack, cnt) == 0)
	{
		ps_rotate_bstack(b, data, cmd_stack);
		ps_rotate_astack(a, cmd_stack, b->top->data);
		ps_cmd_pab(b, a, cmd_stack);
		return (1);
	}
	return (1);
}

int	ps_rotate_same_way(t_stack *a, t_stack *b, \
						t_cmd_stack *cmd_stack, int cnt[2])
{
	int	rev[2];
	int	up_to_down;
	int	down_to_up;

	rev[0] = a->len - cnt[0];
	rev[1] = b->len - cnt[1];
	if (rev[0] < rev[1])
		down_to_up = rev[1];
	else
		down_to_up = rev[0];
	if (cnt[0] < cnt[1])
		up_to_down = cnt[1];
	else
		up_to_down = cnt[0];
	if ((cnt[0] < rev[0] && cnt[0] + rev[1] < up_to_down \
		&& cnt[0] + rev[1] < down_to_up) || (cnt[1] < rev[1] \
		&& cnt[1] + rev[0] < up_to_down && cnt[1] + rev[0] < down_to_up))
		return (0);
	if (down_to_up < up_to_down)
		ps_rotate_rrab_both(a, b, cmd_stack, rev);
	else
		ps_rotate_rab_both(a, b, cmd_stack, cnt);
	ps_cmd_pab(b, a, cmd_stack);
	return (1);
}

int	ps_rotate_bstack(t_stack *b, int num, t_cmd_stack *cmd_stack)
{	
	int	cnt;

	cnt = ps_cnt_position_bstack(b, num);
	if (cnt <= b->len / 2)
		ps_rotate_rab(b, cmd_stack, cnt);
	else
	{
		cnt = b->len - cnt;
		ps_rotate_rrab(b, cmd_stack, cnt);
	}
	return (1);
}

int	ps_rotate_astack(t_stack *a, t_cmd_stack *cmd_stack, int num)
{
	int	cnt;

	cnt = ps_cnt_position_astack(a, num);
	if (cnt <= a->len / 2)
		ps_rotate_rab(a, cmd_stack, cnt);
	else
	{
		cnt = a->len - cnt;
		ps_rotate_rrab(a, cmd_stack, cnt);
	}
	return (1);
}

int	ps_final_rotate(t_stack *a, t_cmd_stack *cmd_stack, int *set)
{
	int		cnt;
	t_list	*list;

	cnt = 0;
	list = a->top;
	while (list)
	{
		if (list->data == set[0])
			break ;
		list = list->next;
		cnt++;
	}
	if (cnt <= a->len / 2)
		ps_rotate_rab(a, cmd_stack, cnt);
	else
	{
		cnt = a->len - cnt;
		ps_rotate_rrab(a, cmd_stack, cnt);
	}
	return (1);
}
