/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:31:28 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/18 14:37:30 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_arguments_bonus(char *map_path)
{
	int		i;
	int		j;
	char	*find;

	find = ".ber";
	i = 0;
	j = 0;
	while (map_path[i] != '\0')
	{
		while (map_path[i] == find[j])
		{
			i++;
			j++;
			if (find[j] == '\0' && map_path[i] == '\0')
				return ;
			else if (find[j] == '\0' && map_path[i] != '\0')
				break ;
		}
		i++;
	}
	ft_printf("Invalid map type, It must be (.ber).\n");
	exit(EXIT_FAILURE);
}

void	images_init_bonus(t_params *p)
{
	p->coin_img = mlx_xpm_file_to_image(p->mlx, "xpm/coin.xpm", &p->w, &p->h);
	p->coin_img1 = mlx_xpm_file_to_image(p->mlx, "xpm/coin1.xpm", &p->w, &p->h);
	p->coin_img2 = mlx_xpm_file_to_image(p->mlx, "xpm/coin2.xpm", &p->w, &p->h);
	p->coin_img3 = mlx_xpm_file_to_image(p->mlx, "xpm/coin3.xpm", &p->w, &p->h);
	p->coin_img4 = mlx_xpm_file_to_image(p->mlx, "xpm/coin4.xpm", &p->w, &p->h);
	p->coin_img5 = mlx_xpm_file_to_image(p->mlx, "xpm/coin5.xpm", &p->w, &p->h);
	p->coin_img6 = mlx_xpm_file_to_image(p->mlx, "xpm/coin6.xpm", &p->w, &p->h);
	p->coin_img7 = mlx_xpm_file_to_image(p->mlx, "xpm/coin7.xpm", &p->w, &p->h);
	p->player_down = mlx_xpm_file_to_image(p->mlx, "xpm/dwn.xpm", &p->w, &p->h);
	p->player_up = mlx_xpm_file_to_image(p->mlx, "xpm/up.xpm", &p->w, &p->h);
	p->player_left = mlx_xpm_file_to_image(p->mlx, "xpm/lft.xpm", &p->w, &p->h);
	p->player_right = mlx_xpm_file_to_image(p->mlx, "xpm/rt.xpm", &p->w, &p->h);
	p->floor_img = mlx_xpm_file_to_image(p->mlx, "xpm/floor.xpm", &p->w, &p->h);
	p->rock_img = mlx_xpm_file_to_image(p->mlx, "xpm/rock.xpm", &p->w, &p->h);
	p->exit_img = mlx_xpm_file_to_image(p->mlx, "xpm/exit.xpm", &p->w, &p->h);
	p->exit_img2 = mlx_xpm_file_to_image(p->mlx, "xpm/exit1.xpm", &p->w, &p->h);
	p->sign = mlx_xpm_file_to_image(p->mlx, "xpm/sign.xpm", &p->w, &p->h);
	p->en1 = mlx_xpm_file_to_image(p->mlx, "xpm/en1.xpm", &p->w, &p->h);
	p->en2 = mlx_xpm_file_to_image(p->mlx, "xpm/en2.xpm", &p->w, &p->h);
	p->en3 = mlx_xpm_file_to_image(p->mlx, "xpm/en3.xpm", &p->w, &p->h);
	p->en4 = mlx_xpm_file_to_image(p->mlx, "xpm/en4.xpm", &p->w, &p->h);
	p->en5 = mlx_xpm_file_to_image(p->mlx, "xpm/en5.xpm", &p->w, &p->h);
	p->en6 = mlx_xpm_file_to_image(p->mlx, "xpm/en6.xpm", &p->w, &p->h);
}

void	map_init_bonus(t_params *p, char *av)
{
	int		fd;
	int		j;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("INVALID fd !. \n");
		exit(EXIT_FAILURE);
	}
	j = -1;
	while (++j < 200)
	{
		p->map[j] = get_next_line(fd);
		if (p->map[j] == NULL)
			break ;
	}
}

int	strchr_one_b(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strchr_coin_b(t_params *str, int x, int y)
{
	int		i;

	i = 0;
	while (i < 200)
	{
		if ((str->coin + i)->x == x && (str->coin + i)->y == y)
		{
			(str->coin + i)->x = 0;
			(str->coin + i)->y = 0;
			return (1);
		}
		i++;
	}
	return (0);
}
