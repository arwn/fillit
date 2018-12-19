/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:50:40 by zfaria            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/12/19 12:12:34 by awindham         ###   ########.fr       */
=======
/*   Updated: 2018/12/19 11:57:54 by zfaria           ###   ########.fr       */
>>>>>>> 380bd6c22d71ffc13e56b617aec82ac2c59b1882
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

enum			e_usage_types
{
	Argc,
	Open,
	Read,
	Invalid
};

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_t
{
	char		**data;
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
char			**verify_tetrimino(char *str);

/*
** ****** list ********
*/
t_etromino		*list_new(char **content);
void			list_append(t_etromino *list, char **content);

/*
** ****** map ******
*/
void			map_free(t_map *map);
t_map			*map_init(int size);
int				map_startsize(int pieces);
int				map_print(t_map *map);

#endif
