/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:01:49 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/23 16:41:44 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*recursivestore(t_file *f, t_data *ls)
{
	t_file	*file;

	file = f;
	while (file)
	{
		if (S_ISDIR(file->stat.st_mode) && !file->child \
		&& !(ls->flags->a && is_ls_hidden(file->name)))
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

t_file		*storechildren(t_file *file, char *dirname, t_flags *flags)
{
	DIR				*odir;
	t_file			*h;
	struct dirent	*entry;

	file->child = (file->child) ? NULL : initfile();
	h = file->child;
	if (!(odir = opendir(dirname)))
		ls_error(dirname, ERRNO);
	while ((entry = readdir(odir)))
	{
		if ((entry->d_name[0] != '.' && flags->a == 0) || flags->a == 1)
		{
			file->child->name = ft_strdup(entry->d_name);
			file->child = addfile(file->child);
		}
	}
	closedir(odir);
	return (h);
}

void		storeflags(t_data *ls, char *av)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if (av[i] == 'l')
			ls->flags->l = 1;
		else if (av[i] == 'R')
			ls->flags->cr = 1;
		else if (av[i] == 'a')
			ls->flags->a = 1;
		else if (av[i] == 'r')
			ls->flags->r = 1;
		else if (av[i] == 't')
			ls->flags->t = 1;
		else
		{
			ft_putstr_fd("ft_ls: illegal option -- ", 2);
			ft_putchar_fd(av[i], 2);
			ft_putchar_fd('\n', 2);
			ft_putendl_fd("usage: ft_ls [-alRrt] [file ...]", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void		storecnt(t_data *ls, char **av, int x, int ac)
{
	ls->dcnt = 0;
	ls->flags = initflags();
	if (ac == 1)
		return ;
	while (av[x] && av[x][0] == '-')
		storeflags(ls, av[x++] + 1);
	while (av[x])
	{
		ls->dcnt++;
		x++;
	}
}

t_file		*storestuff(char **av, t_data *ls, int x)
{
	t_file	*h;

	h = ls->file;
	while (av[x] || ls->dcnt == 0)
	{
		FILE->name = ls->dcnt == 0 ? ft_strdup(".\0") : ft_strdup(av[x]);
		FILE->child = storechildren(FILE, ls->dcnt == 0 ? "." : av[x], ls->flags);
		getps(ls->file, ls);
		if (ls->dcnt == 0 || !av[x+1])
			break ;
		FILE = addfile(FILE);
		x++;
	}
	ls_sort(ls->dcnt <= 1 ? &h->child : &h, ls->flags);
	return (h);
}
