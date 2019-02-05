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

int	main(int argc, char **argv)
{
	int		fd;
	int		nbr;
	int		i;
	char	*tetriminos[27];
	char	**grid;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while ((nbr = input_to_int(fd)) > 0 && i < 26)
	{
		tetriminos[i] = ft_tetrimino(nbr);
		i++;
	}
	tetriminos[i] = NULL;
	i = 0;
	while (tetriminos[i])
	{
		printf("%d\n%s\n\n", i, tetriminos[i]);
		i++;
	}
	if (nbr == -1)
		printf("INVALID FILE\n");
	grid = ft_grid(i + 1);
	i = 0;
	while (grid[i] != 0)
	{
		printf("%s", grid[i]);
		i++;
	}
	free(grid);
	return (0);
}
