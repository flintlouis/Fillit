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

char		**malloc_grid(int size_sqrt)
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

char		**ft_grid(int size)
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

static int	validity_check(int x, int mod)
{
	int	r;

	r = x / mod;
	if (x % mod == 0 && (r == 1 || r == 2 || r == 4 || r == 8 || r == 16 ||
		r == 32 || r == 64 || r == 128 || r == 256 || r == 512 || r == 1024 ||
		r == 4096))
		return (1);
	return (0);
}

char		*ft_tetrimino(int x)
{
	char *result;

	result = NULL;
	result = validity_check(x, 15) ? ft_strdup("####") : result;
	result = validity_check(x, 23) ? ft_strdup("###\n#") : result;
	result = validity_check(x, 39) ? ft_strdup("###\n #") : result;
	result = validity_check(x, 51) ? ft_strdup("##\n##") : result;
	result = validity_check(x, 54) ? ft_strdup(" ##\n##") : result;
	result = validity_check(x, 71) ? ft_strdup("###\n  #") : result;
	result = validity_check(x, 99) ? ft_strdup("##\n ##") : result;
	result = validity_check(x, 113) ? ft_strdup("#\n###") : result;
	result = validity_check(x, 114) ? ft_strdup(" #\n###") : result;
	result = validity_check(x, 116) ? ft_strdup("  #\n###") : result;
	result = validity_check(x, 275) ? ft_strdup("##\n#\n#") : result;
	result = validity_check(x, 305) ? ft_strdup("#\n##\n#") : result;
	result = validity_check(x, 306) ? ft_strdup(" #\n##\n#") : result;
	result = validity_check(x, 547) ? ft_strdup("##\n #\n #") : result;
	result = validity_check(x, 561) ? ft_strdup("#\n##\n #") : result;
	result = validity_check(x, 562) ? ft_strdup(" #\n##\n #") : result;
	result = validity_check(x, 785) ? ft_strdup("#\n#\n##") : result;
	result = validity_check(x, 802) ? ft_strdup(" #\n #\n##") : result;
	result = validity_check(x, 4369) ? ft_strdup("#\n#\n#\n#") : result;
	if (!result)
		ft_error();
	return (result);
}

int			input_to_int(int fd, int *result, int *sum)
{
	int		i;
	int		j;
	char	buf[21];

	*sum = 0;
	i = 0;
	j = 0;
	*result = read(fd, buf, 21);
	buf[*result] = '\0';
	while (buf[i])
	{
		if (i == 19 && buf[i] == '\n')
			return (*sum == 0 ? ft_error() : *sum);
		if ((buf[i] == '#' || buf[i] == '.') && (i % 5) != 4)
		{
			if (buf[i] == '#')
				*sum += ft_power(2, j);
			j++;
		}
		else if (!(buf[i] == '\n' && (i % 5) == 4))
			ft_error();
		i++;
	}
	return (*result > 0 ? ft_error() : 0);
}
