/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 01:15:13 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/09 09:02:37 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	split(t_file *source, t_file **fref, t_file **bref)
{
	t_file	*fast;
	t_file	*slow;

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

t_file	*timemerge(t_file *a, t_file *b, t_flags *f, t_file *result)
{
	int		i;

	if (a == NULL || !a->name)
		return (b);
	else if (b == NULL || !b->name)
		return (a);
	if ((i = (SECSHORT)) > 0)
	{
		result = a;
		result->next = timemerge(a->next, b, f, NULL);
	}
	else if (i == 0 && (NANOSHORT) > 0)
	{
		result = a;
		result->next = timemerge(a->next, b, f, NULL);
	}
	else
	{
		result = b;
		result->next = timemerge(a, b->next, f, NULL);
	}
	return (result);
}

t_file	*alphamerge(t_file *a, t_file *b, t_flags *f, t_file *result)
{
	if (a == NULL || !(a->name))
		return (b);
	else if (b == NULL || !(b->name))
		return (a);
	if ((f->r == 1 ? ft_strcmp(b->name, a->name) : \
		ft_strcmp(a->name, b->name)) <= 0)
	{
		result = a;
		result->next = alphamerge(a->next, b, f, NULL);
	}
	else
	{
		result = b;
		result->next = alphamerge(a, b->next, f, NULL);
	}
	return (result);
}

void	ls_sort(t_file **file, t_flags *f)
{
	t_file	*h;
	t_file	*a;
	t_file	*b;

	a = NULL;
	b = NULL;
	h = *file;
	if (h == NULL || h->next == NULL)
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
	*file = f->t == 0 ? alphamerge(a, b, f, NULL) : timemerge(a, b, f, NULL);
}
