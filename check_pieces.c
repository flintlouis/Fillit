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

int		check_pieces(char **grid, char *tetriminos, int y, int x)
{
	int i;
	int ph;

	ph = x;
	i = 0;
	while (tetriminos[i] != '\0')
	{
		if (tetriminos[i] >= 'A' && tetriminos[i] <= 'Z')
		{
			if (grid[y][x] != '.')
				return (0);
			x++;
		}
		else if (tetriminos[i] == '\n')
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

