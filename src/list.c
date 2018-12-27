/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:28:31 by awindham          #+#    #+#             */
/*   Updated: 2018/12/27 14:26:13 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include "libft.h"
#include <stdlib.h>

t_etromino	*list_new(char **content, int num)
{
	t_etromino	*newl;
	t_piece		*piece;

	if ((newl = malloc(sizeof(*newl))) == 0)
		return (NULL);
	if ((piece = malloc(sizeof(*piece))) == 0)
		return (NULL);
	piece->data = content;
	piece->id = num;
	if (content == 0)
		newl->piece = 0;
	else
		newl->piece = piece;
	newl->next = 0;
	return (newl);
}

void		list_append(t_etromino *list, char **content, int num)
{
	t_etromino	*append;

	append = list_new(content, num);
	while (list->next)
		list = list->next;
	list->next = append;
}

void		list_iter(t_etromino *a_very_posh_lamp, void (*f)(t_piece *piece))
{
	while (a_very_posh_lamp)
	{
		f(a_very_posh_lamp->piece);
		a_very_posh_lamp = a_very_posh_lamp->next;
	}
}

int			list_len(t_etromino *soup)
{
	int	owo;

	owo = 1;
	while (soup)
		(owo += 1 && (soup = soup->next));
	return (owo);
}
