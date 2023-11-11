# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 00:17:25 by sagemura          #+#    #+#              #
#    Updated: 2023/11/07 17:07:30 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sortfunc.a
SRCS =  execute_sort.c helper_sort.c  magic_sort_3.c operation.c operation_2.c operation_3.c \
situation_three.c situation_three_type_a.c situation_three_type_b.c situation_two.c sort_bigstacks.c \
add_stacka.c finish_the_sort.c


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