/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 07:12:17 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/23 17:12:41 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void		ls_free_files(t_file *file)
{

	while (file)
	{
		ft_strdel(&file->path);
		file->name && file->name[0] != '\0' ? ft_strdel(&file->name) : 0;
		file->name = NULL;
		file->path = NULL;
		if (file->child != NULL)
			ls_free_files(file->child);
		free(file);
		file = file->next;
	}
}

t_file		*addfile(t_file *file)
{
	t_file	*new;

	new = initfile();
	file->next = new;
	file = file->next;
	return (file);
}

t_file		*initfile(void)
{
	t_file *f;

	if (!(f = (t_file *)malloc(sizeof(t_file))))
		ls_error("", MALL_ERR);
	f->child = NULL;
	f->name = NULL;
	f->path = NULL;
	f->next = NULL;
	return (f);
}

t_flags		*initflags(void)
{
	t_flags *f;

	if (!(f = (t_flags *)malloc(sizeof(t_flags))))
		ls_error("", MALL_ERR);
	f->l = 0;
	f->r = 0;
	f->cr = 0;
	f->a = 0;
	f->t = 0;
	return (f);
}
