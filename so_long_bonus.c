/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:30:49 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/18 14:36:51 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

int	main(int ac, char **av)
{
	t_params		*params;

	if (ac == 2)
	{
		check_arguments_bonus(av[1]);
		params = malloc(sizeof(t_params));
		if (!params)
			return (0);
		params->mlx = mlx_init();
		images_init_bonus(params);
		map_init_bonus(params, av[1]);
		ft_check_newlines_b(params);
		ft_remove_newlines_b(params);
		game_begin_b(params);
		mlx_hook(params->win, X_EVENT_KEY_PRESS, 0, &key_press_b, params);
		mlx_hook(params->win, X_EVENT_KEY_EXIT, 0, &ft_close_b, params);
		mlx_loop_hook(params->mlx, &images_animated, params);
		mlx_loop(params->mlx);
	}
	else
		ft_printf("Check Your Arguments... !\n");
	return (0);
}
