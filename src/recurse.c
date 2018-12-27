/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:56:43 by awindham          #+#    #+#             */
/*   Updated: 2018/12/27 14:56:57 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_fillit.h>

int				recurse(t_etromino *list, t_game_board *board)
{
	int x;
	int y;

	if (list == NULL)
		return (1);
	y = 0;
	while (y < board->size)
	{
		x = 0;
		while (x < board->size)
		{
			if (place_piece(list->piece, board, point_create(x, y)))
			{
				if (recurse(list->next, board))
					return (1);
				else
					place_piece_force(list->piece, board, point_create(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_game_board	*solve(t_etromino *list)
{
	t_game_board	*map;
	
	map = map_init(2);
	while (!recurse(list, map))
	{
		map->size++;
		map_clear(map);
	}
	return (map);
}
