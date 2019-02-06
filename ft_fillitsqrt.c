/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sqrt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 19:22:23 by fhignett      #+#    #+#                 */
/*   Updated: 2019/01/08 14:51:46 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_fillitsqrt(int nb)
{
	int x;

	if (nb < 0)
		return(-1);
	x = 1;
	while (x * x != nb)
	{
		if (x * x > nb)
			return (x);
		x++;
	}
	return (x);
}
