/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ssturken <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 16:16:51 by ssturken      #+#    #+#                 */
/*   Updated: 2019/01/30 16:58:28 by ssturken      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	**malloc_grid(int size_sqrt)
{
	int		i;
	char	**grid;

	i = 0;
	grid = (char**)malloc(sizeof(char*) * (size_sqrt + 1));
	while (i < size_sqrt)
	{
		grid[i] = (char*)malloc(sizeof(char) * (size_sqrt + 2));
		i++;
	}
	grid[i] = (char*)malloc(sizeof(char) * 1);
	return (grid);
}

char	**ft_grid(int size)
{
	int		size_sqrt;
	int		i;
	int		j;
	char	**grid;

	i = 0;
	j = 0;
	size_sqrt = ft_fillitsqrt(size * 4);
	grid = malloc_grid(size_sqrt);
	while (i < size_sqrt)
	{
		while (j < size_sqrt)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\n';
		j++;
		grid[i][j] = '\0';
		j = 0;
		i++;
	}
	grid[i] = NULL;
	return (grid);
}

char	*ft_tetrimino(int x)
{
	char *result;

	result = NULL;
	result = x % 15 == 0 ? ft_strdup("####") : result;
	result = x % 23 == 0 ? ft_strdup("###\n#") : result;
	result = x % 39 == 0 ? ft_strdup("###\n #") : result;
	result = x % 51 == 0 ? ft_strdup("##\n##") : result;
	result = x % 54 == 0 ? ft_strdup(" ##\n##") : result;
	result = x % 71 == 0 ? ft_strdup("###\n  #") : result;
	result = x % 99 == 0 ? ft_strdup("##\n ##") : result;
	result = x % 113 == 0 ? ft_strdup("#\n###") : result;
	result = x % 114 == 0 ? ft_strdup(" #\n###") : result;
	result = x % 116 == 0 ? ft_strdup("  #\n###") : result;
	result = x % 275 == 0 ? ft_strdup("##\n#\n#") : result;
	result = x % 305 == 0 ? ft_strdup("#\n##\n#") : result;
	result = x % 306 == 0 ? ft_strdup(" #\n##\n#") : result;
	result = x % 547 == 0 ? ft_strdup("##\n #\n #") : result;
	result = x % 561 == 0 ? ft_strdup("#\n##\n #") : result;
	result = x % 562 == 0 ? ft_strdup(" #\n##\n #") : result;
	result = x % 785 == 0 ? ft_strdup("#\n#\n##") : result;
	result = x % 802 == 0 ? ft_strdup(" #\n #\n##") : result;
	result = x % 4369 == 0 ? ft_strdup("#\n#\n#\n#") : result;
	return (result);
}

int		input_to_int(int fd)
{
	char	*line;
	int		i;
	int		j;
	int		sum;
	int		power;

	sum = 0;
	i = 0;
	while (i < 5 && ft_get_next_line(fd, &line) > 0)
	{
		j = 0;
		if (i == 4 && (ft_strlen(line) > 0 || line[0]))
			return (-1);
		while (line[j] || (j < 4 && i != 4))
		{
			power = j + 4 * i;
			if (j > 3 || (line[j] != '.' && line[j] != '#'))
				return (-1);
			if (line[j++] == '#')  // if statement veranderen :(
				sum += ft_power(2, power);
			power++;
		}
		i++;
	}
	return (sum);
}
