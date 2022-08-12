#ifndef PUSH_SWAP_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>

enum e_command {
	CMD_SA = 1,
	CMD_SB = 2,
	CMD_SS = 3,
	CMD_PA = 4,
	CMD_PB = 5,
	CMD_RA = 6,
	CMD_RB = 7,
	CMD_RR = 8,
	CMD_RRA = 9, 
	CMD_RRB = 10,
	CMD_RRR = 11
};

enum e_stack {
	A_STACK = 1,
	B_STACK = 2,
	AB_STACK = 3
};

typedef struct s_list {
	int				data;
	int				flag;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack {
	t_list	*top;
	t_list	*bottom;
	int		len;
	int		stack;
}	t_stack;

typedef struct s_cmd_list {
	enum e_command		cmd;
	int					cnt;
	struct s_cmd_list	*prev;
	struct s_cmd_list	*next;
}	t_cmd_list;

typedef	struct s_cmd_ab_stack {
	t_cmd_list	*top;
	t_cmd_list	*bottom;
	int		len;
} t_cmd_ab_stack;

typedef struct s_cmd_stack {
	t_cmd_ab_stack	*a;
	t_cmd_ab_stack	*b;
}	t_cmd_stack;

/*libft & quick_sort*/
int		ps_ft_atoi(const char *str);
char	**ps_ft_split(char const *s, char c);
size_t	ps_ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ps_ft_strlen(const char *s);
char	*ps_ft_substr(char const *s, unsigned int start, size_t len);
int		*ps_quick_sort(t_stack *stack);

/*cmd*/
int		ps_cmd_sab(t_stack *stack, t_cmd_stack *cmd_stack);
int		ps_cmd_pab(t_stack *from, t_stack *to, t_cmd_stack *cmd_stack);
int		ps_cmd_rab(t_stack *stack, t_cmd_stack *cmd_stack);
int		ps_cmd_rrab(t_stack *stack, t_cmd_stack *cmd_stack);

/*set utils*/
int		ps_set_a_stack(t_stack *stack, int argc, char *argv[]);
int		ps_set_b_stack(t_stack *stack);
void	ps_set_cmd_stack(t_cmd_stack *stack);

/*small mass utils*/
void	ps_sort_small_mass(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack);
void	ps_sort_small_mass2(t_stack *a, t_cmd_stack *cmd_stack);
void	ps_sort_small_mass3(t_stack *a, t_cmd_stack *cmd_stack);

/*extra utils*/
int		ps_is_valid_input(int *set, int len);
void	ps_error();


/*push swap*/

int		divide_to_three_mass(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int piv[2]);
int		ps_sort_mass(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int piv);
int		ps_sort_mass_rotate(t_stack *a, t_cmd_stack *cmd_stack, int num, int cnt);
int		ps_is_right_top(t_stack *a, int num);
int		ps_final_rotate(t_stack *a, t_cmd_stack *cmd_stack, int *set);
int		ps_rotate_bstack(t_stack *b, int num, t_cmd_stack *cmd_stack);

/*ps position cnt*/
int		ps_get_stack_cnt_func(t_stack *stack, int num, int (fp)(t_stack *, int));
int		ps_cnt_position_astack(t_stack *a, int num);
int		ps_cnt_position_bstack(t_stack *a, int num);

/*ps check rotate way*/
int		ps_rotate_same_way(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int cnt[2]);
int		ps_check_rotate_way(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int data);
void	ps_rotate_rab(t_stack *a, t_cmd_stack *cmd_stack, int cnt);
void	ps_rotate_rrab(t_stack *a, t_cmd_stack *cmd_stack, int cnt);



int		check_print_cmd(t_cmd_stack *cmd_stack);



/*  */
int			ps_insert_cmd(enum e_command cmd, enum e_stack stack, t_cmd_stack *cmd_stack);
int			ps_push_cmd_stack(enum e_command cmd, t_cmd_ab_stack *ab);
t_cmd_list	*ps_pop_cmd_stack(enum e_command cmd, t_cmd_ab_stack *ab);
t_cmd_list *ps_pop_bottom_cmd_stack(t_cmd_ab_stack *ab);
int			check_cmd(enum e_command cmd, enum e_stack stack, t_cmd_stack *cmd_stack);
int			ps_check_combine_cmd(enum e_command a_cmd, enum e_command b_cmd);
int			ps_print_cmd(enum e_command cmd);




int		print_ab_stack(t_stack *stack1, t_stack *stack2); // 디버깅용 마지막에 삭제하기
int		print_stack(t_stack *stack); // 마지막에 삭제하기

#endif