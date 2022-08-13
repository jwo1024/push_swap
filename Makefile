# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:27:03 by jiwolee           #+#    #+#              #
#    Updated: 2022/08/13 20:05:00 by jiwolee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc -g
CFLAG	= -Wall -Wextra -Werror

HEADER	= ./includes

INCLUDES = -I$(HEADER)

LIB_DIR	= ./libft/
LIB		= $(LIB_DIR)libft.a

SRCS_1	= ./mandatory/push_swap.c \
 		  ./mandatory/ps_utils_clear.c \
		  ./mandatory/ps_utils_set.c \
		  ./mandatory/ps_is_valid_input.c \
		  \
		  ./mandatory/ps_sort_small_mass.c \
		  ./mandatory/ps_position_cnt.c \
		  \
		  ./mandatory/ps_check_rotate_way.c \
		 \
		  ./mandatory/ps_quick_sort.c \
		  ./mandatory/ps_rotate_mass.c

SRCS_2	= ./ps_cmd_utils/ps_stack_cmd.c \
		  ./ps_cmd_utils/ps_stack_cmd1.c \
		  ./ps_cmd_utils/ps_stack_cmd2.c \
		  ./ps_cmd_utils/ps_cmd_pop.c \
		  ./ps_cmd_utils/ps_cmd_check_delete.c

SRCS_3	= ./ps_libft/ps_ft_atoi.c \
		  ./ps_libft/ps_ft_split.c \
		  ./ps_libft/ps_ft_strlcpy.c \
		  ./ps_libft/ps_ft_strlen.c \
		  ./ps_libft/ps_ft_substr.c

SRCS	= $(SRCS_1) $(SRCS_2)

OBJS	= $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAG) $(INCLUDES) -c -o $@ $^

all : $(NAME)

$(LIB) :
	make all -C $(LIB_DIR)

$(NAME) : $(OBJS) $(LIB)
	$(CC) $(CFLAG) $(INCLUDES) -o $@ $^

clean :
	rm -f $(OBJS)
	make $@ -C $(LIB_DIR)

fclean : clean
	rm -f $(NAME)
	make $@ -C $(LIB_DIR)

re : fclean all

.PHONY : all clean fclean re
