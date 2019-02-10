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

NAME = fillit

SRC = main.c fillit.c ft_rec.c ft_error.c

all: $(NAME)

$(NAME):
	@gcc -o $(NAME) -Wall -Wextra -Werror $(SRC) -LLibft -lft
clean:
	@/bin/rm -f *\~
	@/bin/rm -f \#*#

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
