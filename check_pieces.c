/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_pieces.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/05 16:49:01 by fhignett      #+#    #+#                 */
/*   Updated: 2019/02/05 16:49:02 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int 	clear_pieces(char **grid, char c)
{
	int y;
	int x;
	int location;

	location = -1;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == c)
			{
				if (location == -1)
				{
					printf("LOCATION: X%d, Y%d\n", x, y);
					location = ((ft_strlen(grid[y]) - 1) * y) + x;
				}
				grid[y][x] = '.';
			}
			x++;
		}
		y++;
	}
	return location;
}
int		check_pieces(char **grid, char *tetriminos, int y, int x)
{
	int i;
	int x_ph;
	int y_ph;

	x_ph = x;
	y_ph = y;
	i = 0;
	while (tetriminos[i] != '\0')
	{

		if (tetriminos[i] >= 'A' && tetriminos[i] <= 'Z')
		{
			if (grid[y][x] != '.')
			{
				printf("%s DOESNT FIT at X: %d, Y:%d Error at: X%d, Y:%d I:%d\n", tetriminos, x_ph, y_ph, x , y, i);
				return (0);
			}
			x++;
		}
		else if (tetriminos[i] == '\n')
		{
			y++;
			x = x_ph;
		}
		else if (tetriminos[i] == ' ')
		{
			x++;
		}
		if (grid[y] == NULL)
		{
			printf("THIS SHIT WILL NOT FIT\n");
			return (-1);
		}
		i++;
	}
	printf("%s FITS at X: %d, Y:%d\n", tetriminos, x_ph, y_ph);
	return (1);
}

void	place_pieces(char **grid, char *tetriminos, int y, int x)
{
	int i;
	int ph;

	i = 0;
	ph = x;
	while (tetriminos[i] != '\0')
	{
		if (tetriminos[i] >= 'A' && tetriminos[i] <= 'Z')
		{
			grid[y][x] = tetriminos[i];
			x++;
		}
		else if (tetriminos[i] == '\n')
		{
			y++;
			x = ph;
		}
		else if (tetriminos[i] == ' ')
		{
			x++;
		}
		i++;
	}
}
