/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:13:51 by ayassir           #+#    #+#             */
/*   Updated: 2021/11/24 22:28:41 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	lens1 = (int) ft_strlen(s1);
	lens2 = (int) ft_strlen(s2);
	p = (char *) malloc(((lens1 + lens2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_memmove(p, s1, lens1);
	ft_memmove(p + lens1, s2, lens2 + 1);
	return (p);
}
