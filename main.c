/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ssturken <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 17:05:51 by ssturken      #+#    #+#                 */
/*   Updated: 2019/02/04 15:22:57 by ssturken      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

void tetrimino_to_ABC(char **tetriminos)
{
	int i;
	int j;

	i = 0;
	while (tetriminos[i])
	{
		j = 0;
		while (tetriminos[i][j])
		{
			if (tetriminos[i][j] == '#')
				tetriminos[i][j] += (30 + i);
			j++;
		}
		i++;
	}
}

char **create_list_of_tetriminos(int fd)
{
	int			nbr;
	int			i;
	static char	*tetriminos[27];

	i = 0;
	while ((nbr = input_to_int(fd)) > 0 && i < 26)
		tetriminos[i++] = ft_tetrimino(nbr);
	tetriminos[i] = NULL;
	tetrimino_to_ABC(tetriminos);
	if (nbr == -1)
		printf("INVALID FILE\n");
	return (tetriminos);
}


int	main(int argc, char **argv)
{
	int			fd;
	char		**tetriminos;
	char  		**grid;
	int 		i;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	tetriminos = create_list_of_tetriminos(fd);
	tetrimino_to_ABC(tetriminos);

	i = 0;
	while(*tetriminos)
		printf("%d\n%s\n\n", i++, *tetriminos++);
	grid = ft_grid(i + 1);
	place_pieces(grid, tetriminos);
	free(grid);
	return (0);
}
