/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:17:09 by ayassir           #+#    #+#             */
/*   Updated: 2021/11/24 22:47:09 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			j;

	j = 0;
	str = (unsigned char *) s;
	while (j < n)
	{
		if (str[j] == (unsigned char) c)
			return ((void *)str + j);
		j++;
	}
	return (NULL);
}
