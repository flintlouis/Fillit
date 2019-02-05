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
#include <unistd.h>

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
	int 		x;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	tetriminos = create_list_of_tetriminos(fd);
	tetrimino_to_ABC(tetriminos);

	i = 0;
	while(tetriminos[i])
		printf("%s\n\n", tetriminos[i++]);
	grid = ft_grid(1);
	//printgrid
	i = 0;
	write(1, "\n\n\n", 3);
	while (grid[i] != 0)
	{
		printf("%s", grid[i]);
		i++;
	}
	//
	i = 0;
	x = 0;
	while (tetriminos[i])
	{
		if (check_pieces(grid, tetriminos[i], 0, x))
		{
			place_pieces(grid, tetriminos[i], 0, x);
			i++;
		}
		else
			x++;
	}
	ft_putnbr(check_pieces(grid, tetriminos[1], 0, 0));
	ft_putnbr(check_pieces(grid, tetriminos[2], 0, 0));
	free(grid);
	return (0);
}
