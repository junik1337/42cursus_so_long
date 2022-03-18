/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:23:14 by ayassir           #+#    #+#             */
/*   Updated: 2021/12/19 11:33:17 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int				nbr;
	int				rt;

	nbr = n;
	rt = 0;
	if (n < 0)
	{
		rt += write(1, "-", 1);
		if (n == -2147483648)
			rt += write(1, "2147483648", 10);
		n = n * (-1);
	}
	if (n <= 9 && n >= 0)
	{
		nbr = n + 48;
		rt += write(1, &nbr, 1);
	}
	if (n > 9)
	{
		rt += ft_putnbr(n / 10);
		rt += ft_putnbr(n % 10);
	}
	return (rt);
}