/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:41:37 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/18 13:13:11 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	mlx_anim_coins(t_params *p, int j, void *img)
{
	int		x;
	int		y;

	x = (p->coin + j)->x;
	y = (p->coin + j)->y;
	if (x == 0 && y == 0)
		return ;
	mlx_put_image_to_window(p->mlx, p->win, p->floor_img, x, y);
	mlx_put_image_to_window(p->mlx, p->win, img, x, y);
}

void	mlx_animation_coin(t_params *p, int i)
{
	int			j;
	void		*img;

	j = -1;
	if (i == 0)
		img = p->coin_img;
	else if (i == 1)
		img = p->coin_img1;
	else if (i == 2)
		img = p->coin_img2;
	else if (i == 3)
		img = p->coin_img3;
	else if (i == 4)
		img = p->coin_img4;
	else if (i == 5)
		img = p->coin_img5;
	else if (i == 6)
		img = p->coin_img6;
	else if (i == 7)
		img = p->coin_img7;
	else
		return ;
	while (++j <= p->coins_number)
		mlx_anim_coins(p, j, img);
}

static void	mlx_anim_enemy(t_params *p, int j, void *img)
{
	int		x;
	int		y;

	x = (p->enemy + j)->x;
	y = (p->enemy + j)->y;
	if (x == 0 && y == 0)
		return ;
	mlx_put_image_to_window(p->mlx, p->win, p->floor_img, x, y);
	mlx_put_image_to_window(p->mlx, p->win, img, x, y);
}

void	mlx_animation_enemy(t_params *p, int i)
{
	int			j;
	void		*img;

	j = -1;
	if (i == 0)
		img = p->en1;
	else if (i == 1)
		img = p->en2;
	else if (i == 2)
		img = p->en3;
	else if (i == 3)
		img = p->en4;
	else if (i == 4)
		img = p->en5;
	else if (i == 5)
		img = p->en6;
	else
		return ;
	while (++j <= p->enemy_nmber)
		mlx_anim_enemy(p, j, img);
}
