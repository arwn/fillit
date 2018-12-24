/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:12:29 by awindham          #+#    #+#             */
/*   Updated: 2018/12/23 16:37:32 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	place_tetromino(char **p, t_game_board *board, int x, int y, char l)
{
	int i;
	int j;

	i = 0;	
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			board->map[i + x][j + y] = p[i][j] == '#' ? l : '.';
			j++;
		}
		i++;
	}
}