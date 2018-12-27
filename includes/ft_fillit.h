/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:50:40 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/27 15:29:59 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

enum			e_usage_types
{
	Argc,
	Open,
	Read,
	Invalid_Tetromino
};

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_piece
{
	char		**data;
	char		id;
}				t_piece;

typedef struct	s_t
{
	t_piece		*piece;
	struct s_t	*next;
}				t_etromino;

typedef struct	s_game_board
{
	char		**map;
	int			size;
}				t_game_board;

/*
** ****** verify ******
*/
int				verify_tetromino(char **str);
int				verify_block(char *str);

/*
** ****** list ********
*/
t_etromino		*list_new(char **content, int num);
void			list_append(t_etromino *list, char **content, int num);
void			list_iter(t_etromino *lamp, void (*f)(t_piece *piece));
int				list_len(t_etromino *soup);

/*
** ****** map ******
*/
void			map_free(t_game_board *map);
t_game_board	*map_init(int size);
int				map_startsize(int pieces);
int				map_print(t_game_board *map);
void			map_clear(t_game_board *map);

/*
** ***** place  ******
*/
int				place_piece(t_piece *p, t_game_board *b, t_point *t);
void			place_piece_reset(t_piece *p, t_game_board *b, t_point *t);
int				place_test(t_piece *p, t_game_board *b, t_point *t);

int				recurse(t_etromino *list, t_game_board *board);
t_game_board	*solve(t_etromino *list);

/*
** ***** trim *******
*/
void			trim_tetromino(t_piece *p);

t_point			*point_create(int x, int y);

#endif
