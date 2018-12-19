/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:43:57 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/18 16:25:53 by awindham         ###   ########.fr       */
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
	int		fd;
	char	buf[21];

	if (argc != 2)
		return(die(Argc));
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return(die(Open));
	while (20 < read(fd, buf, 21))
	{
		ft_putendl("read a chunk..");
	}

/*			bullshit			*/
	#ifdef T_PRINT_MAP
		char **map = ft_strsplit("....\n##..\n.##.\n....", '\n');
		print_map(map);
	#endif
/*			bullshit			*/
	return (0);
}
