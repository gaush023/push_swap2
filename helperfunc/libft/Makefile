# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 00:17:25 by sagemura          #+#    #+#              #
#    Updated: 2023/10/23 14:17:25 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS =       ft_memcpy.c     ft_strchr.c  ft_putendl_fd.c  \
ft_atoi.c       ft_isnum.c      ft_split.c      ft_strlen.c  ft_strcmp.c 

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