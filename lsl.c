/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:30:56 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/11 08:49:21 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printspecial(struct stat stat)
{
	ft_putnbr(4);
	ft_putstr(",");
	ft_putnbr(major(stat.st_rdev));
	ft_putnbr(4);
	ft_putnbr(minor(stat.st_rdev));
}
int		blockcount(t_file *file)
{
	int cnt;

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