/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:30:31 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/22 13:30:32 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	instract(t_vars **vars);
static void	instract2(t_vars **vars);

int	ft_input_key(int key, t_vars **vars)
{
	(*vars)->oldpos.y = (*vars)->pos.y;
	(*vars)->oldpos.x = (*vars)->pos.x;
	if (key == KEY_Q || key == KEY_ESC)
		end_game(vars, "EXIT GAME", 0);
	if ((key == KEY_UP || key == KEY_W) \
		&& (*vars)->map[(*vars)->pos.y - 1][(*vars)->pos.x] != '1')
		(*vars)->pos.y -= 1;
	if ((key == KEY_DOWN || key == KEY_S) \
		&& (*vars)->map[(*vars)->pos.y + 1][(*vars)->pos.x] != '1')
		(*vars)->pos.y += 1;
	if ((key == KEY_RIGHT || key == KEY_D) \
		&& (*vars)->map[(*vars)->pos.y][(*vars)->pos.x + 1] != '1')
		(*vars)->pos.x += 1;
	if ((key == KEY_LEFT || key == KEY_A) \
		&& (*vars)->map[(*vars)->pos.y][(*vars)->pos.x - 1] != '1')
		(*vars)->pos.x -= 1;
	if ((*vars)->oldpos.y != (*vars)->pos.y || \
		(*vars)->oldpos.x != (*vars)->pos.x)
		instract(vars);
	if ((*vars)->map[(*vars)->pos.y][(*vars)->pos.x] == 'G')
		end_game(vars, "YOU LOST!", 0);
	if ((*vars)->map[(*vars)->pos.y][(*vars)->pos.x] == 'E' \
		&& (*vars)->kind.collect == 0)
		end_game(vars, "YOU WIN!", 0);
	return (0);
}

char	*ft_counting(char *begin, int *count, int len)
{
	int		i;
	int		n;
	char	*step;

	step = malloc(sizeof(char) * (len + 1));
	n = (*count);
	step[len] = 0;
	i = -1;
	while (begin [++i])
		step [i] = begin[i];
	while (--len > i - 1)
	{
		step[len] = (n % 10 + 48);
		n /= 10;
	}
	return (step);
}

static void	instract(t_vars **vars)
{
	if ((*vars)->oldpos.x < (*vars)->pos.x)
		(*vars)->man_imgind = 1;
	else if ((*vars)->oldpos.x > (*vars)->pos.x)
		(*vars)->man_imgind = 5;
	if ((*vars)->map[(*vars)->pos.y][(*vars)->pos.x] == 'C')
	{
		(*vars)->colect += 1;
		(*vars)->map[(*vars)->pos.y][(*vars)->pos.x] = '0';
		(*vars)->kind.collect -= 1;
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->non_img, \
		(*vars)->pos.x * (*vars)->pos.size, (*vars)->pos.y * (*vars)->pos.size);
	}
	instract2(vars);
}

static void	instract2(t_vars **vars)
{
	char	*step;

	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->wall, 0, 0);
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->wall, 50, 0);
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->wall, 100, 0);
	(*vars)->step += 1;
	step = ft_counting("step -> ", &(*vars)->step, 14);
	mlx_string_put((*vars)->mlx, (*vars)->win, 10, 10, \
		create_trgb(1, 240, 240, 10), step);
	free(step);
	step = ft_counting("coll -> ", &(*vars)->colect, 14);
	mlx_string_put((*vars)->mlx, (*vars)->win, 10, 30, \
		create_trgb(1, 240, 240, 10), step);
	free(step);
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->non_img, \
		(*vars)->oldpos.x * (*vars)->pos.size, (*vars)->oldpos.y * \
		(*vars)->pos.size);
	if ((*vars)->map[(*vars)->oldpos.y][(*vars)->oldpos.x] == 'E')
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->exit, \
		(*vars)->oldpos.x * (*vars)->pos.size, (*vars)->oldpos.y * \
		(*vars)->pos.size);
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->man_img, \
	(*vars)->pos.x * (*vars)->pos.size, (*vars)->pos.y * (*vars)->pos.size);
	(*vars)->oldpos.x = (*vars)->pos.x;
	(*vars)->oldpos.y = (*vars)->pos.y;
}
