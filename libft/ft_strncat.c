/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:29:00 by nolakim           #+#    #+#             */
/*   Updated: 2019/03/02 03:39:43 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t len;

	len = ft_strlen(s1);
	while (*s2 && n-- > 0)
		s1[len++] = *s2++;
	s1[len] = '\0';
	return (s1);
}
