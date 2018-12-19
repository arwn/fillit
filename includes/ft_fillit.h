/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:50:40 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/19 11:29:49 by zfaria           ###   ########.fr       */
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

typedef struct	s_map
{
	char		**map;
	int			size;
}				t_map;

/*
** ****** verify ******
*/
char			**verify_tetrimino(char *str);
/*
** ****** print  ******
*/
int				print_map(char **map);

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

#endif
