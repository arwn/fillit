/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:09:34 by awindham          #+#    #+#             */
/*   Updated: 2018/12/27 14:27:12 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include "ft_fillit.h"

static	int		tetris_row_empty(char *str)
{
	int i;

	i = -1;
	while (++i < 4 && str[i] != '#')
		;
	return (i == 4);
}

static	int		tetris_col_empty(char **piece, int col)
{
	int i;
	int empty;

	i = -1;
	empty = 1;
	while (piece[++i])
	{
		if (piece[i][col] == '#')
			empty = 0;
	}
	return (empty);
}

static	void	tetris_shift_rows(char **piece, int l)
{
	while (piece[l + 1])
	{
		ft_memmove(piece[l], piece[l + 1], 4);
		l++;
	}
	piece[l] = 0;
}

static void		tetris_shift_col(char **piece, int l)
{
	int i;

	i = 0;
	while (piece[i])
	{
		ft_memmove(piece[i] + l, piece[i] + l + 1, ft_strlen(piece[i] + l));
		i++;
	}
}

void			trim_tetromino(t_piece *p)
{
	int i;
	int max;

	max = 4;
	i = 0;
	while (p->data[i])
	{
		if (tetris_row_empty(p->data[i]))
			tetris_shift_rows(p->data, i);
		else
			i++;
	}
	i = 0;
	while (p->data[0][i])
	{
		if (tetris_col_empty(p->data, i))
			tetris_shift_col(p->data, i);
		else
			i++;
	}
	i = 0;
}
