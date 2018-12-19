/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:16:19 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/19 12:05:58 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <libft.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 16

void			map_free(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->size)
		ft_strdel(&(map->map[i]));
	ft_memdel((void **)&map);
}

t_map			*map_init(int size)
{
	int		i;
	t_map	*ret;

	ret = ft_memalloc(sizeof(t_map));
	ret->map = ft_memalloc(sizeof(char *) * MAX_SIZE + 1);
	ret->size = size;
	i = -1;
	while (++i < MAX_SIZE)
	{
		ret->map[i] = ft_strnew(MAX_SIZE);
		ret->map[i] = ft_memset(ret->map[i], '.', MAX_SIZE);
	}
	return (ret);
}

int				map_startsize(int pieces)
{
	pieces++;
	return (0);
}

int				map_print(t_map *map)
{
	int i;

	i = -1;
	if (map == 0)
		return (-1);
	else
	{
		while (++i < map->size)
		{
			write(1, map->map[i], map->size);
			write(1, "\n", 1);
		}
		return (0);
	}
}

