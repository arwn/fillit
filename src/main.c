/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:43:57 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/27 16:07:57 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_fillit.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int	die(int type)
{
	if (type == Argc)
		ft_putendl("usage: ./fillit filename");
	if (type == Error)
		ft_putendl("error");
	exit (-1);
}

int			main(int argc, char **argv)
{
	int			fd;
	char		buf[21];
	int			bread;
	t_etromino	*tetrominos;
	int			i;

	if (argc != 2)
		die(Argc);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		die(Error);
	if (read(fd, buf, 0) < 0)
		die(Error);
	tetrominos = 0;
	i = 0;
	while ((bread = read(fd, buf, 21)))
	{
		buf[bread] = '\0';
		if (verify_tetromino(ft_strsplit(buf, '\n')) == 0)
			die(Error);
		if (verify_block(buf) == 0)
			die(Error);
		if (tetrominos == 0)
			tetrominos = list_new(ft_strsplit(buf, '\n'), i + 'A');
		else
			list_append(tetrominos, ft_strsplit(buf, '\n'), i + 'A');
		i++;
	}
	if (!tetrominos)
		die(Error);
	list_iter(tetrominos, &trim_tetromino);
	map_print(solve(tetrominos));
	close(fd);
	return (0);
}
