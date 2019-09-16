/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 07:12:17 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/15 23:16:01 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			is_ls_hidden(char *s)
{
	return ((s[0] == '.' && s[1] == '\0') || \
	(s[0] == '.' && s[1] == '.' && s[2] == '\0'));
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

t_file	*recursivestore(t_file *f, t_data *ls)
{
	t_file	*file;

	file = f;
	while (file)
	{
		if (S_ISDIR(file->stat.st_mode) && !file->child && !(ls->flags->a && is_ls_hidden(file->name)))
		{
			file->child = storechildren(file, file->path, ls->flags);
			getps(file, ls);
			ls_sort(&file->child, ls->flags);
		}
		if (file->child)
			file->child = recursivestore(file->child, ls);
		file = file->next;
	}
	return (f);
}

t_file		*initfile(void)
{
	t_file *f;
	
	if (!(f = (t_file *)malloc(sizeof(t_file))))
		exit(-1);
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
	f->l = 0;
	f->r = 0;
	f->cr = 0;
	f->a = 0;
	f->t = 0;
	return (f);
}