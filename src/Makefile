#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ssturken <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/08 16:10:52 by ssturken      #+#    #+#                  #
#    Updated: 2019/01/22 21:21:15 by ssturken      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

SRC = main.c fillit.c ft_rec.c ft_error.c

OBJ = main.o fillit.o ft_rec.o ft_error.o

all:
	@gcc -c -Wall -Wextra -Werror -I ../libft/ $(SRC)

clean:
	@/bin/rm -f $(OBJ)

re: clean all
