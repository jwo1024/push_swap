/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:43:37 by jiwolee           #+#    #+#             */
/*   Updated: 2022/08/13 19:46:26 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ps_check_delete_cmd_a(enum e_command cmd1, enum e_command cmd2)
{
	if ((cmd1 == CMD_SA && cmd2 == CMD_SA) \
		|| (cmd1 == CMD_RA && cmd2 == CMD_RRA) \
		|| (cmd1 == CMD_RRA && cmd2 == CMD_RA))
		return (1);
	return (0);
}

int	ps_check_delete_cmd_b(enum e_command cmd1, enum e_command cmd2)
{
	if ((cmd1 == CMD_SB && cmd2 == CMD_SB) \
			|| (cmd1 == CMD_RB && cmd2 == CMD_RRB) \
			|| (cmd1 == CMD_RRB && cmd2 == CMD_RB))
		return (1);
	return (0);
}

int	ps_check_delete_cmd_both(enum e_command cmd, \
							enum e_command cmd_a, enum e_command cmd_b)
{
	if ((cmd == CMD_PA && cmd_a == CMD_PB \
		&& cmd_b == CMD_PB) || (cmd_b == CMD_PA \
		&& cmd == CMD_PB && cmd_a == CMD_PA))
		return (1);
	return (0);
}
