/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 00:12:03 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/05/22 00:12:04 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	d;

	i = 0;
	d = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return ((char*)&s[i]);
		i++;
	}
	if (s[i] == d)
		return ((char*)&s[i]);
	return (0);
}
