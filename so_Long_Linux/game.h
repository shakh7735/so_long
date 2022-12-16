/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:14:50 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/22 13:14:52 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "minilibx/mlx.h"
# include "ft_printf/utils/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define KEY_Q 12
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0

typedef struct s_sprite {
	int	x;
	int	y;
	int	size;
}				t_sprite;

typedef struct s_count {
	int	player;
	int	exit;
	int	collect;
	int	enemy;
}				t_count;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	char		**map;
	void		*man_img;
	void		*non_img;
	void		*wall;
	void		*exit;
	void		*collect;
	void		*enemy;
	int			man_imgind;
	int			col_imgind;
	char		*man_path;
	int			img_width;
	int			img_height;
	int			m_sl;
	int			c_sl;
	int			step;
	int			colect;
	t_sprite	pos;
	t_sprite	oldpos;
	t_sprite	monitor;
	t_sprite	game_scr;
	t_count		kind;
}				t_vars;

int		ft_input_key(int key, t_vars **vars);
char	*ft_strjoin_m(char *path, int *ind, const char *temp, int max_ind);
int		ft_create_screen(t_vars **vars);
int		ft_anim_man(t_vars **vars);
int		ft_anim_collect(t_vars **vars);
int		ft_animation(t_vars **vars);
char	*ft_counting(char *begin, int *count, int len);
void	gamestruct_init(t_vars **vars, char **argv);
void	map_check_and_init(t_vars **vars, char **argv);
void	end_game(t_vars **vars, const char *msg, int er);
void	check_line_and_init_map(t_vars **vars, char *line);
int		create_trgb(int t, int r, int g, int b);

#endif
