/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:12:29 by awindham          #+#    #+#             */
/*   Updated: 2018/12/27 09:52:11 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <libft.h>

void	place_piece(char **p, t_game_board *board, t_point *t, char l)
{
	int i;
	int j;

	i = -1;
	while (p[++i])
	{
		j = -1;
		while (p[i][++j])
			board->map[i + t->x][j + t->y] = p[i][j] == '#' ? l : '.';
	}
}

int		place_test(char **p, t_game_board *board, t_point *t)
{
	int i;
	int j;

	i = -1;
	while (p[++i])
	{
		j = -1;
		while (p[i][++j])
		{
			if (board->map[t->x + i][t->y + j] != '.')
				return (0);
			if (t->x >= board->size || t->y >= board->size)
				return (0);
		}
	}
	return (1);
}

t_point	*place_getpoint(char **p, t_game_board *board)
{
	int		x;
	int		y;
	t_point *point;

	point = NULL;
	x = 0;
	y = 0;
	while (x < board->size)
	{
		point = point_create(x, y);
		if (place_test(p, board, point))
			break ;
		ft_memdel(&point);

	}
	if (!point)
	{
		board->size++;
		return (place_getpoint(p, board));
	}
	return (point);
}
