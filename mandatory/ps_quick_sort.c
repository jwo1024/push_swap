#include	"push_swap.h"

void	sort_swap(int *a, int *b);
void	sort_quick_ascending(int *set, int left, int right);

void	sort_quick_ascending(int *set, int left, int right)
{
	int	*pivot;
	int	l;
	int	r;

	if (!set || left >= right)
		return ;
	pivot = &(set[left]);
	l = left + 1;
	r = right;
	while (l <= r)
	{
		while (*pivot > set[l] && l <= r)
			l++;
		while (*pivot <= set[r] && l <= r)
			r--;
		if (l < r)
			sort_swap(&(set[l]), &(set[r]));
		else
			break;
	}
	sort_swap(pivot, &(set[r]));
	sort_quick_ascending(set, left, r - 1);
	sort_quick_ascending(set, r + 1, right);
}

void	sort_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*ps_quick_sort(t_stack *stack)
{
	int	*set;
	int	len;
	int	i;
	t_list	*list;

	len = stack->len;
	set = (int *)malloc(sizeof(int) * len);
	list = stack->top;
	i = 0;
	while(i < len && list)
	{
		set[i] = list->data;
		list = list->next;
		i++;
	}
	sort_quick_ascending(set, 0, len - 1);
	return (set);
}
