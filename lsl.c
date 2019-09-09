/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:30:56 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/09 11:32:55 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_perms(struct stat *filestats)
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
}