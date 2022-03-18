/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:24:05 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/18 13:37:56 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	key_right(t_params *p, int i, char *str)
{
	if (ft_strchr_exit_b(p, (p->player)->x + 48, (p->player)->y) == 2)
		ft_lost_b(KEY_D, p);
	mlx_enemy_mouvement_right(p, i);
	if (ft_strchr_coin_b(p, (p->player)->x + 48, (p->player)->y))
			p->coins_dec--;
	if (p->coins_dec == 0)
		door_animation_b(p);
	if (ft_strchr_exit_b(p, (p->player)->x + 48, (p->player)->y) == 1
		&& p->coins_dec <= 0)
		ft_success_b(KEY_D, p);
	if (!ft_strchr_exit_b(p, (p->player)->x + 48, (p->player)->y))
	{
		str = ft_itoa(i);
		mlx_put_image_to_window(p->mlx, p->win, p->sign, 0, 0);
		mlx_string_put(p->mlx, p->win, 9, 9, 0xFFFFFF, str);
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img,
			(p->player)->x + 48, (p->player)->y);
		(p->player)->x += 48;
		mlx_put_image_to_window(p->mlx, p->win, p->player_right, (p->player)->x,
			(p->player)->y);
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img,
			(p->player)->x - 48, (p->player)->y);
	}
}

static void	key_up(t_params *p, int i, char *str)
{
	if (ft_strchr_exit_b(p, (p->player)->x, (p->player)->y - 48) == 2)
		ft_lost_b(KEY_D, p);
	mlx_enemy_mouvement_right(p, i);
	if (ft_strchr_coin_b(p, (p->player)->x, (p->player)->y - 48))
			p->coins_dec--;
	if (p->coins_dec == 0)
		door_animation_b(p);
	if (ft_strchr_exit_b(p, (p->player)->x, (p->player)->y - 48) == 1
		&& p->coins_dec <= 0)
		ft_success_b(KEY_D, p);
	if (!ft_strchr_exit_b(p, (p->player)->x, (p->player)->y - 48))
	{
		str = ft_itoa(i);
		mlx_put_image_to_window(p->mlx, p->win, p->sign, 0, 0);
		mlx_string_put(p->mlx, p->win, 9, 9, 0xFFFFFF, str);
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img, (p->player)->x,
			(p->player)->y - 48);
		(p->player)->y -= 48;
		mlx_put_image_to_window(p->mlx, p->win, p->player_up, (p->player)->x,
			(p->player)->y);
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img, (p->player)->x,
			(p->player)->y + 48);
	}
}

static void	key_down(t_params *p, int i, char *str)
{
	if (ft_strchr_exit_b(p, (p->player)->x, (p->player)->y + 48) == 2)
		ft_lost_b(KEY_D, p);
	mlx_enemy_mouvement_right(p, i);
	if (ft_strchr_coin_b(p, (p->player)->x, (p->player)->y + 48))
			p->coins_dec--;
	if (p->coins_dec == 0)
		door_animation_b(p);
	if (ft_strchr_exit_b(p, (p->player)->x, (p->player)->y + 48) == 1
		&& p->coins_dec <= 0)
		ft_success_b(KEY_D, p);
	if (!ft_strchr_exit_b(p, (p->player)->x, (p->player)->y + 48))
	{
		str = ft_itoa(i);
		mlx_put_image_to_window(p->mlx, p->win, p->sign, 0, 0);
		mlx_string_put(p->mlx, p->win, 9, 9, 0xFFFFFF, str);
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img, (p->player)->x,
			(p->player)->y + 48);
		(p->player)->y += 48;
		mlx_put_image_to_window(p->mlx, p->win, p->player_down, (p->player)->x,
			(p->player)->y);
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img, (p->player)->x,
			(p->player)->y - 48);
	}
}

static void	key_left(t_params *p, int i, char *str)
{
	if (ft_strchr_exit_b(p, (p->player)->x - 48, (p->player)->y) == 2)
		ft_lost_b(KEY_D, p);
	mlx_enemy_mouvement_right(p, i);
	if (ft_strchr_coin_b(p, (p->player)->x - 48, (p->player)->y))
			p->coins_dec--;
	if (p->coins_dec == 0)
		door_animation_b(p);
	if (ft_strchr_exit_b(p, (p->player)->x - 48, (p->player)->y) == 1
		&& p->coins_dec <= 0)
		ft_success_b(KEY_D, p);
	if (!ft_strchr_exit_b(p, (p->player)->x - 48, (p->player)->y))
	{
		str = ft_itoa(i);
		mlx_put_image_to_window(p->mlx, p->win, p->sign, 0, 0);
		mlx_string_put(p->mlx, p->win, 9, 9, 0xFFFFFF, str);
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img,
			(p->player)->x - 48, (p->player)->y);
		(p->player)->x -= 48;
		mlx_put_image_to_window(p->mlx, p->win, p->player_left,
			(p->player)->x, (p->player)->y);
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img,
			(p->player)->x + 48, (p->player)->y);
	}
}

int	key_press_b(int keycode, t_params *p)
{
	static int		i;
	static char		*str;

	if (keycode == KEY_D
		&& !ft_strchr_rock_b(p, (p->player)->x + 48, (p->player)->y))
		key_right(p, ++i, str);
	if (keycode == KEY_W
		&& !ft_strchr_rock_b(p, (p->player)->x, (p->player)->y - 48))
		key_up(p, ++i, str);
	if (keycode == KEY_S
		&& !ft_strchr_rock_b(p, (p->player)->x, (p->player)->y + 48))
		key_down(p, ++i, str);
	if (keycode == KEY_A
		&& !ft_strchr_rock_b(p, (p->player)->x - 48, (p->player)->y))
		key_left(p, ++i, str);
	if (keycode == KEY_ESC)
		ft_close_b(KEY_ESC, p);
	return (0);
}
