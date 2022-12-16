/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:05:11 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/22 13:05:12 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	ft_create_screen2(t_vars **vars, int len, int i);
static void	screen_loop(t_vars **vars, int len, int i);

int	ft_create_screen(t_vars **vars)
{
	int	i;
	int	len;

	len = -1;
	while ((*vars)->map[++len])
	{
		i = -1;
		while ((*vars)->map[len][++i])
			screen_loop(vars, len, i);
	}
	return (0);
}

static void	screen_loop(t_vars **vars, int len, int i)
{
	if ((*vars)->map[len][i] == '1')
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, \
			(*vars)->wall, i * (*vars)->pos.size, len * (*vars)->pos.size);
	if ((*vars)->map[len][i] == 'E')
		mlx_put_image_to_window ((*vars)->mlx, (*vars)->win, (*vars)->exit, \
			i * (*vars)->pos.size, len * (*vars)->pos.size);
	if ((*vars)->map[len][i] == 'C')
		mlx_put_image_to_window ((*vars)->mlx, (*vars)->win, (*vars)->collect, \
			i * (*vars)->pos.size, len * (*vars)->pos.size);
	if ((*vars)->map[len][i] == 'G')
		mlx_put_image_to_window ((*vars)->mlx, (*vars)->win, (*vars)->enemy, \
			i * (*vars)->pos.size, len * (*vars)->pos.size);
	if ((*vars)->map[len][i] == 'P')
		ft_create_screen2(vars, len, i);
}

static void	ft_create_screen2(t_vars **vars, int len, int i)
{
	mlx_put_image_to_window ((*vars)->mlx, (*vars)->win, (*vars)->man_img, \
		i * (*vars)->pos.size, len * (*vars)->pos.size);
	(*vars)->pos.x = i;
	(*vars)->pos.y = len;
	(*vars)->oldpos.y = (*vars)->pos.y;
	(*vars)->oldpos.x = (*vars)->pos.x;
}
