#include	"push_swap.h"

int	ft_isdigit(int c);
int	ps_insert_bottom_stack(t_stack *stack, int data);
int	ps_insert_stack_argv(t_stack *stack, char *argv[]);

int	ps_check_duplicates(int *set, int len) //ps_is_valid_input
{
	int	i;

	i = 0;
	while (i + 1 < len)
	{
		if (set[i] == set[i + 1]) // 같은 숫자 있을 경우 에러처리
			return (-1);
		i++;
	}
	return (1);
}

void	ps_error()
{
	write(2, "\nError", 6);
}


int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (3);
	return (0);
}


int	ps_insert_bottom_stack(t_stack *stack, int data);


int	ps_insert_stack_argv(t_stack *stack, char *argv[])
{
	char	**pstr;
	int		data;
	int		fro_data;
	int		idx;

	idx = 0;
	argv++;
	pstr = ps_ft_split(*argv, ' ');
	argv++;
	fro_data = 0;
	while (pstr != NULL)
	{
		if (1) // 이미 정렬되어 있는 오름차순일경우 감지
			;
		if (1) // ft_isdigit ? 확인 한번 해주기
			return (-1); // pstr 다 해제해주고
		data = ps_ft_atoi(pstr[idx++]); // valid 한 인자인지 확인은 요기 어디선가.
		free(pstr[idx - 1]);
		ps_insert_bottom_stack(stack, data);
		fro_data = data;
		if (pstr[idx] == NULL)
		{
			free(pstr);
			pstr = ps_ft_split(*argv, ' ');
			argv++;
			idx = 0;
		}
	}
	return (1);
}


int	ps_insert_bottom_stack(t_stack *stack, int	data)
{
	t_list	*list;
	
	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (-1);
	list->data = data;
	list->next = NULL;
	stack->bottom->next = list;
	list->flag = 0; // 이거 지워도 되나 확인 쓰이는 곳 없나
	stack->bottom = list;
	if (stack->len == 0)
		stack->top = list;
	stack->len++;
	return (1);
}

// 1 2 3 4 
// 

/*

검사해야할것

- 같은 숫자 duplicates
- 이미 정렬되었는지

- 숫자가 아닌 문자
- 공백 " "

- integer 범위 ---> atoi 에서 다뤄야 하나?



*/