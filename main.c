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

void tetrimino_to_abc(char **tetriminos)
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
	tetrimino_to_abc(tetriminos);
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
	int 		z;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	tetriminos = create_list_of_tetriminos(fd);
	tetrimino_to_abc(tetriminos);

	i = 0;
	while(tetriminos[i])
		printf("%s\n\n", tetriminos[i++]);
	grid = ft_grid(i);
	x_y_grid = ft_fillitsqrt(i * 4);

	i = 0;
	x = 0;
	y = 0;
	// while (grid[y])
	// {
	// 	printf("%s", grid[y]);
	// 	y++;
	// }
	// y = 0;
	// ft_putnbr(rec_check_pieces(grid, tetriminos, y, x));
	while (tetriminos[i])
	{
		if (check_pieces(grid, tetriminos[i], y, x) == 1)
		{
			place_pieces(grid, tetriminos[i], y, x);
			ft_printgrid(grid);
			x = 0;
			y = 0;
			i++;
		}
		else if (check_pieces(grid, tetriminos[i], y, x) == -1)
		{
			printf("THIS SHIT DIDNT FIT\n");
			i -= 1;
			ft_printgrid(grid);
			printf("A CLEAAAAAAR %d, %c\n", z = clear_pieces(grid, (i + 30 + '#')), i + 30 + '#');
			ft_printgrid(grid);
			if (z == -1)
			{
				printf("Z IS -1\n");
				printf("x_y_grid: %d\n", x_y_grid);
				x_y_grid += 1;
				grid = ft_grid((x_y_grid * x_y_grid) / 4);
				printf("x_y_grid: %d\n", x_y_grid);
				ft_printgrid(grid);
				x = 0;
				y = 0;
				i = 0;
				getchar();
			}
			//ft_printgrid(grid);
			//x_y_grid += 1;
			//grid = ft_grid(x_y_grid);
			//getchar();
			else
			{
				z += 1;
				x = z % x_y_grid;
				y = z / x_y_grid;
			}
		}
		else
		{
			x++;
			if (x > x_y_grid)
			{
				printf("X_Y_GRID: %d X:%d\n", x_y_grid, x);
				x = 0;
				y++;
				printf("X_Y_GRID: %d Y:%d\n", x_y_grid, y);
				if (y == x_y_grid)
				{
					i -= 1;
					ft_printgrid(grid);
					printf("B CLEAAAAAAR %d, %c\n", z = clear_pieces(grid, (i + 30 + '#')), i + 30 + '#');
					ft_printgrid(grid);
					if (z == -1)
					{
						printf("Z IS -1\n");
						x_y_grid += 1;
						grid = ft_grid(x_y_grid);
						x = 0;
						y = 0;
						i = 0;
						getchar();
					}
					else
					{
						z += 1;
						x = z % x_y_grid;
						y = z / x_y_grid;
					}
				}
			}
		}
	}
	return (0);
}
