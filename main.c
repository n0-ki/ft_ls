/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:26:04 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/02 08:25:38 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	simple_ls(t_data *ls, t_file *file)
{
	while (file)
	{
		ft_putstr(file->name);
		if (file->child)
		{
			ft_putstr(":\n");
			simple_ls(ls, file->child);
			ft_putchar('\n');
		}
		if (file->next)
		{
			if (!(file->child))
				ft_putchar('\t');
			file = file->next;
		}
		else
		{
			ft_putchar('\n');
			return ;
		}
	}
}

int		main(int ac, char **av)
{
	int		x;
	t_data	*ls;
	
	x = 0;
	ls = (t_data *)malloc(sizeof(t_data));
	if (ac == 1)
	{
		FILE = initfile();
		FILE->name = ".";
	}
	else
		ls->file = storestuff(av, ls, 1);
	ls->flags->cr == true ? 1+1 : simple_ls(ls, FILE);
}
//sort directories & store them in linked list -- done
//ls -r (reverse directories) -- done, along with print partially. use dcnt to check if multiple directories was typed, then decide to print : based on that.
//ls -a (normal doesnt show files with . at beginning, -a does)
//ls -R (recursive print)
//every time you finish storing everything in a directory, print

/*
if ((dirp = opendir(dir)) == NULL)
	ls_error(dir, ERRNO);
else
{
	while ((entry = readdir(dirp)) != NULL)
	{
		file = (file) ? ls_add_file(file) : ls_new_file();
		file->parent = parent;
		file->name = ft_strdup(entry->d_name);
		file->path = ls_get_path(dir, file->name);
		if (!(lstat(file->path, &file->stat) == 0) && (*flags & L_FLAG))
			ls_lstat_error(file);
		if (S_ISDIR(file->stat.st_mode) && !is_ls_hidden(file->name) && \
		*flags & RR_FLAG)
			file->child = ls_init_file(file->path, file->child, flags, \
			file);
	}
	closedir(dirp);
}
return (file);
*/

