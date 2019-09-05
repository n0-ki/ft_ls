/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:01:49 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/04 10:21:54 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*initfile(void)
{
	t_file *f;
	
	if (!(f = (t_file *)malloc(sizeof(t_file))))
		exit(-1);
	f->child = NULL;
	f->next = NULL;

	return (f);
}

void	getpath(t_file **h)
{
	t_file *parent;
	t_file *child;
	char	*tmp;

	parent = *h;
	while (parent)
	{
		child = parent->child;
		parent->path = ft_strjoin(parent->name, "/");
		while (child)
		{
			child->path = ft_strjoin(parent->path, child->name);
			child = child->next;
		}
		parent = parent->next;
	}
}

t_file		*storechildren(t_file *file, char *av, t_flags *flags)
{
	DIR		*odir;
	t_file	*h;
	struct dirent *entry;

	file->child = initfile();
	h = file->child;
	if (!(odir = opendir(av)))
		exit(1);
	while ((entry = readdir(odir)))
	{
		if ((entry->d_name[0] != '.' && flags->a == false) || flags->a == true)
			file->child->name = ft_strdup(entry->d_name);
		file->child->next = initfile();
		file->child = file->child->next;
	}
	closedir(odir);
	file->child->next = initfile();
	return (h);
}

void	storeflags(t_data *ls, char *av)
{
	int i;
	
	i = 0;
	while (av[i])
	{
		if (av[i] == 'l')
			ls->flags->l = true;
		else if (av[i] == 'R')
			ls->flags->cr = true;
		else if (av[i] == 'a')
			ls->flags->a = true;
		else if (av[i] == 'r')
			ls->flags->r = true;
		else if (av[i] == 't')
			ls->flags->t = true;
	//	else
		//usage:
		i++;
	}
}

t_file	*storestuff(char **av, t_data *ls, int x)
{
	t_file	*h;
	
	ls->flags = malloc(sizeof(t_flags));
	while (av[x][0] == '-')
	{
		storeflags(ls, av[x]);
		x++;
	}
	FILE = initfile();
	h = ls->file;
	while (av[x])
	{
		FILE->name = ft_strdup(av[x]);
		FILE->child = storechildren(FILE, av[x], ls->flags);
		FILE->next = initfile();
		FILE = FILE->next;
		x++;
	}
	getpath(&h);
	ls_sort(&h, ls->flags);
	return (h);
}
//get flags + verify them
//get path, run through lstat, sortby time