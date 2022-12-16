/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:23:46 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/22 13:23:48 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	gamestruct_init2(t_vars **vars);

void	gamestruct_init(t_vars **vars, char **argv)
{
	(*vars)->mlx = mlx_init();
	mlx_get_screen_size((*vars)->mlx, &(*vars)->monitor.x, &(*vars)->monitor.y);
	(*vars)->man_path = malloc(sizeof(char) * 50);
	(*vars)->map = malloc(sizeof(char *) * 50);
	(*vars)->map[0] = 0;
	map_check_and_init(vars, argv);
	(*vars)->pos.size = 50;
	if ((*vars)->monitor.x / (*vars)->pos.size < (*vars)->game_scr.x \
		|| (*vars)->monitor.y / (*vars)->pos.size < (*vars)->game_scr.y)
		end_game(vars, "Slishkom bolshaya karta!", 1);
	(*vars)->win = mlx_new_window((*vars)->mlx, \
		(*vars)->game_scr.x * (*vars)->pos.size, \
		(*vars)->game_scr.y * (*vars)->pos.size, "SO_LONG");
	gamestruct_init2(vars);
}

static void	gamestruct_init2(t_vars **vars)
{
	(*vars)->man_imgind = 1;
	(*vars)->col_imgind = 1;
	(*vars)->m_sl = 0;
	(*vars)->c_sl = 0;
	(*vars)->step = 0;
	(*vars)->colect = 0;
	(*vars)->wall = mlx_xpm_file_to_image((*vars)->mlx, "./sprite/wall.xpm", \
		&((*vars)->img_width), &((*vars)->img_height));
	(*vars)->non_img = mlx_xpm_file_to_image((*vars)->mlx, "./sprite/non.xpm", \
		&((*vars)->img_width), &((*vars)->img_height));
	(*vars)->exit = mlx_xpm_file_to_image((*vars)->mlx, "./sprite/house.xpm", \
		&((*vars)->img_width), &((*vars)->img_height));
	(*vars)->collect = mlx_xpm_file_to_image((*vars)->mlx, \
		"./sprite/moneta1.xpm", &((*vars)->img_width), &((*vars)->img_height));
	(*vars)->enemy = mlx_xpm_file_to_image((*vars)->mlx, "./sprite/floor.xpm", \
		&((*vars)->img_width), &((*vars)->img_height));
	(*vars)->man_img = mlx_xpm_file_to_image((*vars)->mlx, "./sprite/man1.xpm", \
		&(*vars)->img_width, &(*vars)->img_height);
}
