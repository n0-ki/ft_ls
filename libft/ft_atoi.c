/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:05:00 by nolakim           #+#    #+#             */
/*   Updated: 2019/08/10 08:02:47 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned long long	nmbr;
	char				check;

	nmbr = 0;
	while ((*str < 14 && *str > 8) || *str == 32)
		str++;
	check = '+';
	if (*str == '-' || *str == '+')
	{
		check = *str;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		nmbr = nmbr * 10 + (*str - '0');
		str++;
	}
	if (nmbr > 9223372036854775807)
		return (check == '-' ? 0 : -1);
	return (check == '-' ? -nmbr : nmbr);
}
