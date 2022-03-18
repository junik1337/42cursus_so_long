/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:19:01 by ayassir           #+#    #+#             */
/*   Updated: 2021/11/24 12:30:51 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*pdst;
	const char		*psrc;

	pdst = (char *) dst;
	psrc = (const char *) src;
	if (!dst && !src)
		return (NULL);
	if (pdst > psrc)
	{
		while (n > 0)
		{
			n--;
			pdst[n] = psrc[n];
		}
	}
	else
		ft_memcpy(pdst, psrc, n);
	return (dst);
}
