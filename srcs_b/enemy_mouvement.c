/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mouvement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:13:27 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/18 13:42:13 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_mouuveeee(t_params *p, int i)
{
	mlx_put_image_to_window(p->mlx, p->win, p->floor_img,
		(p->enemy + i)->x + 48, (p->enemy + i)->y);
	(p->enemy + i)->x += 48;
	mlx_put_image_to_window(p->mlx, p->win, p->en1, (p->enemy + i)->x,
		(p->enemy + i)->y);
	mlx_put_image_to_window(p->mlx, p->win, p->floor_img,
		(p->enemy + i)->x - 48, (p->enemy + i)->y);
}

void	mlx_enemy_mouvement_right(t_params *p, int i3)
{
	static int			i;

	if (i > p->enemy_nmber)
		i = 0;
	if (!ft_strchr_rock_b(p, (p->enemy + i)->x - 48, (p->enemy + i)->y)
		&& (i3 % 2) == 0)
	{
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img,
			(p->enemy + i)->x - 48, (p->enemy + i)->y);
		(p->enemy + i)->x -= 48;
		mlx_put_image_to_window(p->mlx, p->win, p->en1, (p->enemy + i)->x,
			(p->enemy + i)->y);
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img,
			(p->enemy + i)->x + 48, (p->enemy + i)->y);
		i++;
	}
	else if (!ft_strchr_rock_b(p, (p->enemy + i)->x + 48, (p->enemy + i)->y)
		&& (i3 % 2) == 0)
	{
		ft_mouuveeee(p, i);
		i++;
	}
}
