/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:30:56 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/16 07:10:12 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printpwgr(t_file *file)
{
	ft_putstr(getpwuid(file->stat.st_uid)->pw_name);
	ft_putstr("  ");
	ft_putstr(getgrgid(file->stat.st_gid)->gr_name);
	if (file->stat.st_size > 9)
		(file->stat.st_size > 9999 ? ft_putchar(' ') : ft_putstr("  "));
	else
		ft_putstr("\t");
	ft_putchar(' ');
	!S_ISCHR(file->stat.st_mode) || !S_ISBLK(file->stat.st_mode) ? \
	ft_putnbr(file->stat.st_size) : printspecial(file->stat);
}

void	printspecial(struct stat stat)
{
	ft_putnbr(4);
	ft_putstr(",");
	ft_putnbr(major(stat.st_rdev));
	ft_putnbr(4);
	ft_putnbr(minor(stat.st_rdev));
}

int		blockcount(t_file *f)
{
	t_file	*file;
	int		cnt;

	file = f;
	cnt = 0;
	while (file)
	{
		cnt += file->stat.st_blocks;
		file = file->next;
	}
	return (cnt);
}

void	printperms(struct stat *filestats)
{
	if (S_ISDIR(filestats->st_mode))
		ft_putstr("d");
	else if (S_ISLNK(filestats->st_mode))
		ft_putstr("l");
	else if (S_ISCHR(filestats->st_mode))
		ft_putstr("c");
	else if (S_ISBLK(filestats->st_mode))
		ft_putstr("b");
	else if (S_ISFIFO(filestats->st_mode))
		ft_putstr("p");
	else
		ft_putstr("-");
	ft_putstr((filestats->st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((filestats->st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((filestats->st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((filestats->st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((filestats->st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((filestats->st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((filestats->st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((filestats->st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((filestats->st_mode & S_IXOTH) ? "x" : "-");
	ft_putstr("  ");
}

void	lsl(t_file *h)
{
	t_file	*file;
	char	*time;

	file = h;
	if (file && file->name)
	{
		ft_putstr("total ");
		ft_putendl(ft_itoa(blockcount(file)));
	}
	while (file && file->name)
	{
		if (S_ISLNK(file->stat.st_mode))
			file->name = ft_strjoin(file->name, ft_readlink(file->path));
		time = ctime(&file->stat.st_mtime);
		time[16] = '\0';
		printperms(&file->stat);
		ft_putnbr(file->stat.st_nlink);
		ft_putchar(' ');
		printpwgr(file);
		ft_putchar(' ');
		ft_putstr(time + 4);
		ft_putchar(' ');
		ft_putendl(file->name);
		file = file->next;
	}
}
