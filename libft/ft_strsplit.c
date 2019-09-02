/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 01:38:12 by nolakim           #+#    #+#             */
/*   Updated: 2019/08/10 08:10:39 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	size_t	wrdcnt;
	size_t	i;
	size_t	j;

	if (!s || !(ret = (char **)malloc(sizeof(char *) * (ft_wrdcnt(s, c) + 1))))
		return (NULL);
	wrdcnt = ft_wrdcnt(s, c);
	i = 0;
	while (i < wrdcnt)
	{
		while (*s && *s == c)
			s++;
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		if (!(ret[i] = ft_strnew(j)))
			return (NULL);
		ft_strncpy(ret[i], s, j);
		s += j;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
