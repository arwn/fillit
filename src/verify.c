/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:45:38 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/19 11:34:14 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_fillit.h>
#include <string.h>

static int	verify_block(char *str)
{
	int hash;
	int dot;
	int nl;
	int i;

	hash = 0;
	dot = 0;
	nl = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '\n')
			nl++;
		if (str[i] == '.')
			dot++;
		if (str[i]== '#')
			hash++;
		i++;
	}
	return (hash == 4 && dot == 12 && nl == 4);
}

static int	verify_adjacent(char **piece, int x, int y)
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

static int	verify_piece(char **piece)
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

char		**verify_tetrimino(char *str)
{
	char **map;

	map = NULL;
	if (verify_block(str))
	{
		map = ft_strsplit(str, '\n');
		if (verify_piece(map))
			return (map);
	}
	ft_strdel(map);
	return (NULL);
}