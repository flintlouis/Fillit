/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ssturken <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/10 20:31:37 by ssturken      #+#    #+#                 */
/*   Updated: 2019/02/10 20:31:38 by ssturken      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>

int		ft_error(void)
{
	ft_putendl("error");
	exit(0);
	return (-1);
}

void	ft_error_usage(void)
{
	ft_putendl("usage: ./fillit file_name");
	exit(0);
}
