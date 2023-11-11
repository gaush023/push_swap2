# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 00:17:25 by sagemura          #+#    #+#              #
#    Updated: 2023/11/03 20:15:42 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = helperfunc.a
LIBFTNAME = libft.a
SORTFUNCNAME = sortfunc.a
SRCS =   free_split.c   free_stacks.c ft_check_argc.c \
ft_print_error.c ft_set_stacks.c is_sorted.c node.c node_2.c


OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft
SORTFUNCDIR = ./sortfunc

all: $(NAME)

makelibft:
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTNAME) .
	mv $(LIBFTNAME) $(NAME)

makesortfunc:
	make -C $(SORTFUNCDIR)
	cp $(SORTFUNCDIR)/$(SORTFUNCNAME) .
	mv $(SORTFUNCNAME) $(NAME)



$(NAME):makelibft makesortfunc $(OBJS)
	$(AR) rcs $@ $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) && make clean
	cd $(SORTFUNCDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean
	cd $(SORTFUNCDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re bonus