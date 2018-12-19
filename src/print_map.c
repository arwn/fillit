/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:51:31 by awindham          #+#    #+#             */
/*   Updated: 2018/12/18 16:08:36 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_fillit.h"

/*
** prints the map of tetriminos. Assumes null termination
*/
int		print_map(char **map)
{
	if (*map == 0)
		return (-1);
	else
	{
		while (*map)
			ft_putendl(*map++);
		return (0);
	}
}
