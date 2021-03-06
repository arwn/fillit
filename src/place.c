/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:12:29 by awindham          #+#    #+#             */
/*   Updated: 2018/12/27 15:31:44 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <libft.h>
#include <stdlib.h>

int		place_piece(t_piece *p, t_game_board *board, t_point *t)
{
	int i;
	int j;

	if (!place_test(p, board, t))
		return (0);
	j = -1;
	while (p->data[++j])
	{
		i = -1;
		while (p->data[j][++i])
			if (p->data[j][i] == '#')
				board->map[j + t->y][i + t->x] = p->id;
	}
	return (1);
}

void	place_piece_reset(t_piece *p, t_game_board *board, t_point *t)
{
	int i;
	int j;

	j = -1;
	while (p->data[++j])
	{
		i = -1;
		while (p->data[j][++i])
			if (p->data[j][i] == '#')
				board->map[j + t->y][i + t->x] = '.';
	}
}

int		place_test(t_piece *p, t_game_board *board, t_point *t)
{
	int i;
	int j;

	j = -1;
	while (p->data[++j])
	{
		i = -1;
		while (p->data[j][++i])
		{
			if (board->map[t->y + j][t->x + i] != '.' && p->data[j][i] != '.')
				return (0);
			if (t->x + i >= board->size || t->y + j >= board->size)
				return (0);
		}
	}
	return (1);
}
