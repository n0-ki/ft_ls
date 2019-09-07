/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 07:12:17 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/07 12:18:16 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*initfile(void)
{
	t_file *f;
	
	if (!(f = (t_file *)malloc(sizeof(t_file))))
		exit(-1);
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
	f->l = 0;
	f->r = 0;
	f->cr = 0;
	f->a = 0;
	f->t = 0;
	return (f);
}