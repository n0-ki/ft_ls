/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 01:15:13 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/02 07:23:16 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	split(t_file *source, t_file **fref, t_file **bref)
{
	t_file *fast;
	t_file *slow;
	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*fref = source; 
	*bref = slow->next;
	slow->next = NULL;
}

t_file	*revmerge(t_file *a, t_file *b, t_flags *f)
{
	t_file *result = NULL;
	if (a == NULL || !(a->name))
		return (b); 
	else if (b == NULL || !(b->name)) 
		return (a);
	if (ft_strcmp(a->name, b->name) >= 0)
	{
		result = a;
        result->next = revmerge(a->next, b, f);
	}
	else
	{
		result = b;
        result->next = revmerge(a, b->next, f);
	}
	return (result);
}

t_file	*sortedmerge(t_file *a, t_file *b, t_flags *f)
{
	t_file *result = NULL;
	if (a == NULL || !(a->name))
		return (b); 
	else if (b == NULL || !(b->name)) 
		return (a);
	if (ft_strcmp(a->name, b->name) <= 0)
	{
		result = a;
        result->next = sortedmerge(a->next, b, f);
	}
	else
	{
		result = b;
        result->next = sortedmerge(a, b->next, f);
	}
	return (result);
}

void     ls_sort(t_file **file, t_flags *f)
{
	t_file	*h;
	t_file  *a;
	t_file  *b;

	a = NULL;
	b = NULL;
	h = *file;
	
	if ((h == NULL) || (h->next == NULL))
		return ;
	while (h->next && h->child && h->child->name)
	{
		ls_sort(&h->child, f);
		if (h->next)
			h = h->next;
	}
	h = *file;
	split(h, &a, &b);
	ls_sort(&a, f);
	ls_sort(&b, f);
	*file = f->r == false ? sortedmerge(a, b, f) : revmerge(a, b, f);
}
//find greater file name, then push everything back
/*
t_file      *ls_sort(t_file *file)
{
	t_file *head;
	t_file *chead;


	head = file;
	while (file)
	{
		chead = h->child;
		linksort(head);
		while (h->child)
		{
			linksort(chead);
			h->child = h->child->next;
		}
		file = h->next;
	}
	return (head);
}
void	swapnode(t_file *a, t_file *b)
{
	char	*tmp;
	tmp = a->name;
	a->name = b->name;
	b->name = tmp;
} 
*/