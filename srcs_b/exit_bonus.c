/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:12:04 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/17 15:28:25 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_invalid_b(int keycode)
{
	(void) keycode;
	ft_printf("ERROR : Invalid map.\n");
	exit(EXIT_FAILURE);
}

void	ft_player_error_b(int keycode)
{
	(void) keycode;
	ft_printf("ERROR : You need just 1 Player.\n");
	exit(EXIT_FAILURE);
}

void	ft_exit_error_b(int keycode)
{
	(void) keycode;
	ft_printf("ERROR : You need at least 1 Exit.\n");
	exit(EXIT_FAILURE);
}

void	ft_coins_error_b(int keycode)
{
	(void) keycode;
	ft_printf("ERROR : You need at least 1 Collectible.\n");
	exit(EXIT_FAILURE);
}

void	ft_success_b(int keycode, t_params *p)
{
	(void) keycode;
	ft_printf("Congratulations : You Won !\n");
	free(p->enemy);
	free(p->player);
	free(p->coin);
	free(p->exit);
	free(p->rock);
	free(p->mlx);
	exit(EXIT_SUCCESS);
}
