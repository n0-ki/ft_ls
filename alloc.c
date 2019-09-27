/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:40:04 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/26 17:40:22 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_free_files(t_file *file)
{
	t_file	*tmp;

	while (file)
	{
		tmp = file->next;
		ft_strdel(&file->path);
		ft_strdel(&file->name);
		if (file->child)
			ls_free_files(file->child);
		free(file);
		file = tmp;
	}
	file = NULL;
}

t_file		*addfile(t_file *file)
{
	t_file	*new;

	new = initfile();
	file->next = new;
	file = file->next;
	return (file);
}

t_file		*initfile(void)
{
	t_file *f;

	if (!(f = malloc(sizeof(t_file))))
		ls_error("", MALL_ERR);
	f->child = NULL;
	f->name = NULL;
	f->path = NULL;
	f->next = NULL;
	return (f);
}

t_flags		*initflags(void)
{
	t_flags *f;

	if (!(f = (t_flags *)malloc(sizeof(t_flags))))
		ls_error("", MALL_ERR);
	f->l = 0;
	f->r = 0;
	f->cr = 0;
	f->a = 0;
	f->t = 0;
	return (f);
}
