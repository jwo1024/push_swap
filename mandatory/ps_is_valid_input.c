/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_is_valid_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:47:45 by jiwolee           #+#    #+#             */
/*   Updated: 2022/08/13 20:13:58 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ps_insert_stack_argv(t_stack *stack, char *argv[])
{
	char	**pstr;
	int		idx;

	idx = 0;
	argv++;
	pstr = ft_split(*argv, ' ');
	argv++;
	while (pstr != NULL)
	{
		if (ps_check_valid_num(pstr[idx]) == -1)
		{
			ps_free_pstr(pstr);
			return (-1);
		}
		ps_insert_bottom_stack(stack, ft_atoi(pstr[idx++]));
		if (pstr[idx] == NULL)
		{
			ps_free_pstr(pstr);
			pstr = ft_split(*argv, ' ');
			argv++;
			idx = 0;
		}
	}
	return (1);
}

int	ps_check_duplicates(int *set, int len)
{
	int	i;

	i = 0;
	while (i + 1 < len)
	{
		if (set[i] == set[i + 1])
			return (-1);
		i++;
	}
	return (1);
}

int	ps_check_valid_num(char *str)
{
	int					i;

	i = 1;
	if (str == NULL)
		return (-1);
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i *= -1;
		str++;
	}
	if (*str == '\0')
		return (-1);
	return (ps_check_valid_num_1(str, i));
}

int	ps_check_valid_num_1(char *str, int i)
{
	unsigned long long	mul;
	unsigned long long	result;
	int					idx;

	mul = 1;
	idx = 0;
	result = 0;
	while (str[idx])
	{
		if (!('0' <= str[idx] && str[idx] <= '9'))
			return (-1);
		idx++;
	}
	while (0 < idx--)
	{
		result += (str[idx] - '0') * mul;
		if (mul == 1000000000)
			break ;
		mul *= 10;
	}
	if ((result > 2147483648 && i == -1) \
		|| (result > 2147483647 && i == 1) || idx > 0)
		return (-1);
	return (1);
}

int	ps_is_already_sorted(t_stack *stack)
{
	t_list	*list;
	int		flg;

	flg = 0;
	list = stack->top;
	while (list->next)
	{
		if (list->data >= list->next->data)
			flg = 1;
		list = list->next;
	}
	if (flg == 1)
		return (-1);
	return (1);
}
