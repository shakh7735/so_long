/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:27:25 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/22 13:27:26 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	end_game(t_vars **vars, const char *msg, int er)
{
	int	i;

	if ((*vars)->map)
	{
		i = 0;
		while ((*vars)->map[i])
			free((*vars)->map[i++]);
	}
	free ((*vars)->map);
	free ((*vars)->man_path);
	free (*vars);
	if (er)
		ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		end_game(&vars, "No valid parametr!", 1);
	vars = (t_vars *)malloc(sizeof(t_vars));
	gamestruct_init(&vars, argv);
	ft_create_screen(&vars);
	mlx_string_put(vars->mlx, vars->win, 10, 10, \
		create_trgb(1, 240, 240, 10), "step -> 000000");
	mlx_string_put(vars->mlx, vars->win, 10, 30, \
		create_trgb(1, 240, 240, 10), "coll -> 000000");
	mlx_key_hook(vars->win, ft_input_key, &vars);
	mlx_loop_hook(vars->mlx, ft_animation, &vars);
	mlx_loop(vars->mlx);
	return (0);
}
