/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:33:49 by ayassir           #+#    #+#             */
/*   Updated: 2021/11/24 13:50:38 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_test(int n)
{
	long	num;
	int		len;

	num = n;
	len = 0;
	if (n < 0)
	{
		num = num * (-1);
		len++;
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	if (n == 0)
		len++;
	return (len);
}

long	ft_topstv(long n)
{
	if (n < 0)
		n = n * (-1);
	return (n);
}

char	*ft_itoa(int n)
{
	int		j;
	long	i;
	int		rem;
	int		len;
	char	*str;

	rem = 0;
	len = ft_test(n);
	j = 0;
	i = ft_topstv(n);
	str = malloc ((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (len > j)
	{
		rem = i % 10;
		i = i / 10;
		str[len - (j + 1)] = rem + '0';
		j++;
	}
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	return (str);
}
