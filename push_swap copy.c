
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
//	printf("%d", set[0]);
	if (set == NULL)
		printf("error\n");
	//	ps_error("Error\n : ps_quick_sort() : overlapping numbers");
	//	ps_clear_stack();

//	getchar(); // 유효성까지 끝낸다음 아래

	if (a_stack.len <= 3) // 5일때 처리할지 말지 나중에 결정하기
		ps_sort_small_mass(&a_stack, &b_stack, &cmd_stack);
	else
		push_swap(&a_stack, &b_stack, &cmd_stack, set);

	print_ab_stack(&a_stack, &b_stack);
	check_print_cmd(&cmd_stack);

	free(set);

	return (0);
}

// NULL
void	ps_get_pivot(int **piv, int len, int *set) //여기에서 오류 나는 이유 알ㄹㅈ
{
	len -= 2;

	(*piv)[0] = set[len / 3];
	(*piv)[1] = set[len / 3 * 2 + 1];
//	printf("pivvvv %d %d", len / 3, len / 3 * 2 + 1);
	if (len % 3 == 2)
		piv[1]++;
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
//	print_ab_stack(a, b);

	ps_final_rotate(a, cmd_stack, set);


	free(piv);
	// cmd_stack 이용시 마지막에 정리 및 출력해주기
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
//	printf("divdedto three mass\n");
//	print_ab_stack(a, b);
//	getchar();
	return (1);
}



int	ps_sort_mass(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int piv)
{

	// b 스택 피벗 기준 큰거 애들만 검사해서 넘겨줄 애 위치 확인한다.
	t_list	*list;
	int		min;
	int		cnt[2];
	int		data;

	min = 2000000000;
	list = b->top;
	data = 0;
	while (list)
	{
		if (list->data > piv) // ???? 
		{
			cnt[0] = ps_sort_mass_cnt(a, list->data); /// 여기가 문제..
			cnt[1] = ps_is_position_down(b, list->data);
			cnt[1]--;
		//	printf("data %d // cnt [%d] [%d]\n", list->data, cnt[0], cnt[1]);
			if (min > cnt[0] + cnt[1]) /// 두가지를 계산을 먼저 해둔다면
			{
				min = cnt[0]+ cnt[1];
				data = list->data;
			}
		}
		list = list->next;
//		print_ab_stack(a, b);
//		getchar();
	}
//	printf("data %d cnt %d min %d\n", data, cnt, min);
	ps_rotate_bstack(b, data, cmd_stack);
	ps_sort_mass_rotate(a, cmd_stack, b->top->data, cnt[1]);
	ps_cmd_pab(b, a, cmd_stack);

//	print_ab_stack(a, b);
//	getchar();


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

int	ps_sort_mass_cnt(t_stack *a, int num)
{
	int	cnt;

	cnt = ps_is_position_up(a, num);
	if (cnt <= a->len / 2)
		return (cnt);
	else
		return (a->len - cnt);
	return (1);
}




int	ps_sort_mass1(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int piv[2]) //xxxxx
{
	while (b->len != 0)
	{
		if (ps_is_right_top(a, b->top->data))
			ps_cmd_pab(b, a, cmd_stack);
		else
		{
			int cnt = ps_is_position_up(a,  b->top->data);
			ps_sort_mass_rotate(a, cmd_stack, b->top->data, cnt);
			ps_cmd_pab(b, a, cmd_stack);
		}
	}
	return (1);
}






int	ps_sort_mass_rotate(t_stack *a, t_cmd_stack *cmd_stack, int num, int cnt) // 맞는 자리로 a스택 돌린다. 
{
//	int	cnt;

	cnt = ps_is_position_up(a, num);
//	printf("cnt %d\n", cnt);

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

int	ps_is_position_up(t_stack *a, int num)
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


int	ps_is_position_down(t_stack *a, int num)
{
	int		cnt;
	t_list	*list;

	cnt = 1;
	list = a->top;

	while (list->data != num)
	{
		list = list->next;
		cnt++;
	}
	return (cnt);
}


int	ps_is_right_top(t_stack *a, int num)
{
	if (a->top->data > a->bottom->data)
	{
		if (a->top->data > num && num > a->bottom->data)
			return (1);
	}
	else // top < bottom  // 정렬되어 있는 상태
	{
		if (num < a->top->data || num > a->bottom->data)
			return (1);
	}
	return (0);
}