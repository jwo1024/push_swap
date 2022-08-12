#include	"push_swap.h"

// ps_get_func_cnt   ps_sort_mass_cnt
int	ps_get_stack_cnt_func(t_stack *stack, int num, int (fp)(t_stack *, int))
{
	int	cnt;

	cnt = fp(stack, num);
	if (cnt <= stack->len / 2)
		return (cnt);
	else
		return (stack->len - cnt);
	return (1);
}

int	ps_cnt_position_astack(t_stack *a, int num) //position_cnt_a  ps_is_position_up
{
	int		cnt;
	t_list	*list;

	cnt = 1;
	list = a->top;
	while (1)
	{
		if ((list->next == NULL || list->data > list->next->data) \
			&& (list->data < num || (list->next == NULL || list->next->data > num)))
			break;
		else if ((list->next == NULL || list->data < list->next->data) \
				&& list->data < num && (list->next == NULL || list->next->data > num))
			break;
		list = list->next;
		cnt++;
	}
	return (cnt);
}

int	ps_cnt_position_bstack(t_stack *a, int num) // position_cnt_b // ps_is_position_down
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