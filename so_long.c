/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:30:49 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/18 14:31:21 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_param		*params;

	if (ac == 2)
	{
		check_arguments(av[1]);
		params = malloc(sizeof(t_param));
		if (!params)
			return (0);
		params->mlx = mlx_init();
		images_init(params);
		map_init(params, av[1]);
		ft_check_newlines(params);
		ft_remove_newlines(params);
		game_begin(params);
		mlx_loop(params->mlx);
	}
	else
		ft_printf("Check Your Arguments... !\n");
	return (0);
}
