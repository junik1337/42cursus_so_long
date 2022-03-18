/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:24:05 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/17 17:11:48 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	key_right(t_param *p, int i)
{
	ft_printf("%d\n", i);
	if (ft_strchr_coin(p, (p->player)->x + 48, (p->player)->y))
			p->coins_number--;
	if (p->coins_number == 0)
		door_animation(p);
	if (ft_strchr_exit(p, (p->player)->x + 48, (p->player)->y) == 1
		&& p->coins_number <= 0)
		ft_success(KEY_D, p);
	if (!ft_strchr_exit(p, (p->player)->x + 48, (p->player)->y))
	{
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img,
			(p->player)->x + 48, (p->player)->y);
		(p->player)->x += 48;
		mlx_put_image_to_window(p->mlx, p->win, p->player_right, (p->player)->x,
			(p->player)->y);
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img,
			(p->player)->x - 48, (p->player)->y);
	}
}

static void	key_up(t_param *p, int i)
{
	ft_printf("%d\n", i);
	if (ft_strchr_coin(p, (p->player)->x, (p->player)->y - 48))
			p->coins_number--;
	if (p->coins_number == 0)
		door_animation(p);
	if (ft_strchr_exit(p, (p->player)->x, (p->player)->y - 48) == 1
		&& p->coins_number <= 0)
		ft_success(KEY_D, p);
	if (!ft_strchr_exit(p, (p->player)->x, (p->player)->y - 48))
	{
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img, (p->player)->x,
			(p->player)->y - 48);
		(p->player)->y -= 48;
		mlx_put_image_to_window(p->mlx, p->win, p->player_up, (p->player)->x,
			(p->player)->y);
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img, (p->player)->x,
			(p->player)->y + 48);
	}
}

static void	key_down(t_param *p, int i)
{
	ft_printf("%d\n", i);
	if (ft_strchr_coin(p, (p->player)->x, (p->player)->y + 48))
			p->coins_number--;
	if (p->coins_number == 0)
		door_animation(p);
	if (ft_strchr_exit(p, (p->player)->x, (p->player)->y + 48) == 1
		&& p->coins_number <= 0)
		ft_success(KEY_D, p);
	if (!ft_strchr_exit(p, (p->player)->x, (p->player)->y + 48))
	{
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img, (p->player)->x,
			(p->player)->y + 48);
		(p->player)->y += 48;
		mlx_put_image_to_window(p->mlx, p->win, p->player_down, (p->player)->x,
			(p->player)->y);
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img, (p->player)->x,
			(p->player)->y - 48);
	}
}

static void	key_left(t_param *p, int i)
{
	ft_printf("%d\n", i);
	if (ft_strchr_coin(p, (p->player)->x - 48, (p->player)->y))
			p->coins_number--;
	if (p->coins_number == 0)
		door_animation(p);
	if (ft_strchr_exit(p, (p->player)->x - 48, (p->player)->y) == 1
		&& p->coins_number <= 0)
		ft_success(KEY_D, p);
	if (!ft_strchr_exit(p, (p->player)->x - 48, (p->player)->y))
	{
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img,
			(p->player)->x - 48, (p->player)->y);
		(p->player)->x -= 48;
		mlx_put_image_to_window(p->mlx, p->win, p->player_left,
			(p->player)->x, (p->player)->y);
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img,
			(p->player)->x + 48, (p->player)->y);
	}
}

int	key_press(int keycode, t_param *p)
{
	static int		i;

	if (keycode == KEY_D
		&& !ft_strchr_rock(p, (p->player)->x + 48, (p->player)->y))
		key_right(p, ++i);
	if (keycode == KEY_W
		&& !ft_strchr_rock(p, (p->player)->x, (p->player)->y - 48))
		key_up(p, ++i);
	if (keycode == KEY_S
		&& !ft_strchr_rock(p, (p->player)->x, (p->player)->y + 48))
		key_down(p, ++i);
	if (keycode == KEY_A
		&& !ft_strchr_rock(p, (p->player)->x - 48, (p->player)->y))
		key_left(p, ++i);
	if (keycode == KEY_ESC)
		ft_close(KEY_ESC, p);
	return (0);
}
