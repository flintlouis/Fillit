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

void ft_printgrid(char **grid)
{
	while (*grid != NULL)
		printf("%s", *grid++);
	printf("\n");
}

int	main(int argc, char **argv)
{
	int			fd;
	char		**tetriminos;
	char  		**grid;
	int 		x_y_grid;
	int 		i;
	int 		x;
	int			y;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	tetriminos = create_list_of_tetriminos(fd);
	tetrimino_to_ABC(tetriminos);

	i = 0;
	while(tetriminos[i])
		printf("%s\n\n", tetriminos[i++]);
	grid = ft_grid(i);
	x_y_grid = ft_fillitsqrt(i);

	i = 0;
	x = 0;
	y = 0;
	while (tetriminos[i])
	{
		if (check_pieces(grid, tetriminos[i], y, x))
		{
			place_pieces(grid, tetriminos[i], y, x);
			ft_printgrid(grid);
			i++;
		}
		else
			if (++x > x_y_grid)
			{
				x = 0;
				y++;
			}
	}
	return (0);
}
