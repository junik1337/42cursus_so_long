/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:59:43 by ayassir           #+#    #+#             */
/*   Updated: 2021/11/19 16:10:06 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = (int) ft_strlen(str);
	if (!str)
		return (0);
	while (i >= 0)
	{
		if (str[i] == (unsigned char )c)
			return ((char *) str + i);
		i--;
	}
	return (NULL);
}
