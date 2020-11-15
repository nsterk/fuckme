# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nsterk <nsterk@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/15 00:06:19 by nsterk        #+#    #+#                  #
#    Updated: 2020/11/15 01:45:51 by nsterk        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fuckme
SRC = fuckme.c $(PATH_LIBFT)/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -lcriterion

all: libft $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJ)

libft:
	$(MAKE) -C $(PATH_LIBFT) re

re: fclean all