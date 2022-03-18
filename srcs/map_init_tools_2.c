/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_tools_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:10:12 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/18 14:34:00 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_coins(t_param *p)
{
	int		i;
	int		j;
	int		coins;

	coins = 1;
	i = 0;
	j = 0;
	while (p->map[i])
	{
		while (p->map[i][j])
		{
			if (p->map[i][j] == 'C')
				coins--;
			j++;
		}
		i++;
		j = 0;
	}
	if (coins == 1)
		ft_coins_error(1);
}

void	init_params(t_param *params)
{
	params->x = 0;
	params->y = 0;
	params->i = 0;
	params->j = 0;
	params->r = 0;
	params->p = 0;
	params->e = 0;
	params->c = 0;
	params->coins_number = 0;
}

int	ft_strock(t_param *map)
{
	int		i;
	int		j;
	int		rtn;

	i = 0;
	j = 0;
	rtn = 0;
	while (map->map[i])
	{
		if (map->map[i][j] == '1')
			rtn += 1;
		j++;
		if (map->map[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
	return (rtn);
}

int	ft_strexit(t_param *map)
{
	int		i;
	int		j;
	int		rtn;

	i = 0;
	j = 0;
	rtn = 0;
	while (map->map[i])
	{
		if (map->map[i][j] == 'E')
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
		ft_printf("You need at least 1 Exit...!\n\n");
		exit(EXIT_FAILURE);
	}
	return (rtn);
}

int	ft_strplayer(t_param *map)
{
	int		i;
	int		j;
	int		rtn;

	i = 0;
	j = 0;
	rtn = 0;
	while (map->map[i])
	{
		if (map->map[i][j] == 'P')
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
		ft_printf("You need at least 1 Player...!\n\n");
		exit(EXIT_FAILURE);
	}
	return (rtn);
}
