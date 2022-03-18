/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:20:13 by ayassir           #+#    #+#             */
/*   Updated: 2021/11/14 16:35:32 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	j;

	lensrc = ft_strlen (src);
	lendst = ft_strlen (dst);
	j = lensrc + lendst;
	if (lendst >= size)
		return (lensrc + size);
	lensrc = 0;
	while (src[lensrc] != '\0' && lendst < size - 1)
	{
		dst[lendst] = src[lensrc];
		lendst++;
		lensrc++;
	}
	dst[lendst] = '\0';
	return (j);
}
