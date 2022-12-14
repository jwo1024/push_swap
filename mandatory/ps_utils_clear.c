/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:04:00 by jiwolee           #+#    #+#             */
/*   Updated: 2022/08/13 20:10:33 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ps_clear_all(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int *set)
{
	ps_clear_stack(a);
	ps_clear_stack(b);
	ps_clear_cmd_ab_stack(cmd_stack->a);
	ps_clear_cmd_ab_stack(cmd_stack->b);
	if (set != NULL)
		free(set);
}

void	ps_clear_stack(t_stack *stack)
{
	t_list	*list;
	t_list	*next;

	if (stack != NULL)
	{
		list = stack->top;
		while (list)
		{
			next = list->next;
			free(list);
			list = next;
		}
	}
}

void	ps_clear_cmd_ab_stack(t_cmd_ab_stack *ab)
{
	t_cmd_list	*pop;

	if (ab != NULL)
	{
		while (ab->len)
		{
			pop = ps_pop_cmd_stack(ab);
			if (pop != NULL)
				free(pop);
		}
		free(ab);
	}
}

void	ps_free_pstr(char **pstr)
{
	int	i;

	i = 0;
	while (pstr[i])
		free(pstr[i++]);
	free(pstr);
}
