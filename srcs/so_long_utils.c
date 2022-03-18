/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:38:09 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/18 14:35:13 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_arguments(char *map_path)
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

void	images_init(t_param *p)
{
	int		w;
	int		h;

	p->coin_img = mlx_xpm_file_to_image(p->mlx, "xpm/coin2.xpm", &w, &h);
	p->player_down = mlx_xpm_file_to_image(p->mlx, "xpm/dwn.xpm", &w, &h);
	p->player_up = mlx_xpm_file_to_image(p->mlx, "xpm/up.xpm", &w, &h);
	p->player_left = mlx_xpm_file_to_image(p->mlx, "xpm/lft.xpm", &w, &h);
	p->player_right = mlx_xpm_file_to_image(p->mlx, "xpm/rt.xpm", &w, &h);
	p->floor_img = mlx_xpm_file_to_image(p->mlx, "xpm/floor.xpm", &w, &h);
	p->rock_img = mlx_xpm_file_to_image(p->mlx, "xpm/rock.xpm", &w, &h);
	p->exit_img = mlx_xpm_file_to_image(p->mlx, "xpm/exit.xpm", &w, &h);
	p->exit_img2 = mlx_xpm_file_to_image(p->mlx, "xpm/exit1.xpm", &w, &h);
}

void	map_init(t_param *p, char *av)
{
	int		fd;
	int		j;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("INVALID fd !.\n");
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

int	strchr_one(char *str)
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

int	ft_strchr_coin(t_param *str, int x, int y)
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
