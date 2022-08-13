
#include	"push_swap.h"

/*
처리 해야 할것
clear 함수 만들기 v
ps_insert_stack_argv() pstr free 해주기 v
int max, min 처리 하기 v
argc 5개 처리하기
norminette 돌리기 + 함수 분리
함수 반환 확인
정렬되어서 들어왔을때 처리 v
*/

int	push_swap_1(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int *set);

int	main(int argc, char *argv[])
{
	t_stack		a_stack;
	t_stack		b_stack;
	t_cmd_stack	cmd_stack;
	int			*set;

	if (argc < 2)
		return (0); // no argv
	ps_set_cmd_stack(&cmd_stack);
	ps_set_a_stack(&a_stack);
	ps_set_b_stack(&b_stack);
	set = NULL;
	if (ps_insert_stack_argv(&a_stack, argv) == -1)
		ps_error();
	else if (ps_is_already_sorted(&a_stack) == 1)
		;
	else
	{
		set = ps_quick_sort(&a_stack);
		if (set != NULL && ps_check_duplicates(set, a_stack.len) == 1)
			push_swap(&a_stack, &b_stack, &cmd_stack, set);
		else
			ps_error();
	}
	ps_clear_all(&a_stack, &b_stack, &cmd_stack, set);
	system("leaks push_swap");
	return (0);
}

int	push_swap(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int *set) //retur void
{
	if (a->len <= 5) // 4개 일경우...5 개일때 문제 있음 !
		ps_sort_small_mass(a, b, cmd_stack, set);
	else
		push_swap_1(a, b, cmd_stack, set);
	check_print_cmd(cmd_stack);
	return (1);
}

int	push_swap_1(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int *set)
{
	int	len;
	int	*piv;

	piv = (int *)malloc(sizeof(int) * 2);
	len = a->len;
	ps_get_pivot(&piv, len, set);

	divide_to_three_mass(a, b, cmd_stack, piv);

	while (b->len && (b->top->data > piv[1] || b->bottom->data > piv[1]))
		ps_sort_mass(a, b, cmd_stack, piv[1]);
	while (b->len && (b->top->data > piv[0] || b->bottom->data > piv[0]))
		ps_sort_mass(a, b, cmd_stack, piv[0]);
	while (b->len > 0)
		ps_sort_mass(a, b, cmd_stack, set[0]);
	
//	if (b->len)
//		ps_sort_mass_rotate(a, cmd_stack, b->top->data, 0);
//	ps_cmd_pab(b, a, cmd_stack); //// um.. 

	ps_final_rotate(a, cmd_stack, set);
	free(piv);
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

void	ps_get_pivot(int **piv, int len, int *set)
{
	len -= 2;
	(*piv)[0] = set[len / 3];
	(*piv)[1] = set[len / 3 * 2 + 1];
}
