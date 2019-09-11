/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:26:04 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/11 08:49:20 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lsl(t_file  *h)
{
	t_file	*file;
	char	*time;
	
	file = h;
	ft_putstr("total ");
	ft_putstr(ft_itoa(blockcount(file->child)));
	ft_putchar('\n');
	while (file)
	{
		time = ctime(&file->stat.st_mtime);
		time[16] = '\0';
		printperms(&file->stat);
		ft_putnbr(file->stat.st_nlink);
		ft_putchar(' ');
		ft_putstr(getpwuid(file->stat.st_uid)->pw_name);
		ft_putstr("  ");
		ft_putstr(getgrgid(file->stat.st_gid)->gr_name);
		ft_putstr("  ");
		!S_ISCHR(file->stat.st_mode) || !S_ISBLK(file->stat.st_mode) ?
		ft_putnbr(file->stat.st_size) : printspecial(file->stat);
		file->stat.st_size > 9 ? ft_putchar('\t') : ft_putstr("\t\t");
		ft_putstr(time + 4);
		ft_putchar(' ');
		ft_putstr(file->name);
		ft_putchar('\n');
		file = file->next;
	}
}
void	simple_ls(t_data *ls, t_file *file)
{
	int dc;

	dc = ls->dcnt;
	while (file)
	{
		if (file->name && !(dc <= 1 && file->child != NULL))
			ft_putstr(file->name);
		if (file->child)
		{
			!(dc <= 1 && file->child != NULL) ? ft_putstr(":\n") : 0;
			ls->flags->l == 1 ? lsl(file->child) : simple_ls(ls, file->child);
			ft_putchar('\n');
		}
		if (!(file->child) && dc++ >= 0)
			ft_putchar('\n');
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
	ls->flags->cr == 1 ? 1+1 : simple_ls(ls, FILE);
}
//handle file doesnt exist and incorrect flag
//ls -l
//ls -R (recursive print)
//every time you finish storing everything in a directory, print
