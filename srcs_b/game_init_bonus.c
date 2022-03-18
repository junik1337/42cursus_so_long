/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:35:03 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/18 14:38:06 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	game_begin_b(t_params *p)
{
	int			i;
	int			j;
	size_t		chars;

	j = 0;
	chars = 0;
	while (p->map[j])
		j++;
	if (p->map[0] == NULL)
		ft_invalid_b(1);
	while (p->map[0][chars] != '\0')
		chars++;
	i = 1;
	while (i < j && p->map[i] != NULL)
	{
		if (ft_strlen(p->map[i++]) != chars)
			ft_invalid_b(1);
	}
	check_map_valid_b(p, j, chars);
	check_map_elements_b(p);
}

void	check_map_elements_b(t_params *p)
{
	check_player_b(p);
	check_exit_b(p);
	check_coins_b(p);
	put_floor_b(p);
}

void	put_floor_b(t_params *p)
{
	p->width = p->width * 48;
	p->height = p->height * 48;
	p->win = mlx_new_window(p->mlx, p->width, p->height, "SO_LONG");
	p->x = 0;
	p->y = 0;
	while (p->x < ((p->width / 32) * 48))
	{
		mlx_put_image_to_window(p->mlx, p->win, p->floor_img, p->x, p->y);
		p->x += 48;
		if (p->x >= ((p->width / 32) * 48))
		{
			p->x = 0;
			p->y += 48;
		}
		else if (p->y >= p->height)
			break ;
	}
	put_images_to_window_b(p);
}

int	images_animated(t_params *p)
{
	static int		i;
	static int		i2;
	static int		j;

	mlx_animation_coin(p, i);
	mlx_animation_enemy(p, i2);
	if (i == 7)
		i = 0;
	if (i == 5)
		i2 = 0;
	j++;
	if (j == 8)
	{
		i++;
		i2++;
		j = 0;
	}
	return (0);
}

void	put_images_to_window_b(t_params *p)
{
	p->rock = malloc (sizeof(t_r) * ft_strock_b(p));
	p->exit = malloc (sizeof(t_e) * ft_strexit_b(p));
	p->coin = malloc (sizeof(t_c) * ft_strcoin_b(p));
	p->player = malloc (sizeof(t_p) * ft_strplayer_b(p));
	p->enemy = malloc (sizeof(t_en) * ft_strenemy_b(p));
	if (!p->coin || !p->exit || !p->player || !p->rock || !p->enemy)
		exit(EXIT_FAILURE);
	init_params_b(p);
	while (p->map[p->i])
	{
		while (p->map[p->i][p->j])
		{
			fill_map_b_1(p);
			fill_map_b_2(p);
			p->x += 48;
			p->j++;
		}
		p->j = 0;
		p->y += 48;
		p->x = 0;
		p->i += 1;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->floor_img, 0, 0);
	mlx_put_image_to_window(p->mlx, p->win, p->sign, 0, 0);
}
