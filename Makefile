# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 00:17:25 by sagemura          #+#    #+#              #
#    Updated: 2023/11/22 15:40:24 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HELPERFUNCNAME = helperfunc.a


SRCS =   main.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
HELPERFUNCDIR = ./helperfunc
LIBFTDIR = ./helperfunc/libft
SORTFUNCDIR = ./helperfunc/sortfunc

LIBFT = $(LIBFTDIR)/libft.a
SORTFUNCNAME = $(SORTFUNCDIR)/sortfunc.a

all: $(NAME)

makehelperfunc:
	make -C $(HELPERFUNCDIR)
	cp $(HELPERFUNCDIR)/$(HELPERFUNCNAME) .
	mv $(HELPERFUNCNAME) $(NAME)

$(NAME):makehelperfunc $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(HELPERFUNCDIR)/$(HELPERFUNCNAME) $(LIBFT) $(SORTFUNCNAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)
	cd $(HELPERFUNCDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(HELPERFUNCDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re bonus