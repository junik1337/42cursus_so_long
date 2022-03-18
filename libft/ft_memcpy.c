/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:40:23 by ayassir           #+#    #+#             */
/*   Updated: 2021/11/24 19:21:01 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src1;
	char		*dest1;
	size_t		i;

	src1 = src;
	dest1 = dest;
	i = 0;
	if (!src && !dest)
		return (0);
	while (n > 0)
	{
		dest1[i] = src1[i];
		n--;
		i++;
	}
	return (dest);
}
