/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 01:46:28 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/16 01:51:08 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_readlink(char *path)
{
	char	buf[128];
	ssize_t len;
	ssize_t buffsize;

	buffsize = 128;
	buf[0] = ' ';
	buf[1] = '-';
	buf[2] = '>';
	buf[3] = ' ';
	if (!(len = readlink(path, &buf[4], (buffsize - 4))))
		exit(EXIT_FAILURE);
	buf[len + 4] = '\0';
	return (ft_strdup(buf));
}
