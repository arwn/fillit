/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:43:57 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/11 13:15:01 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_fillit.h>

#include <stdio.h>
int		main(int argc, char **argv)
{
	argc--;
	argv++;
	char *str = "#####\n....\n....\n....\n";
	char *str2 = "....\n.##.\n.##.\n....\n";
	char *str3 = 	"....\n"
					"##..\n"
					"..##\n"
					"....\n";
	printf("%d:%d:%d\n", verify_block(str), verify_block(str2), verify_block(str3));
	printf("%d\n", verify_piece(ft_strsplit(str, '\n')));
	printf("%d\n", verify_piece(ft_strsplit(str2, '\n')));
	printf("%d\n", verify_piece(ft_strsplit(str3, '\n')));
	return (0);
}
