/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 01:12:44 by nolakim           #+#    #+#             */
/*   Updated: 2019/03/07 02:18:32 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*t;

	if (!s)
		return (NULL);
	while (*s && ft_iswspace(*s))
		s++;
	i = ft_strlen(s) - 1;
	while (*s && ft_iswspace(s[i]))
		i--;
	if (!(t = ft_strnew(i + 1)))
		return (NULL);
	ft_strncpy(t, s, i + 1);
	return (t);
}
