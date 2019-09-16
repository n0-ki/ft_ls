/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:26:04 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/15 23:25:34 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_print(t_file *file, t_data *ls)
{
	//int		l;
	
	if (ls->flags->l == 1)
		return(lsl(file->child, ls));
	//l = ls_max_namelen(file);
	while (file)
	{
		ft_putendl(file->name);
		file = file->next;
	}
}

void		ls_print_recurs(t_file *file, t_data *ls)
{
	t_file			*tmp;

	(ls->flags->l == 1) ? lsl(file, ls) : ls_print(file, ls);
	tmp = file;
	while (tmp)
	{
		if (S_ISDIR(tmp->stat.st_mode) && !(tmp->name[0] == '.' && ls->flags->a && is_ls_hidden(tmp->name)))
		{
			ft_putchar('\n');
			ft_putstr(tmp->path);
			ft_putstr(":\n");
		}
		if (tmp->child)
			ls_print_recurs(tmp->child, ls);
		tmp = tmp->next;
	}
}

int			main(int ac, char **av)
{
	int		x;
	t_data	*ls;
	
	ls = (t_data *)malloc(sizeof(t_data));
	storecnt(ls, av, ac > 1 ? 1 : 0, ac);
	ls->flg = 0;
	x = ac - ls->dcnt;
	ls->file = storestuff(av, ls, x);
	if (ls->flags->cr == 1)
	{
		recursivestore(ls->file, ls);
		ls_print_recurs(ls->file, ls);
		exit(1);
	}
	while (FILE)
	{
		ls->dcnt > 1 ? ft_putstr(FILE->path) : 0;
		ls->dcnt > 1 ? ft_putendl(":") : 0;
		ls_print(ls->flags->l == 1 ? FILE : FILE->child, ls);
		FILE = FILE->next;
	}
}
/*Error management
- non-existent file / directory
- inaccessible file / directory
- option not managed or nonexistent 
- correct display of symbolic links.*/

//every time you finish storing everything in a directory, print
