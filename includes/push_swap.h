/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:00:49 by jiwolee           #+#    #+#             */
/*   Updated: 2022/08/13 20:20:05 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include	<stdlib.h>
# include	<unistd.h>
# include	"../libft/libft.h"

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
	struct s_cmd_list	*prev;
	struct s_cmd_list	*next;
}	t_cmd_list;

typedef struct s_cmd_ab_stack {
	t_cmd_list	*top;
	t_cmd_list	*bottom;
	int			len;
}	t_cmd_ab_stack;

typedef struct s_cmd_stack {
	t_cmd_ab_stack	*a;
	t_cmd_ab_stack	*b;
}	t_cmd_stack;

int			*ps_quick_sort(t_stack *stack);
int			push_swap(t_stack *a, t_stack *b, t_cmd_stack *cmd_stack, int *set);
int			push_swap_1(t_stack *a, t_stack *b, \
						t_cmd_stack *cmd_stack, int *set);
int			divide_to_three_mass(t_stack *a, t_stack *b, \
								t_cmd_stack *cmd_stack, int piv[2]);
void		ps_get_pivot(int **piv, int len, int *set);
void		ps_set_a_stack(t_stack *stack);
void		ps_set_b_stack(t_stack *stack);
void		ps_set_cmd_stack(t_cmd_stack *stack);
void		ps_error(void);
int			ps_insert_bottom_stack(t_stack *stack, int data);
void		ps_sort_small_mass(t_stack *a, t_cmd_stack *cmd_stack);
void		ps_sort_small_mass2(t_stack *a, t_cmd_stack *cmd_stack);
void		ps_sort_small_mass3(t_stack *a, t_cmd_stack *cmd_stack);
void		ps_clear_all(t_stack *a, t_stack *b, \
						t_cmd_stack *cmd_stack, int *set);
void		ps_clear_stack(t_stack *stack);
void		ps_clear_cmd_ab_stack(t_cmd_ab_stack *ab);
void		ps_free_pstr(char **pstr);
int			ps_get_min_rotate_cnt(t_stack *stack, int num);
int			ps_cnt_position_astack(t_stack *a, int num);
int			ps_cnt_position_bstack(t_stack *a, int num);
int			ps_rotate_same_way(t_stack *a, t_stack *b, \
								t_cmd_stack *cmd_stack, int cnt[2]);
int			ps_check_rotate_way(t_stack *a, t_stack *b, \
								t_cmd_stack *cmd_stack, int data);
int			ps_rotate_bstack(t_stack *b, int num, t_cmd_stack *cmd_stack);
int			ps_rotate_astack(t_stack *a, t_cmd_stack *cmd_stack, int num);
int			ps_final_rotate(t_stack *a, t_cmd_stack *cmd_stack, int *set);
int			ps_sort_mass(t_stack *a, t_stack *b, \
							t_cmd_stack *cmd_stack, int piv);
void		ps_rotate_rab(t_stack *a, t_cmd_stack *cmd_stack, int cnt);
void		ps_rotate_rrab(t_stack *a, t_cmd_stack *cmd_stack, int cnt);
void		ps_rotate_rrab_both(t_stack *a, t_stack *b, \
								t_cmd_stack *cmd_stack, int rev[2]);
void		ps_rotate_rab_both(t_stack *a, t_stack *b, \
								t_cmd_stack *cmd_stack, int cnt[2]);
int			ps_insert_stack_argv(t_stack *stack, char *argv[]);
int			ps_check_valid_num(char *str);
int			ps_check_valid_num_1(char *str, int i);
int			ps_is_already_sorted(t_stack *stack);
int			ps_check_duplicates(int *set, int len);
int			ps_cmd_sab(t_stack *stack, t_cmd_stack *cmd_stack);
int			ps_cmd_pab(t_stack *from, t_stack *to, t_cmd_stack *cmd_stack);
int			ps_cmd_rab(t_stack *stack, t_cmd_stack *cmd_stack);
int			ps_cmd_rrab(t_stack *stack, t_cmd_stack *cmd_stack);
int			ps_insert_cmd(enum e_command cmd, \
						enum e_stack stack, t_cmd_stack *cmd_stack);
int			ps_push_cmd_stack(enum e_command cmd, t_cmd_ab_stack *ab);
t_cmd_list	*ps_pop_cmd_stack(t_cmd_ab_stack *ab);
t_cmd_list	*ps_pop_bottom_cmd_stack(t_cmd_ab_stack *ab);
int			combine_cmd(t_cmd_stack *cmd_stack);
int			ps_check_combine_cmd(enum e_command a_cmd, enum e_command b_cmd);
int			ps_check_cmd(enum e_command cmd, \
						enum e_stack stack, t_cmd_stack *cmd_stack);
int			ps_check_print_cmd(t_cmd_stack *cmd_stack);
void		ps_print_cmd(enum e_command cmd);
void		ps_cmd_pop_free_one(t_cmd_stack *cmd_stack, enum e_stack stack);
void		ps_cmd_pop_free_two(t_cmd_stack *cmd_stack);
void		ps_cmd_pop_free_print_one(t_cmd_ab_stack *cmd_ab_stack);
void		ps_cmd_pop_free_print_two(t_cmd_ab_stack *a, t_cmd_ab_stack *b);
int			ps_check_delete_cmd_a(enum e_command cmd1, enum e_command cmd2);
int			ps_check_delete_cmd_b(enum e_command cmd1, enum e_command cmd2);
int			ps_check_delete_cmd_both(enum e_command cmd, \
								enum e_command cmd_a, enum e_command cmd_b);

#endif