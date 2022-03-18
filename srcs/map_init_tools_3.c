/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_tools_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:38:04 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/16 16:38:16 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strcoin(t_param *map)
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
