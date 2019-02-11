/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ssturken <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 17:09:22 by ssturken      #+#    #+#                 */
/*   Updated: 2019/01/30 17:09:24 by ssturken      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

int		input_to_int(int fd, int *result, int *sum);
int		ft_fillitsqrt(int nb);
int		ft_rec(char **grid, char **tetris, int i);
char	**ft_grid(int size);
char	*ft_tetrimino(int x);
int		ft_error(void);
void	ft_error_usage(void);

#endif
