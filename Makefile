# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fhignett <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/11 12:48:37 by fhignett      #+#    #+#                  #
#    Updated: 2021/04/20 11:58:51 by flintlouis    ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OBJ = src/main.o src/fillit.o src/ft_rec.o src/ft_error.o
INCLUDES = -ILibft -Isrc

all: $(NAME)

$(NAME):
	@make -C libft/
	@make -C src/
	@gcc -o $(NAME) -Wall -Wextra -Werror -Llibft -lft $(OBJ) $(INCLUDES)

clean:
	@make -C libft/ clean
	@make -C src/ clean

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
