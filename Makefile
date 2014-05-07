# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrebierr <vrebierr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/07 12:56:40 by vrebierr          #+#    #+#              #
#    Updated: 2014/05/07 12:56:41 by vrebierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
SRC = main.c
OBJS = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra -O3 -g
LFLAGS = -L $(LDIR) -lft
LDIR = libft/
LDFLAGS = -L /usr/X11/lib -lmlx -lXext -lX11

all: $(NAME)

$(NAME):
	make -C $(LDIR)
	gcc -c $(FLAGS) $(LDFLAGS) $(SRC) -I $(LDIR)inc
	gcc -o $(NAME) $(OBJS) $(LFLAGS) $(LDFLAGS)

clean:
	make clean -C $(LDIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
