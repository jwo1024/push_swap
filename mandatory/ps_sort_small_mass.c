#include	"push_swap.h"


void	ps_sort_small_mass(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack)
{
	if (a->len == 2)
		ps_sort_small_mass2(a, cmd_stack);
	else if (a->len == 3)
		ps_sort_small_mass3(a, cmd_stack);
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