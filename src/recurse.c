/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:56:43 by awindham          #+#    #+#             */
/*   Updated: 2018/12/27 11:26:49 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_fillit.h>

t_game_board	*recurse(t_etromino *list, t_game_board *board)
{
	int				i;
	t_point			*point;
	t_etromino		*begin;

	begin = list;
	i = 0;
	while (list)
	{
		point = place_getpoint(list->data, board);
		if (!point)
		{
			map_clear(board);
			board->size++;
			return (recurse(begin, board));
		}
		place_piece(list->data, board, point, i + 'A');
		i++;
		list = list->next;
	}
	return (board);
}