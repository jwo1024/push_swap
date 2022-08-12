#include	"push_swap.h"

int	ps_is_valid_input(int *set, int len)
{
	int	i;
	int	flg;

	i = 0;
	flg = 0;
	while (i + 1 < len)
	{
		if (set[i] == set[i + 1])
		{
			flg = 0;
			break;
		}
		else if (!(set[i] < set[i + 1]))
			flg = 1;
		i++;
	}
	if (flg == 1)
		return (1);
	free(set);
	return (0);
}

void	ps_error()
{
	write(2, "\nError", 6);
}

/*

검사해야할것

- 같은 숫자 duplicates
- 이미 정렬되었는지

- 숫자가 아닌 문자
- 공백 " "
- integer 범위



*/