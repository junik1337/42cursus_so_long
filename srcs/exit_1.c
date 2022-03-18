/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:04:04 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/17 17:10:20 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(int keycode, t_param *p)
{
	(void) keycode;
	ft_printf("GAME HAS BEEN CLOSED.\n");
	free(p->player);
	free(p->coin);
	free(p->exit);
	free(p->rock);
	free(p->mlx);
	exit(EXIT_FAILURE);
}
