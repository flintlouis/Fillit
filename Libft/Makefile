#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fhignett <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/09 15:24:52 by fhignett      #+#    #+#                  #
#    Updated: 2019/02/04 17:47:53 by fhignett      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = libft.a
FILESC = ft_putnbr.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr_fd.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_bzero.c ft_memdel.c \
ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_memset.c ft_memcpy.c \
ft_memccpy.c ft_memmove.c ft_memchr.c ft_memalloc.c ft_strdup.c ft_strchr.c \
ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
ft_strncat.c ft_strnew.c ft_strmap.c ft_strmapi.c ft_strsub.c ft_strjoin.c \
ft_strtrim.c ft_itoa.c ft_strsplit.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strcmp.c \
ft_strncmp.c ft_memcmp.c ft_strequ.c ft_strnequ.c ft_strlen.c ft_strlcat.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
ft_countwords.c ft_print_byte.c ft_sort_int_tab.c ft_lstadd_back.c \
ft_strsplit_list.c ft_lstinsert.c ft_lstfold.c ft_power.c ft_get_next_line.c \
ft_sqrt.c
FILESO = $(FILESC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(FILESC)
	@ar rc $(NAME) $(FILESO)
	@ranlib $(NAME)

clean:
	@rm -f $(FILESO)

fclean: clean
	@rm -f $(NAME)

re: fclean all
