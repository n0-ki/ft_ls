/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 20:54:01 by nolakim           #+#    #+#             */
/*   Updated: 2019/03/17 20:57:59 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*i;

	if (!lst || !(i = ft_lstnew(NULL, 0)))
		return (NULL);
	i = f(lst);
	head = i;
	while (lst->next)
	{
		lst = lst->next;
		i->next = f(lst);
		i = i->next;
	}
	return (head);
}
