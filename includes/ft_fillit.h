/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:50:40 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/18 16:08:18 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

enum usage_types{Argc};

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tetromino
{
	char				**piece;
	struct s_tetromino	*next;
}				t_etromino;

/*
** ****** verify ******
*/
int				verify_piece(char **str);
int				verify_block(char *str);
int				verify_adjacent(char **piece, int x, int y);
/*
** ****** print  ******
*/
int				print_map(char **map);

#endif
