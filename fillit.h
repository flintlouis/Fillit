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

char	**ft_grid(int size);
char	*ft_tetrimino(int x);
int		input_to_int(int fd);
int		ft_fillitsqrt(int nb);
int		check_pieces(char **grid, char *tetriminos, int y, int x);
void	place_pieces(char **grid, char *tetriminos, int y, int x);

#endif
