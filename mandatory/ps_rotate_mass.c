#include	"push_swap.h"

int	ps_sort_mass(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int piv)
{
	t_list	*list;
	int		min[2];
	int		cnt[2];
	int		data;

	min[0] = 1000000000;
	min[1] = 1000000000;
	list = b->top;
	data = 0;
	while (list)
	{
		if (list->data >= piv)
		{
			cnt[0] = ps_get_stack_cnt_func(a, list->data, ps_cnt_position_astack); // 
			cnt[1] = ps_get_stack_cnt_func(b, list->data, ps_cnt_position_bstack);
			if (min[0] + min[1] > cnt[0] + cnt[1]) /// 두가지를 계산을 먼저 해둔다면
			{
				min[0] = cnt[0];
				min[1] = cnt[1];
				data = list->data;
			}
		}
		list = list->next;
	}
	ps_check_rotate_way(a, b, cmd_stack, data);
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
			break;
		list = list->next;
		cnt++;
	}
	if (cnt <= a->len / 2) //만약 윗쪽에 위치한다면 
	{
		while (cnt--)
			ps_cmd_rab(a, cmd_stack);	
	}
	else
	{
		cnt = a->len - cnt;
		while (cnt--)
			ps_cmd_rrab(a, cmd_stack);
	}
	return (1);

}

void ps_rotate_rab(t_stack *stack, t_cmd_stack *cmd_stack, int cnt)
{
	while (cnt--)
		ps_cmd_rab(stack, cmd_stack);	
}

void ps_rotate_rrab(t_stack *stack, t_cmd_stack *cmd_stack, int cnt)
{
	while (cnt--)
		ps_cmd_rrab(stack, cmd_stack);	
}
