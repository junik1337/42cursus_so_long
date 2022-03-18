/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:12:04 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/17 17:10:54 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_invalid(int keycode)
{
	(void) keycode;
	ft_printf("ERROR : Invalid map.\n");
	exit(EXIT_FAILURE);
}

void	ft_player_error(int keycode)
{
	(void) keycode;
	ft_printf("ERROR : You need just 1 Player.\n");
	exit(EXIT_FAILURE);
}

void	ft_exit_error(int keycode)
{
	(void) keycode;
	ft_printf("ERROR : You need at least 1 Exit.\n");
	exit(EXIT_FAILURE);
}

void	ft_coins_error(int keycode)
{
	(void) keycode;
	ft_printf("ERROR : You need at least 1 Collectible.\n");
	exit(EXIT_FAILURE);
}

void	ft_success(int keycode, t_param *p)
{
	(void) keycode;
	ft_printf("Congratulations : You Won !\n");
	free(p->player);
	free(p->coin);
	free(p->exit);
	free(p->rock);
	free(p->mlx);
	exit(EXIT_SUCCESS);
}
