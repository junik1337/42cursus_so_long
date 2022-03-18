/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:32:45 by ayassir           #+#    #+#             */
/*   Updated: 2021/11/23 18:44:41 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	first(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	firsty;

	i = 0;
	j = 0;
	firsty = 0;
	while (s1[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if (set[j] == s1[i])
			{
				firsty = i + 1;
				j = 0;
				break ;
			}
			else
			{
				j++;
			}
		}
		i++;
	}
	return (firsty);
}

int	second(const char *s1, const char *set)
{
	int	j;
	int	len;
	int	secondy;

	j = 0;
	len = ft_strlen(s1) - 1;
	secondy = len;
	while (len >= 0)
	{
		if (set[j] == '\0')
			break ;
		while (set[j] != '\0')
		{
			if (set[j] == s1[len])
			{
				j = 0;
				break ;
			}
			secondy = len;
			j++;
		}
		len--;
	}
	return (secondy);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		firsti;
	int		secondi;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	firsti = first(s1, set);
	secondi = second(s1, set);
	if (firsti == (int) ft_strlen(s1))
		return (ft_strdup(""));
	p = (char *) malloc(((secondi - firsti) + 2) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (firsti <= secondi)
	{
		p[i] = s1[firsti];
		firsti++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
