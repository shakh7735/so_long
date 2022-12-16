/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:36:48 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/22 12:36:52 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	collect_loop(t_vars **vars, int len, int i);

int	ft_animation(t_vars **vars)
{
	ft_anim_man(vars);
	ft_anim_collect(vars);
	return (0);
}

int	ft_anim_collect(t_vars **vars)
{	
	char	*path;
	int		len;

	path = malloc (sizeof(char) * 50);
	if ((*vars)->c_sl > 2000)
	{
		path = ft_strjoin_m(path, &(*vars)->col_imgind, "./sprite/moneta", 6);
		(*vars)->collect = mlx_xpm_file_to_image((*vars)->mlx, \
			path, &(*vars)->img_width, &(*vars)->img_height);
		len = 0;
		while ((*vars)->map[++len])
			collect_loop(vars, len, -1);
		(*vars)->c_sl = 1;
	}
	else
		(*vars)->c_sl += 1;
	free (path);
	return (0);
}

static void	collect_loop(t_vars **vars, int len, int i)
{
	while ((*vars)->map[len][++i])
	{
		if ((*vars)->map[len][i] == 'C')
		{
			mlx_put_image_to_window((*vars)->mlx, (*vars)->win, \
				(*vars)->non_img, i * (*vars)->pos.size, \
				len * (*vars)->pos.size);
			mlx_put_image_to_window((*vars)->mlx, (*vars)->win, \
				(*vars)->collect, i * (*vars)->pos.size, \
				len * (*vars)->pos.size);
		}
	}
}

int	ft_anim_man(t_vars **vars)
{	
	if ((*vars)->m_sl > 2000)
	{
		(*vars)->man_path = ft_strjoin_m((*vars)->man_path, \
			&(*vars)->man_imgind, "./sprite/man", 4);
		(*vars)->man_img = mlx_xpm_file_to_image((*vars)->mlx, \
			(*vars)->man_path, &(*vars)->img_width, &(*vars)->img_height);
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, \
			(*vars)->non_img, (*vars)->pos.x * (*vars)->pos.size, \
			(*vars)->pos.y * (*vars)->pos.size);
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, \
			(*vars)->man_img, (*vars)->pos.x * (*vars)->pos.size, \
			(*vars)->pos.y * (*vars)->pos.size);
		(*vars)->m_sl = 1;
	}
	else
		(*vars)->m_sl += 1;
	return (0);
}

char	*ft_strjoin_m(char *path, int *ind, const char *temp, int max_ind)
{
	int	i;

	i = -1;
	while (temp[++i])
		path[i] = temp[i];
	if ((*ind) % max_ind == 0)
		(*ind) -= max_ind;
	(*ind) += 1;
	if ((*ind) > 9)
		path[i++] = '1';
	path[i++] = ((*ind) % 10 + 48);
	path[i++] = '.';
	path[i++] = 'x';
	path[i++] = 'p';
	path[i++] = 'm';
	path[i++] = '\0';
	return (path);
}
