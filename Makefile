# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:27:03 by jiwolee           #+#    #+#              #
#    Updated: 2022/08/12 16:07:44 by jiwolee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc -g
CFLAG	=
#CFLAG	= -Wall -Wextra -Werror

HEADER	= ./includes

INCLUDES = -I$(HEADER)

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
		  ./ps_print_stack.c 

SRCS_2	= ./ps_cmd_utils/ps_stack_cmd.c \
		  ./ps_cmd_utils/ps_stack_cmd1.c \
		  ./ps_cmd_utils/stack_command.c

SRCS_3	= ./ps_libft/ps_ft_atoi.c \
		  ./ps_libft/ps_ft_split.c \
		  ./ps_libft/ps_ft_strlcpy.c \
		  ./ps_libft/ps_ft_strlen.c \
		  ./ps_libft/ps_ft_substr.c

SRCS	= $(SRCS_1) $(SRCS_2) $(SRCS_3)

OBJS	= $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAG) $(INCLUDES) -c -o $@ $^

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(INCLUDES) -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re