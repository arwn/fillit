/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:43:57 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/18 16:47:22 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_fillit.h>
#include <unistd.h>
#include <fcntl.h>

static int	die(int type)
{
	if (type == Argc)
		ft_putendl("usage: ./fillit filename");
	if (type == Open)
		ft_putendl("Can not open file");
	return (-1);
}

#include <stdio.h>
int			main(int argc, char **argv)
{
	int			fd;
	char		buf[22];
	t_etromino	*pieces;

	if (argc != 2)
		return(die(Argc));
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return(die(Open));
	pieces = 0;
	while (20 < read(fd, buf, 21))
	{
		buf[21] = '\0';
		pieces = list_new(buf);
		for (int i = 0; pieces->data[i]; i++)
			puts(pieces->data[i]);
	}
	puts(pieces->data[0]);
	close(fd);

/*			bullshit			*/
	#ifdef T_PRINT_MAP
		char **map = ft_strsplit("....\n##..\n.##.\n....", '\n');
		print_map(map);
	#endif
/*			bullshit			*/
	return (0);
}
