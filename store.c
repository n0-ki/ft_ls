/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:01:49 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/15 22:26:51 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* void	getps(t_file *h)
{
	t_file	*file;
	t_file	*child;

	file = h;
	while (file)
	{
		if (!file->path)
			file->path = ft_strjoin(file->name, "/");
		else if (file->path)
		{
			file->path = ft_strjoin(file->path, file->name);
			file->path = ft_strjoin(file->path, "/");
		}
		ft_bzero(&file->stat, sizeof(struct stat));
		lstat(file->path, &file->stat);
		if (file->child)
			getps(file->child);
		file = file->next;
	}
}*/

void		getps(t_file *h, t_data *ls)
{
	t_file	*file;
	t_file	*child;

	file = h;
	child = file->child;
	if (!file->path && file->name)
		file->path = ft_strjoin(file->name, "/");
	else if (file->path)
		file->path = ft_strjoin(file->path, "/");
	ft_bzero(&file->stat, sizeof(struct stat));
	lstat(file->path, &file->stat);
	while (child)
	{
		if (!child->path)
			child->path = ft_strjoin(file->path, child->name);
		ft_bzero(&child->stat, sizeof(struct stat));
		lstat(child->path, &child->stat);
		if (child->child)
			getps(child->child, ls);
		child = child->next;
	}
}

t_file	*storechildren(t_file *file, char *dirname, t_flags *flags)
{
	DIR				*odir;
	t_file			*h;
	struct dirent	*entry;

	if (!file->child)
		file->child = initfile();
	h = file->child;
	if (!(odir = opendir(dirname)))
	{
		if (flags->cr == 0)
			exit(1);
		else
			return (NULL);
	}
	while ((entry = readdir(odir)))
	{
		if ((entry->d_name[0] != '.' && flags->a == 0) || flags->a == 1)
			file->child->name = ft_strdup(entry->d_name);
		file->child->next = initfile();
		file->child = file->child->next;
	}
	closedir(odir);
	return (h);
}

void	storeflags(t_data *ls, char *av)
{
	int	i;

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
		//else if (av)
		//	exit(1);
		i++;
	}
}

void	storecnt(t_data *ls, char **av, int x, int ac)
{
	ls->dcnt = 0;
	ls->flags = initflags();
	if (ac == 1)
		return ;
	while (av[x] && av[x][0] == '-')
	{
		storeflags(ls, av[x++]);
	}
	while (av[x])
	{
		ls->dcnt++;
		x++;
	}
}

t_file	*storestuff(char **av, t_data *ls, int x)
{
	t_file		*h;

	FILE = initfile();
	h = ls->file;
	while (av[x] || ls->dcnt == 0)
	{
		FILE->name = ls->dcnt == 0 ? "." : ft_strdup(av[x]);
		FILE->child = storechildren(FILE, ls->dcnt == 0 ? "." :\
		av[x], ls->flags);
		getps(ls->file, ls);
		FILE->next = initfile();
		FILE = FILE->next;
		if (ls->dcnt == 0)
			break ;
		x++;
	}
	ls_sort(&h, ls->flags);
	return (h);
}
