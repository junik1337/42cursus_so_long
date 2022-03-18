/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:31:10 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/17 17:11:00 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_R					15
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <mlx.h>
# include "../ft_printf/ft_printf.h"
# include "get_next_line.h"

typedef struct s_player{
	int		x;
	int		y;
}				t_p;

typedef struct s_coin{
	int		x;
	int		y;
}				t_c;

typedef struct s_exit{
	int		x;
	int		y;
	int		i_e;
}				t_e;

typedef struct s_rock{
	int		x;
	int		y;
}				t_r;

typedef struct s_param{
	char	*map[100000];
	void	*mlx;
	void	*win;
	void	*floor_img;
	void	*rock_img;
	void	*coin_img;
	void	*exit_img;
	void	*exit_img2;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	t_c		*coin;
	t_p		*player;
	t_r		*rock;
	t_e		*exit;
	int		x;
	int		y;
	int		i;
	int		j;
	int		r;
	int		p;
	int		e;
	int		c;
	int		coins_number;
	int		width;
	int		height;
}				t_param;

void	check_arguments(char *map_path);
void	images_init(t_param *params);
void	ft_remove_newlines(t_param *p);
void	ft_check_newlines(t_param *p);
void	map_init(t_param *p, char *av);
void	ft_invalid(int keycode);
void	game_begin(t_param *p);
size_t	ft_strlen(const char *str);
int		strchr_one(char *str);
void	check_map_valid(t_param *p, int j, size_t chars);
void	check_map_elements(t_param *p);
void	check_player(t_param *p);
void	ft_player_error(int keycode);
void	check_exit(t_param *p);
void	ft_exit_error(int keycode);
void	check_coins(t_param *p);
void	ft_coins_error(int keycode);
void	init_params(t_param *params);
void	put_images_to_window(t_param *p);
void	put_floor(t_param *p);
void	fill_map_1(t_param *p);
void	fill_map_2(t_param *p);
int		ft_strexit(t_param *map);
int		ft_strock(t_param *map);
int		ft_strcoin(t_param *map);
int		ft_strplayer(t_param *map);
int		ft_strchr_coin(t_param *str, int x, int y);
int		ft_strchr_exit(t_param *str, int x, int y);
int		ft_strchr_rock(t_param *str, int x, int y);
void	ft_success(int keycode, t_param *p);
int		ft_close(int keycode, t_param *p);
int		key_press(int keycode, t_param *p);
void	door_animation(t_param *p);
#endif