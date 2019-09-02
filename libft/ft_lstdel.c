/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 00:10:30 by nolakim           #+#    #+#             */
/*   Updated: 2019/03/10 00:10:31 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*c;
	t_list	*n;

	c = *alst;
	while (c)
	{
		n = c->next;
		del((c->content), (c->content_size));
		free(c);
		c = n;
	}
	*alst = NULL;
}
