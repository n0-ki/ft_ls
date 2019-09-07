/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:26:04 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/07 12:50:43 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lsl(t_data ls)
{ 
	
}

void	simple_ls(t_data *ls, t_file *file, int ac)
{
	while (file)
	{
		if (file->name && ac != 1)
			ft_putstr(file->name);
		if (file->child)
		{
			ac != 1 ? ft_putstr(":\n") : 0;
			simple_ls(ls, file->child, ac);
			ft_putchar('\n');
		}
		if (!(file->child) && ac != 1)
			ft_putchar('\n');
		ac++;		
		file = file->next;
	}
}


int		main(int ac, char **av)
{
	int		x;
	t_data	*ls;
	
	ls = (t_data *)malloc(sizeof(t_data));
	storecnt(ls, av, ac > 1 ? 1 : 0, ac);
	x = ac - ls->dcnt;
	ls->file = storestuff(av, ls, x);
	ls->flags->cr == 1 ? 1+1 : simple_ls(ls, FILE, ac);
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

