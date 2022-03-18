/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:46:58 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/17 15:23:05 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_strchr_exit_b(t_params *str, int x, int y)
{
	int		i;

	i = 0;
	while (i < 200)
	{
		if ((str->exit + i)->x == x && (str->exit + i)->y == y)
			return (1);
		if ((str->enemy + i)->x == x && (str->enemy + i)->y == y)
			return (2);
		i++;
	}
	return (0);
}

int	ft_strchr_rock_b(t_params *str, int x, int y)
{
	int		i;

	i = 0;
	while (i < 200)
	{
		if ((str->rock + i)->x == x && (str->rock + i)->y == y)
			return (1);
		i++;
	}
	return (0);
}

void	door_animation_b(t_params *p)
{
	int					x_exit;
	int					y_exit;
	int					i;

	i = 0;
	while ((p->exit)->i_e > 1)
	{
		x_exit = (p->exit + i)->x;
		y_exit = (p->exit + i)->y;
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img, x_exit, y_exit);
		mlx_put_image_to_window(p->mlx, p->win, p->exit_img, x_exit, y_exit);
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img, x_exit, y_exit);
		mlx_put_image_to_window(p->mlx, p->win, p->exit_img2, x_exit, y_exit);
		(p->exit)->i_e--;
		i++;
	}
}
