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

void	place_pieces(char **grid, char **tetriminos)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (tetriminos[i])
	{
		while (tetriminos[i][j] != '\n' && tetriminos[i][j] != '\0')
		{
			grid[i][j] = tetriminos[i][j];
			j++;
		}
	}
	i = 0;
	while (grid[i] != 0)
	{
		printf("%s", grid[i]);
		i++;
	}
}
