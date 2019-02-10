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
#include <stdlib.h>
#include <unistd.h>

//	errors to fix: testwrong3a, testwrong3b, testwrong5

int			ft_fillitsqrt(int nb)
{
	int x;

	if (nb < 0)
		return (-1);
	x = 1;
	while (x * x != nb)
	{
		if (x * x > nb)
			return (x);
		x++;
	}
	return (x);
}

void		printgrid(char **grid)
{
	int i;

	i = 0;
	while (grid[i])
	{
		ft_putstr(grid[i]);
		i++;
	}
}

void		tetrimino_to_abc(char **tetriminos)
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

void		create_list_of_tetriminos(int fd, char **tetriminos)
{
	int			nbr;
	int			i;

	i = 0;
	while ((nbr = input_to_int(fd)) > 0) //while loop veranderen :(
	{
		// ft_putnbr(nbr);
		// ft_putchar('\n');
		if (i == 26)
			ft_error("4");
		tetriminos[i] = ft_tetrimino(nbr);
		i++;
	}
	if (nbr == -1 || i == 0)
		ft_error("3");
	tetriminos[i] = NULL;
	tetrimino_to_abc(tetriminos);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	**grid;
	char	*tetriminos[27];
	int 	x_y_width;

	if (argc != 2)
		ft_error("2");
	fd = open(argv[1], O_RDONLY);
	create_list_of_tetriminos(fd, tetriminos);
	i = 0;
	while (tetriminos[i])
		i++;
	grid = ft_grid(i);
	x_y_width = ft_fillitsqrt(i * 4);
	while (ft_rec(grid, tetriminos, 0) != 1)
	{
		x_y_width += 1;
		grid = ft_grid(i++);
	}
	printgrid(grid);
	free(grid);
	return (0);
}
