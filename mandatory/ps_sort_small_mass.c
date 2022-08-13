#include	"push_swap.h"


void	ps_sort_small_mass(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int *set)
{
	if (a->len == 1)
		;
	else if (a->len == 2)
		ps_sort_small_mass2(a, cmd_stack);
	else if (a->len == 3)
		ps_sort_small_mass3(a, cmd_stack);
	else // 4개 5개 일때.. 
		ps_sort_small_mass5(a, b, cmd_stack, set);
}

void	ps_sort_small_mass2(t_stack *a, t_cmd_stack *cmd_stack)
{
	if (a->top->data > a->bottom->data)
		ps_cmd_sab(a, cmd_stack);
}

void	ps_sort_small_mass3(t_stack *a, t_cmd_stack *cmd_stack)
{
	if (a->top->data > a->top->next->data && a->top->data > a->bottom->data)
		ps_cmd_rab(a, cmd_stack);
	else if (a->top->next->data > a->top->data && a->top->next->data > a->bottom->data)
		ps_cmd_rrab(a, cmd_stack);
	if (a->top->data > a->top->next->data)
		ps_cmd_sab(a, cmd_stack);
}

// 이거 안돼... 
void	ps_sort_small_mass5(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int *set) // 7개 이하로
{
	int	piv;

	if (a->len == 5)
		piv = set[2];
	else
		piv = set[1];
	while (a->len > 3)
	{
		if (a->top->data < piv)
			ps_cmd_pab(a, b, cmd_stack);
		ps_cmd_rab(a, cmd_stack);
	}
	ps_sort_small_mass3(a, cmd_stack);
	if (b->top->data < b->bottom->data)
		ps_cmd_sab(b, cmd_stack);
	while (b->len)
		ps_cmd_pab(b, a, cmd_stack);
}
