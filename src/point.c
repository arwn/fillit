/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 10:10:53 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/26 10:14:57 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <libft.h>
#include <stdlib.h>

t_point	*point_create(int x, int y)
{
	t_point *ret;

	ret = (t_point *)ft_memalloc(sizeof(t_point));
	ret->x = x;
	ret->y = y;
	return (ret);
}
