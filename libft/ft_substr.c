/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:16:40 by ayassir           #+#    #+#             */
/*   Updated: 2021/11/21 13:04:56 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mallocate(char const *s, unsigned int start, size_t len)
{
	size_t	lenn;

	lenn = ft_strlen(s);
	if (len > lenn && start < lenn)
		return ((lenn - start) + 1);
	else if (len < lenn && start < lenn)
		return (len + 1);
	else if (start > lenn)
		return (1);
	return (len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			j;
	int				size;
	char			*p;

	if (!s)
		return (NULL);
	size = ft_mallocate(s, start, len);
	p = (char *) malloc(size * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && len > 0)
		{
			*(p + j) = *(s + i);
			j++;
			len--;
		}
		i++;
	}
	p[j] = '\0';
	return (p);
}
