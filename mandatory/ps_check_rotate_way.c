
#include	"push_swap.h"

int	ps_check_rotate_way(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int data)
{
	int	sum[2];
	int	cnt[2];
	int	tmp;

	cnt[0] = ps_cnt_position_astack(a, data);
	cnt[1] = ps_cnt_position_bstack(b, data);
	if (((cnt[0] <= a->len / 2 && cnt[1] <= b->len / 2) || (cnt[0] > a->len / 2 && cnt[1] > b->len / 2)) \
		|| ps_rotate_same_way(a, b, cmd_stack, cnt) == 0)
	{
		ps_rotate_bstack(b, data, cmd_stack);
		ps_sort_mass_rotate(a, cmd_stack, b->top->data, cnt[1]); // cnt[1] 역할 확인
		ps_cmd_pab(b, a, cmd_stack);
		return (1);
	}
	return (1);
}
// 체크하고 같을 경우 이 안에서 로테이트함

int	ps_rotate_same_way(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int cnt[2])
{
	int	rev[2];
	int	up_to_down;
	int	down_to_up;

	rev[0] = a->len - cnt[0]; // 거꾸로
	rev[1] = b->len - cnt[1]; // 거꾸로
	if (rev[0] < rev[1])
		down_to_up = rev[1];
	else
		down_to_up = rev[0];
	if (cnt[0] < cnt[1])
		up_to_down = cnt[1];
	else
		up_to_down = cnt[0];
	if ((cnt[0] < rev[0] && cnt[0] + rev[1] < up_to_down && cnt[0] + rev[1] < down_to_up) \
		|| (cnt[1] < rev[1] && cnt[1] + rev[0] < up_to_down && cnt[1] + rev[0] < down_to_up))
		return (0);
	if (down_to_up < up_to_down) // 따로 돌아가는 것이 이득일 수도 있다. 그 경우 확인해주어야 한다. 
	{
		ps_rotate_rrab(a, cmd_stack, rev[0]); // 함수로 하나로 묶어서 처리하기
		ps_rotate_rrab(b, cmd_stack, rev[1]);
	}
	else
	{
		ps_rotate_rab(a, cmd_stack, cnt[0]); // 이것도 하나로 묶어서 처리
		ps_rotate_rab(b, cmd_stack, cnt[1]);
	}		
	ps_cmd_pab(b, a, cmd_stack);
	return (1);
}
// 체크하고 다를경우 로테이트함

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
