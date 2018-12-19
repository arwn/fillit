/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:28:31 by awindham          #+#    #+#             */
/*   Updated: 2018/12/18 16:40:49 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include "libft.h"
#include <stdlib.h>

t_etromino	*list_new(char *content)
{
	t_etromino	*big_boyo;

	if ((big_boyo = malloc(sizeof(*big_boyo))) == 0)
		return (NULL);
	if (content == 0)
	{
		big_boyo->data = 0;
	}
	else
	{
		 big_boyo->data = ft_strsplit(content, '\n');
	}
	big_boyo->next = 0;
	return (big_boyo);
}
