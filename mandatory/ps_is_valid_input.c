#include	"push_swap.h"

// check and insert num

int	ps_insert_bottom_stack(t_stack *stack, int data);
int	ps_insert_stack_argv(t_stack *stack, char *argv[]);
int	ps_check_valid_num(char *str);
int	ps_check_valid_num_1(char *str, int i);
int	ps_is_already_sorted(t_stack *stack);

int		ps_check_duplicates(int *set, int len);
void	ps_error();


void	ps_error()
{
	write(2, "Error\n", 6);
}

int	ps_insert_bottom_stack(t_stack *stack, int data)
{
	t_list	*list;
	
	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		exit(1);
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

// --------------------------------

int	ps_insert_stack_argv(t_stack *stack, char *argv[])
{
	char	**pstr;
	int		idx;

	idx = 0;
	argv++;
	pstr = ft_split(*argv, ' ');
	argv++;
	while (pstr != NULL)
	{
		if (ps_check_valid_num(pstr[idx]) == -1)
		{
			while (pstr[idx])
				free(pstr[idx++]);
			free(pstr);
			return (-1);
		}
		ps_insert_bottom_stack(stack, ft_atoi(pstr[idx]));
		free(pstr[idx++]);
		if (pstr[idx] == NULL)
		{
			free(pstr);
			pstr = ft_split(*argv, ' ');
			argv++;
			idx = 0;
		}
	}
	return (1);
}

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

int	ps_check_valid_num(char *str)
{
	int					i;

	i = 1;
	if (str == NULL)
		return (-1);
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i *= -1;
		str++;
	}
	if (*str == '\0')
		return (-1);
	return (ps_check_valid_num_1(str, i));
}

int	ps_check_valid_num_1(char *str, int i)
{
	unsigned long long	mul;
	unsigned long long	result;
	int					idx;

	mul = 1;
	idx = 0;
	result = 0;
	while (str[idx])
	{
		if (!('0' <= str[idx] && str[idx] <= '9'))// ft_isdigit > 0 
			return (-1);
		idx++;
	}
	while (0 < idx--)
	{
		result += (str[idx] - '0') * mul;
		if (mul == 1000000000)
			break;
		mul *= 10;
	}
	if ((result > 2147483648 && i == -1) \
		|| (result > 2147483647 && i == 1) || idx > 0)
		return (-1);
	return (1);
}


int	ps_is_already_sorted(t_stack *stack)
{
	t_list	*list;
	int		flg;

	flg = 0;
	list = stack->top;
	while (list->next)
	{
		if (list->data > list->next->data)
			flg = 1;
		list = list->next;
	}
	if (flg == 1)
		return (-1);
	return (1);
}