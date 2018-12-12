/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:45:38 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/11 13:14:47 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_fillit.h>

int	verify_piece(char **piece)
{
	int x;
	int y;
	int valid;

	x = 0;
	y = 0;
	valid = 0;
	while (y <= 3)
	{
		if (piece[y][x] == '#')
		{
			valid += verify_adjacent(piece, x, y);
		}
		if (x == 3)
		{
			x = -1;
			y++;
		}
		x++;
	}
	return (valid > 5);
}

int verify_block(char *str)
{
	int hash;
	int dot;
	int nl;

	hash = 0;
	dot = 0;
	nl = 0;
	while (*str)
	{
		if (*str == '\n')
			nl++;
		if (*str == '.')
			dot++;
		if (*str == '#')
			hash++;
		str++;
	}
	return (hash == 4 && dot == 12 && nl == 4);
}

int	verify_adjacent(char **piece, int x, int y)
{
	int valid;

	valid = 0;
	if (y > 0)
		if (piece[y - 1][x] == '#')
			valid++;
	if (y < 3)
		if (piece[y + 1][x] == '#')
			valid++;
	if (x > 0)
		if (piece[y][x - 1] == '#')
			valid++;
	if (x < 3)
		if (piece[y][x + 1] == '#')
			valid++;
	return (valid);
}
