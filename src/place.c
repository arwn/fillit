/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:12:29 by awindham          #+#    #+#             */
/*   Updated: 2018/12/26 11:47:28 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	place_piece(char **p, t_game_board *board, t_point *t, char l)
{
	int i;
	int j;

	i = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			board->map[i + t->x][j + t->y] = p[i][j] == '#' ? l : '.';
			j++;
		}
		i++;
	}
}
