/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rec_check_pieces.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 12:46:49 by fhignett      #+#    #+#                 */
/*   Updated: 2019/02/06 12:46:49 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

int		rec_check_pieces(char **grid, char **tetriminos, int y, int x)
{
	int amount;
	int i;
	int ph;
	int x_y_grid;

	amount = 0;
	i = 0;
	ph = x;
	while(tetriminos[amount])
		amount++;
	x_y_grid = ft_fillitsqrt(amount * 4);
	while (tetriminos[2][i] != '\0')
	{
		if (tetriminos[2][i] >= 'A' && tetriminos[2][i] <= 'Z')
		{
			if (grid[y][x] != '.')
			{
				x++;
				if (x > x_y_grid)
				{
					x = 0;
					y++;
				}
				return (rec_check_pieces(grid, tetriminos, y, x));
			}
			x++;
		}
		else if (tetriminos[2][i] == '\n')
		{
			y++;
			x = ph;
		}
		if (grid[y] == NULL)
			return (0);
		i++;
	}
	return (1);
}
