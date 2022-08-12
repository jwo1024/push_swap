
#include	"push_swap.h"

int		push_swap(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int *set);
void	ps_get_pivot(int **piv, int len, int *set);



int	main(int argc, char *argv[])
{
	t_stack		a_stack;
	t_stack		b_stack;
	t_cmd_stack	cmd_stack;
	int			*set;

	if (argc < 2)
		return (0); // no argv
	ps_set_cmd_stack(&cmd_stack);
	ps_set_a_stack(&a_stack, argc, argv);
	ps_set_b_stack(&b_stack);

	set = ps_quick_sort(&a_stack);
//	if (set == NULL || ps_is_valid_input(set, a_stack.len) == 0)
//		ps_error();
	//	ps_error("Error\n : ps_quick_sort() : overlapping numbers");
	//	ps_clear_stack();
//	getchar(); // 유효성까지 끝낸다음 아래
	if (a_stack.len <= 3)
		ps_sort_small_mass(&a_stack, &b_stack, &cmd_stack);
	else
		push_swap(&a_stack, &b_stack, &cmd_stack, set);

//	print_ab_stack(&a_stack, &b_stack);
	check_print_cmd(&cmd_stack);
	// ps_clear_all();

	free(set);
	return (0);
}

// NULL
void	ps_get_pivot(int **piv, int len, int *set) //여기에서 오류 나는 이유 알ㄹㅈ
{
	len -= 2;
	(*piv)[0] = set[len / 3];
	(*piv)[1] = set[len / 3 * 2 + 1];
	if (len % 3 == 2)
		piv[1]++; // 이거 맞아 ?? 이상한데
}

int	push_swap(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int *set)
{
	int	len;
	int	*piv;

	piv = (int *)malloc(sizeof(int) * 2);
	len = a->len;
	ps_get_pivot(&piv, len, set);
//	printf("piv %d %d\n", piv[0], piv[1]);

	divide_to_three_mass(a, b, cmd_stack, piv);
	
	while (b->len && (b->top->data > piv[1] || b->bottom->data > piv[1]))
		ps_sort_mass(a, b, cmd_stack, piv[1]); /////
	while (b->len && (b->top->data > piv[0] || b->bottom->data > piv[0]))
		ps_sort_mass(a, b, cmd_stack, piv[0]);
	while (b->len > 1)
		ps_sort_mass(a, b, cmd_stack, set[0]);
	if (b->len)
		ps_sort_mass_rotate(a, cmd_stack, b->top->data, 0);
	ps_cmd_pab(b, a, cmd_stack);
	ps_final_rotate(a, cmd_stack, set);
	free(piv);
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

int	divide_to_three_mass(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int piv[2])
{
	int		len;

	len = a->len / 3 + a->len % 3;
	while (a->len > len)
	{
		
		if (a->top->data <= piv[1] && a->top->data > piv[0]) // 중간덩어리
			ps_cmd_pab(a, b, cmd_stack);
		else if (a->top->data <= piv[0])// 작은덩어리
		{
			ps_cmd_pab(a, b, cmd_stack);
			ps_cmd_rab(b, cmd_stack);
		}
		else
			ps_cmd_rab(a, cmd_stack);
	}
	while (a->len > 3)
		ps_cmd_pab(a, b, cmd_stack);
	ps_sort_small_mass3(a, cmd_stack);
	return (1);
}






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
		if (list->data >= piv) // > -> >=
		{
			cnt[0] = ps_sort_mass_cnt(a, list->data, ps_is_position_up);
			cnt[1] = ps_sort_mass_cnt(b, list->data, ps_is_position_down);
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

int	ps_rotate_bstack(t_stack *b, int num, t_cmd_stack *cmd_stack) // 나갈애가 위로 가도록 bstack 돌리고
{	
	int	cnt;
	t_list	*list;

	cnt = 0;
	list = b->top;
	while (num != list->data)
	{
		list = list->next;
		cnt++;
	}
	if (cnt <= b->len / 2) //만약 윗쪽에 위치한다면 
	{
		while (cnt--)
			ps_cmd_rab(b, cmd_stack);	
	}
	else
	{
		cnt = b->len - cnt;
		while (cnt--)
			ps_cmd_rrab(b, cmd_stack);
	}
	return (1);
}


int	ps_sort_mass_rotate(t_stack *a, t_cmd_stack *cmd_stack, int num, int cnt) // 맞는 자리로 a스택 돌린다. 
{
	cnt = ps_is_position_up(a, num);
	if (cnt <= a->len / 2)
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




//----------------------------------




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


int	ps_check_rotate_way(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int data)
{
	int	sum[2];
	int	cnt[2];
	int	tmp;

	cnt[0] = ps_is_position_up(a, data);
	cnt[1] = ps_is_position_down(b, data);
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


//----------------------------------


int	ps_sort_mass_cnt(t_stack *stack, int num, int (fp)(t_stack *, int))
{
	int	cnt;

	cnt = fp(stack, num);
	if (cnt <= stack->len / 2)
		return (cnt);
	else
		return (stack->len - cnt);
	return (1);
}
int	ps_is_position_up(t_stack *a, int num) //position_cnt_a
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
int	ps_is_position_down(t_stack *a, int num) // position_cnt_b
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