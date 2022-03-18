/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:58:19 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/17 16:25:48 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_begin(t_param *p)
{
	int			i;
	int			j;
	size_t		chars;

	j = 0;
	chars = 0;
	while (p->map[j])
		j++;
	if (p->map[0] == NULL)
		ft_invalid(1);
	while (p->map[0][chars] != '\0')
		chars++;
	i = 1;
	while (i < j && p->map[i] != NULL)
	{
		if (ft_strlen(p->map[i++]) != chars)
			ft_invalid(1);
	}
	check_map_valid(p, j, chars);
	check_map_elements(p);
}

void	check_map_elements(t_param *p)
{
	check_player(p);
	check_exit(p);
	check_coins(p);
	put_floor(p);
}

void	put_floor(t_param *p)
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
	put_images_to_window(p);
}

void	put_images_to_window(t_param *p)
{
	p->rock = malloc (sizeof(t_r) * ft_strock(p));
	p->exit = malloc (sizeof(t_e) * ft_strexit(p));
	p->coin = malloc (sizeof(t_c) * ft_strcoin(p));
	p->player = malloc (sizeof(t_p) * ft_strplayer(p));
	if (!p->coin || !p->exit || !p->player || !p->rock)
		exit(EXIT_FAILURE);
	init_params(p);
	while (p->map[p->i])
	{
		while (p->map[p->i][p->j])
		{
			fill_map_1(p);
			fill_map_2(p);
			p->x += 48;
			p->j++;
		}
		p->j = 0;
		p->y += 48;
		p->x = 0;
		p->i += 1;
	}
	mlx_hook(p->win, X_EVENT_KEY_PRESS, 0, &key_press, p);
	mlx_hook(p->win, X_EVENT_KEY_EXIT, 0, &ft_close, p);
}
