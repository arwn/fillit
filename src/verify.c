/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:45:38 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/23 17:00:43 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_fillit.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>
int		verify_block(char *s)
{
	int nl;
	int dot;
	int hash;

	nl = 0;
	dot = 0;
	hash = 0;
	while (*s)
	{
		if (*s == '\n')
			nl++;
		else if (*s == '.')
			dot++;
		else if (*s == '#')
			hash++;
		else
			return (0);
		s++;
	}
	return ((nl == 5 || nl == 4) && dot == 12 && hash == 4);
}

int		verify_tetromino(char **buf)
{
	int connectey_bois;
	int i;
	int j;

	connectey_bois = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			if (0 < j && buf[i][j] == '#' && buf[i][j - 1] == '#')
				connectey_bois++;
			if (j < 3 && buf[i][j] == '#' && buf[i][j + 1] == '#')
				connectey_bois++;
			if (0 < i && buf[i][j] == '#' && buf[i - 1][j] == '#')
				connectey_bois++;
			if (i < 3 && buf[i][j] == '#' && buf[i + 1][j] == '#')
				connectey_bois++;
			j++;
		}
		i++;
	}
	return (6 == connectey_bois || 8 == connectey_bois);
}