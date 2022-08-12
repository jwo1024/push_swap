#include	"push_swap.h"

int	ps_str_isdigit(char *str);
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
	write(2, "Error\n", 6);
}


int	ps_str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[i] == '\0')
		return (-1);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9') // int min int max 확인.. -2147483647 2147483648
			;
		else
			return (-1);
		i++;
	}
	if ((i > 11 && str[0] == '-') || (i > 10 && str[0] != '-') && 1) /// atoi 변형해서
		return (-1);
/*
	if ((i > 11 && str[0] == '-') || (i > 10 && str[0] != '-')\
		|| (i == 11 && (str[0] == '-' || str[1] >= '2' || str[2] >= '1' \
		|| str[3] >= '4' || str[4] >= '7' || str[5] >= '4' || str[6] >= '8' \
		|| str[7] >= '3' || str[8] >= '6' || str[9] >= '4' || str[10] > '7')) \
		|| (i == 10 && (str[0] >= '2' || str[1] >= '1' || str[2] >= '4' \
		|| str[3] >= '7' || str[4] >= '4' || str[5] >= '8' || str[6] >= '3' \
		|| str[7] >= '6' || str[8] >= '4') && str[9] > '8')) // 
		return (-1); ///아 이거 아닌듯 atoi ....... 로 다시 받아서 확인 하는게 나을듯
*/
	return (1);
}




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
		if (ps_str_isdigit(pstr[idx]) == -1)
			return (-1); // pstr 다 해제해주고
		if (!(fro_data < data)) // 이미 정렬되어 있는 오름차순일경우 감지 sorted
			;
		data = ps_ft_atoi(pstr[idx++]);
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


int	ps_insert_bottom_stack(t_stack *stack, int data)
{
	t_list	*list;
	
	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (-1);
	list->data = data;
	list->next = NULL;
	if (stack->bottom != NULL)
		stack->bottom->next = list;
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