/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:01:08 by ayassir           #+#    #+#             */
/*   Updated: 2021/11/21 13:17:34 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_notalloc(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
	return (NULL);
}

static size_t	ft_words(char const	*s, char c, size_t	i)
{
	size_t	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static int	ft_county(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}	
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	size_t	i;
	char	**p;

	j = 0;
	i = 0;
	p = (char **) malloc((ft_county(s, c) + 1) * sizeof(char *));
	if (p == NULL || s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			p[j] = ft_substr(s, i, ft_words(s, c, i));
			if (!p[j])
				return (ft_notalloc(p));
			j++;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	p[j] = 0;
	return (p);
}
