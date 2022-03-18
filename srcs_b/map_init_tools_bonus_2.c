/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_tools_bonus_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:44:35 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/17 14:11:21 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_strcoin_b(t_params *map)
{
	int		i;
	int		j;
	int		rtn;

	i = 0;
	j = 0;
	rtn = 0;
	while (map->map[i])
	{
		if (map->map[i][j] == 'C')
			rtn += 1;
		j++;
		if (map->map[i][j - 1] == '\0')
		{
			i++;
			j = 0;
		}
	}
	if (rtn == 0)
	{
		ft_printf("You need at least 1 Collectible...!\n\n");
		exit(EXIT_FAILURE);
	}
	return (rtn);
}

int	ft_strenemy_b(t_params *map)
{
	int		i;
	int		j;
	int		rtn;

	i = 0;
	j = 0;
	rtn = 0;
	while (map->map[i])
	{
		if (map->map[i][j] == 'X')
			rtn += 1;
		j++;
		if (map->map[i][j - 1] == '\0')
		{
			i++;
			j = 0;
		}
	}
	if (rtn == 0)
	{
		ft_printf("You need at least 1 Enemy...!\n\n");
		exit(EXIT_FAILURE);
	}
	return (rtn);
}
