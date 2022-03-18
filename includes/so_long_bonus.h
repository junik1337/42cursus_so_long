/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:28:22 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/18 13:13:50 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
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

typedef struct s_enemy{
	int		x;
	int		y;
}				t_en;

typedef struct s_params{
	char	*map[100000];
	void	*mlx;
	void	*win;
	void	*floor_img;
	void	*rock_img;
	void	*coin_img;
	void	*coin_img1;
	void	*coin_img2;
	void	*coin_img3;
	void	*coin_img4;
	void	*coin_img5;
	void	*coin_img6;
	void	*coin_img7;
	void	*exit_img;
	void	*exit_img2;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*sign;
	void	*en1;
	void	*en2;
	void	*en3;
	void	*en4;
	void	*en5;
	void	*en6;
	t_c		*coin;
	t_p		*player;
	t_r		*rock;
	t_e		*exit;
	t_en	*enemy;
	int		x;
	int		y;
	int		i;
	int		j;
	int		r;
	int		p;
	int		e;
	int		c;
	int		en;
	int		enemy_nmber;
	int		coins_number;
	int		coins_dec;
	int		width;
	int		height;
	int		w;
	int		h;
}				t_params;

void			check_arguments_bonus(char *map_path);
void			images_init_bonus(t_params *p);
void			map_init_bonus(t_params *p, char *av);
void			ft_remove_newlines_b(t_params *p);
void			ft_check_newlines_b(t_params *p);
void			game_begin_b(t_params *p);
void			check_map_valid_b(t_params *p, int j, size_t chars);
void			check_player_b(t_params *p);
void			check_exit_b(t_params *p);
void			check_coins_b(t_params *p);
void			init_params_b(t_params *params);
int				ft_strock_b(t_params *map);
int				ft_strexit_b(t_params *map);
int				ft_strplayer_b(t_params *map);
int				ft_strcoin_b(t_params *map);
int				key_press_b(int keycode, t_params *p);
void			fill_map_b_1(t_params *p);
void			fill_map_b_2(t_params *p);
int				ft_strchr_exit_b(t_params *str, int x, int y);
int				ft_strchr_rock_b(t_params *str, int x, int y);
int				ft_strchr_coin_b(t_params *str, int x, int y);
int				strchr_one_b(char *str);
void			door_animation_b(t_params *p);
int				ft_close_b(int keycode, t_params *p);
void			ft_invalid_b(int keycode);
void			ft_player_error_b(int keycode);
void			ft_exit_error_b(int keycode);
void			ft_coins_error_b(int keycode);
void			ft_success_b(int keycode, t_params *p);
void			check_map_elements_b(t_params *p);
void			put_floor_b(t_params *p);
void			put_images_to_window_b(t_params *p);
int				images_animated(t_params *p);
void			mlx_animation_coin(t_params *p, int i);
char			*ft_itoa(int n);
void			mlx_animation_enemy(t_params *p, int i);
int				ft_strenemy_b(t_params *map);
void			ft_lost_b(int keycode, t_params *p);
void			mlx_mouvement_left(t_params *p, int i3);
void			mlx_enemy_mouvement_right(t_params *p, int i3);
#endif