/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:14:18 by ayassir           #+#    #+#             */
/*   Updated: 2021/11/09 15:20:25 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	l;
	size_t	k;

	l = 0;
	k = 0;
	if (find[0] == '\0')
		return ((char *)str);
	while (str[l] != '\0')
	{
		k = 0;
		while ((str[l] != '\0' && find[k] != '\0')
			&& (str[l] == find[k] && l < len))
		{
			l++;
			k++;
		}
		if (find[k] == '\0')
			return ((char *) &str[l - k]);
		l = l - k + 1;
	}
	return (0);
}
