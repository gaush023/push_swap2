# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 00:17:25 by sagemura          #+#    #+#              #
#    Updated: 2024/01/05 20:31:22 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sortfunc.a
SRCS =   helper_sort.c operation.c operation_2.c operation_3.c execute_sort.c\
		 bigstacks_sort.c magic_sort_5.c magic_sort_3.c finish_bigstacks_sort.c\
		 set_stacksb.c delete_memory.c allocate_memory.c find_stack_pos.c\


OBJS = $(SRCS:.c=.o)
ALL_OBJS = $(OBJS)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(ALL_OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus