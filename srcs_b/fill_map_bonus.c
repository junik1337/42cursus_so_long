/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:28:41 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/17 14:48:28 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	fill_map_b_1(t_params *p)
{
	if (p->map[p->i][p->j] == '1')
	{
		mlx_put_image_to_window(p->mlx, p->win, p->rock_img, p->x, p->y);
		(p->rock + p->r)->x = p->x;
		(p->rock + p->r++)->y = p->y;
	}
	else if (p->map[p->i][p->j] == 'P')
	{
		mlx_put_image_to_window(p->mlx, p->win, p->player_down, p->x, p->y);
		(p->player + p->p)->x = p->x;
		(p->player + p->p++)->y = p->y;
	}
	else if (p->map[p->i][p->j] == 'X')
	{
		mlx_put_image_to_window(p->mlx, p->win, p->en1, p->x, p->y);
		(p->enemy + p->en)->x = p->x;
		(p->enemy + p->en)->y = p->y;
		p->enemy_nmber = p->en;
		p->en++;
	}
	else if (p->map[p->i][p->j] == '0')
		return ;
}

void	fill_map_b_2(t_params *p)
{
	static int		k;

	if (k == 0)
		k++;
	if (p->map[p->i][p->j] == 'E')
	{
		mlx_put_image_to_window(p->mlx, p->win, p->exit_img, p->x, p->y);
		(p->exit + p->e)->x = p->x;
		(p->exit + p->e++)->y = p->y;
		(p->exit)->i_e = k + 1;
		k++;
	}	
	else if (p->map[p->i][p->j] == 'C')
	{
		mlx_put_image_to_window(p->mlx, p->win, p->coin_img, p->x, p->y);
		(p->coin + p->c)->x = p->x;
		(p->coin + p->c)->y = p->y;
		p->coins_number = p->c;
		p->c++;
		p->coins_dec = p->c;
	}
	if (p->map[p->i][p->j] != '1' && p->map[p->i][p->j] != 'P'
		&& p->map[p->i][p->j] != 'E' && p->map[p->i][p->j] != 'C'
		&& p->map[p->i][p->j] != '0' && p->map[p->i][p->j] != 'X')
		ft_invalid_b(1);
}
