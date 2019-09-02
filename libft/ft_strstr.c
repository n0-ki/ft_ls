/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:47:57 by nolakim           #+#    #+#             */
/*   Updated: 2019/02/23 03:48:05 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (*s1)
	{
		while (*(s1 + i) == s2[i] && s2[i])
			i++;
		if (!s2[i])
			return ((char *)s1);
		i = 0;
		s1++;
	}
	return (NULL);
}
