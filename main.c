/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:26:04 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/23 17:06:21 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_print(t_file *file, t_data *ls)
{
	if (ls->flags->l == 1)
		return (lsl(file->child));
	while (file)
	{
		ft_putendl(file->name);
		file = file->next;
	}
}

void		simple_ls(t_file *file, t_data *ls)
{
	while (file)
	{
		ls->dcnt > 1 ? ft_putstr(file->path) : 0;
		ls->dcnt > 1 ? ft_putendl(":") : 0;
		ls_print(ls->flags->l == 1 ? file : file->child, ls);
		file = file->next;
	}
}

void		ls_print_recurs(t_file *file, t_data *ls, int i)
{
	t_file			*tmp;

	if (i == 1)
		(ls->flags->l == 1) ? lsl(file) : ls_print(file, ls);
	tmp = file;
	while (tmp)
	{
		if (i == 1 && S_ISDIR(tmp->stat.st_mode) && !(tmp->name[0] == '.' \
		&& ls->flags->a && is_ls_hidden(tmp->name)))
		{
			ft_putchar('\n');
			ft_putstr(tmp->path);
			ft_putstr(":\n");
		}
		if (tmp->child)
			ls_print_recurs(tmp->child, ls, 1);
		tmp = tmp->next;
	}
}

int			main(int ac, char **av)
{
	int		x;
	t_data	*ls;

	if (!(ls = (t_data *)malloc(sizeof(t_data))))
		ls_error("", MALL_ERR);
	ls->file = initfile();
	storecnt(ls, av, ac > 1 ? 1 : 0, ac);
	ls->flg = 0;
	x = ac - ls->dcnt;
	ls->file = storestuff(av, ls, x);
	if (ls->flags->cr == 1)
	{
		recursivestore(ls->file, ls);
		ls_print_recurs(ls->file, ls, 0);
		ls_free_files(ls->file);
		sleep(6);
		exit(1);
	}
	else
		simple_ls(ls->file, ls);
  	ls_free_files(ls->file);
	free(ls->flags);
	free(ls);
	sleep(6);
}
/*
**Error management
**- non-existent file / directory
**- inaccessible file / directory
**- option not managed or nonexistent
**- correct display of symbolic links.
*/
