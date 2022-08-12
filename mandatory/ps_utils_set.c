#include	"push_swap.h"

//int	ps_set_a_stack(t_stack *stack, char *argv[]) // 함수 나누기

int	ps_set_a_stack(t_stack *stack) // 함수 나누기
{
//	t_list	*list;
//	char	**pstr;
//	int		idx;

	stack->len = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->stack = A_STACK;

//
/*
	stack->top = (t_list *)malloc(sizeof(t_list));
	list = stack->top;
//	list->flag = 0;
	idx = 0;
	argv++;
	pstr = ps_ft_split(*argv, ' ');
	argv++;
	while (pstr != NULL)
	{
		if (stack->len != 0)
		{
			list->next = (t_list *)malloc(sizeof(t_list));
			list = list->next;
		}
		// is_char_digit ? 확인 한번 해주기
		list->data = ps_ft_atoi(pstr[idx++]); // valid 한 인자인지 확인은 요기 어디선가.
		free(pstr[idx - 1]);
//		list->flag = 0;
		stack->len++;
		if (pstr[idx] == NULL)
		{
			free(pstr);
			pstr = ps_ft_split(*argv, ' ');
			argv++;
			idx = 0;
		}
	}
	stack->bottom = list;
	list->next = NULL;
	*/
//
	return (1);
}

int	ps_set_b_stack(t_stack *stack)
{
	stack->len = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->stack = B_STACK;
	return (0);
}

void ps_set_cmd_stack(t_cmd_stack *stack)
{
	stack->a = (t_cmd_ab_stack *)malloc(sizeof(t_cmd_ab_stack));
	stack->b = (t_cmd_ab_stack *)malloc(sizeof(t_cmd_ab_stack));
	stack->a->top = NULL;
	stack->a->bottom = NULL;
	stack->b->top = NULL;
	stack->b->bottom = NULL;
	stack->a->len = 0;
	stack->b->len = 0;
}
