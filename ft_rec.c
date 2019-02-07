/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rec.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 15:10:50 by fhignett      #+#    #+#                 */
/*   Updated: 2019/02/06 15:10:51 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "fillit.h"

void		remove_tetris(char **grid, char *tetris, int x, int y)
{
	int i;
	int xph;

	i = 0;
	xph = x;
	while (tetris[i] != '\0')
	{
		if (tetris[i] >= 'A' && tetris[i] <= 'Z')
		{

			grid[y][x] = '.';
			i++;
			x++;

		}
		else if (tetris[i] == '\n')
		{
			i++;
			x = xph;
			y++;
		}
		else if (tetris[i] == ' ')
		{
			i++;
			x++;
		}
	}
}

void	place_tetris(char **grid, char *tetris, int x, int y)
{
	int i;
	int xph;

	i = 0;
	xph = x;
	while (tetris[i] != '\0')
	{
		if (tetris[i] >= 'A' && tetris[i] <= 'Z')
		{
			if (grid[y][x] == '.')
			{
				grid[y][x] = tetris[i];
				i++;
				x++;
			}
		}
		else if (tetris[i] == '\n')
		{
			i++;
			x = xph;
			y++;
		}
		else if (tetris[i] == ' ')
		{
			i++;
			x++;
		}
	}
}

int		tetris_check(char **grid, char *tetris, int x, int y)
{
	int i;
	int xph;

	i = 0;
	xph = x;
	while (tetris[i] != '\0')
	{
		if (tetris[i] >= 'A' && tetris[i] <= 'Z')
		{
			if (grid[y][x] == '.')
			{
				i++;
				x++;
			}
			else
				return (-1);
		}
		else if (tetris[i] == '\n')
		{
			i++;
			x = xph;
			y++;
			if (!grid[y])
				return (-1);
		}
		else if (tetris[i] == ' ')
		{
			i++;
			x++;
		}
	}
	return (1);
}

void	xy_plus(char **grid, int *x, int *y)
{
	if (grid[*y][*x] != '\n')
		(*x)++;
	else
	{
		(*y)++;
		*x = 0;
	}
}

int		ft_rec(char **grid, char **tetris, int i)
{
	int ret;
	int x;
	int y;

	x = 0;
	y = 0;
	if (!tetris[i])
		return (1);
	while (grid[y])
	{
		ret = tetris_check(grid, tetris[i], x, y);
		if (ret == -1)
			xy_plus(grid, &x, &y);
		if (ret == 1)
		{
			place_tetris(grid, tetris[i], x, y);
			ret = ft_rec(grid, tetris, i + 1);
			if (ret == 1)
				return (1);
			else
			{
				remove_tetris(grid, tetris[i], x, y);
				xy_plus(grid, &x, &y);
			}
		}
	}
	return (-1);
}