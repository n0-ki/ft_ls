/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 07:12:17 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/26 17:42:17 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			blockcount(t_file *f)
{
	t_file	*file;
	int		cnt;

	file = f;
	cnt = 0;
	while (file)
	{
		cnt += file->stat.st_blocks;
		file = file->next;
	}
	return (cnt);
}

int			is_ls_hidden(char *s)
{
	return ((s[0] == '.' && s[1] == '\0') || \
	(s[0] == '.' && s[1] == '.' && s[2] == '\0'));
}

int			ls_lstat_error(t_file *file)
{
	ls_free_files(file);
	exit(EXIT_FAILURE);
}

int			ls_error(char *s, int error)
{
	if (error == USAGE)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(*s, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ft_ls [-alRrt1] [file ...]", 2);
	}
	else if (error == ERRNO || error == MALL_ERR)
		ft_putstr_fd("ft_ls: ", 2);
	if (error == ERRNO)
	{
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		exit(EXIT_FAILURE);
	}
	else if (error == MALL_ERR)
		ft_putendl_fd(strerror(errno), 2);
	if (error == USAGE || error == MALL_ERR)
		exit(EXIT_FAILURE);
	return (0);
}
