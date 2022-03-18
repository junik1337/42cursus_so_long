/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:30:57 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/16 18:12:32 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strchr_exit(t_param *str, int x, int y)
{
	int		i;

	i = 0;
	while (i < 200)
	{
		if ((str->exit + i)->x == x && (str->exit + i)->y == y)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strchr_rock(t_param *str, int x, int y)
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

void	door_animation(t_param *p)
{
	int					x_exit;
	int					y_exit;
	int					i;

	i = 0;
	x_exit = (p->exit + i)->x;
	y_exit = (p->exit + i)->y;
	mlx_put_image_to_window(p->mlx, p->win, p->floor_img, x_exit, y_exit);
	mlx_put_image_to_window(p->mlx, p->win, p->exit_img, x_exit, y_exit);
	mlx_put_image_to_window(p->mlx, p->win, p->floor_img, x_exit, y_exit);
	mlx_put_image_to_window(p->mlx, p->win, p->exit_img2, x_exit, y_exit);
}
