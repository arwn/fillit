/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:01:30 by awindham          #+#    #+#             */
/*   Updated: 2018/12/12 16:24:52 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 545

/*
** The files will be small enough to load completely into memory so we do this
** and return a linked list containing each tetromino in order. The funcions
** here should be called in the order listed
*/

/*
** function reads the file into memory to be passed to the piece generator
** the file should never be larger than MAX_FILE_SIZE because each piece is a 5x4
** with a newline after. ((5 * 4) * 26) + 25 newlines == 545
*/
char		*file_consume(char *path)
{
	int		fd;
	char	*ret;

	if ((fd = open(path, O_RDONLY)) < 0)
		return ("error: cant open file");
	if (ret = malloc(MAX_FILE_SIZE * sizeof(*ret)) == 0)
		return ("error: could not alloc ret");
	if ((read(fd, ret, MAX_FILE_SIZE)) < MAX_FILE_SIZE ||
			read(fd, 0, MAX_FILE_SIZE))
		return ("error: file too big");
	return (ret);
}
