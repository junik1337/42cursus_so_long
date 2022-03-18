/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:04:04 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/17 15:28:50 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_close_b(int keycode, t_params *p)
{
	(void) keycode;
	ft_printf("GAME HAS BEEN CLOSED.\n");
	free(p->enemy);
	free(p->player);
	free(p->coin);
	free(p->exit);
	free(p->rock);
	free(p->mlx);
	exit(EXIT_SUCCESS);
}

void	ft_lost_b(int keycode, t_params *p)
{
	(void) keycode;
	ft_printf("HARD LUCK, YOU LOST.\n");
	free(p->enemy);
	free(p->player);
	free(p->coin);
	free(p->exit);
	free(p->rock);
	free(p->mlx);
	exit(EXIT_SUCCESS);
}
