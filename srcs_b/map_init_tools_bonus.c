/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_tools_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:33:46 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/16 18:58:06 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_remove_newlines_b(t_params *p)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (p->map[i] != NULL)
	{
		while (p->map[i][j] != '\0')
		{
			if (p->map[i][j] == '\n')
			{
				p->map[i][j] = '\0';
				i++;
				j = 0;
			}
			else
				j++;
		}
		i++;
		j = 0;
	}
}

void	ft_check_newlines_b(t_params *p)
{
	int		i;
	int		len;

	i = 0;
	while (p->map[i] != NULL)
	{
		len = ft_strlen(p->map[i]);
		if (p->map[i][len - 1] == '\n' && p->map[i][len] == '\0' \
			&& p->map[i + 1] == NULL)
			ft_invalid_b(1);
		++i;
	}
}

void	check_map_valid_b(t_params *p, int j, size_t chars)
{
	int		i;
	int		l;

	i = j - 1;
	l = 1;
	if (strchr_one_b(p->map[0]) || strchr_one_b(p->map[i]))
		ft_invalid_b(1);
	while (p->map[l])
	{
		if (p->map[l][0] != '1' || p->map[l][chars - 1] != '1')
			ft_invalid_b(1);
		l++;
	}
	p->height = j;
	p->width = chars;
}

void	check_player_b(t_params *p)
{
	int		i;
	int		j;
	int		player;

	player = 1;
	i = 0;
	j = 0;
	while (p->map[i])
	{
		while (p->map[i][j])
		{
			if (p->map[i][j] == 'P')
				player--;
			j++;
		}
		i++;
		j = 0;
	}
	if (player < 0)
		ft_player_error_b(1);
}

void	check_exit_b(t_params *p)
{
	int		i;
	int		j;
	int		ext;

	ext = 1;
	i = 0;
	j = 0;
	while (p->map[i])
	{
		while (p->map[i][j])
		{
			if (p->map[i][j] == 'E')
				ext--;
			j++;
		}
		i++;
		j = 0;
	}
	if (ext == 1)
		ft_exit_error_b(1);
}
