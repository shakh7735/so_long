#ifndef GAME_H

# define GAME_H

# include <X11/Xlib.h>
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include "ft_printf/utils/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "keycode.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


typedef struct	s_sprite {
	int x;
	int y;
	int size;
}		t_sprite;

typedef struct	s_count {
	int player;
	int exit;
	int collect;
	int enemy;
}		t_count;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	void	*man_img;
	void	*non_img;
	void	*wall;
	void	*exit;
	void	*collect;
	void	*enemy;
	int		man_imgind;
	int		col_imgind;
	char	*man_path;
	int		img_width;
 	int		img_height;
 	int		m_sl;
 	int		c_sl;
 	int		step;
 	int		colect;
 	t_sprite	pos;
 	t_sprite	oldpos;
 	t_sprite	monitor;
 	t_sprite	game_scr;
 	t_count		kind;
}				t_vars;


#endif
