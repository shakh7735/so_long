/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:51:20 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/22 12:51:24 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	init_kind(t_vars **vars, char *line);
static int	check_line_and_init_map2(t_vars **vars, char *line, int i);
static int	check_line_and_init_map3(t_vars **vars, char *line, int i);

void	map_check_and_init(t_vars **vars, char **argv)
{
	char	*line;
	int		fd;

	fd = open (argv[1], O_RDONLY);
	if (fd == -1)
		end_game(vars, "Wrong map path!", 1);
	line = get_next_line(fd);
	if (ft_strlen(line) == 0)
		end_game(vars, "Wrong map!", 1);
	line[ft_strlen(line) - 1] = 0;
	init_kind (vars, line);
	while (line)
	{
		(*vars)->game_scr.y += 1;
		check_line_and_init_map(vars, line);
		free (line);
		line = get_next_line(fd);
		if (line)
			line[ft_strlen(line) - 1] = 0;
	}
	if ((*vars)->game_scr.y == 0 || (*vars)->game_scr.x == 0)
		end_game(vars, "Wrong map!", 1);
	check_line_and_init_map (vars, line);
	close (fd);
}

static void	init_kind(t_vars **vars, char *line)
{
	(*vars)->game_scr.x = (int)ft_strlen(line);
	(*vars)->game_scr.y = 0;
	(*vars)->kind.player = 0;
	(*vars)->kind.exit = 0;
	(*vars)->kind.collect = 0;
	(*vars)->kind.enemy = 0;
}

void	check_line_and_init_map(t_vars **vars, char *line)
{
	int	i;

	if (line)
	{
		if ((int)ft_strlen(line) != (*vars)->game_scr.x)
			end_game(vars, "Map lines of different lengths!", 1);
		else
			(*vars)->map[(*vars)->game_scr.y - 1] = \
		malloc(sizeof(char) * ((*vars)->game_scr.x + 1));
	}
	if (line)
	{
		i = -1;
		while (line[++i])
			(*vars)->map[(*vars)->game_scr.y - 1][i] = line[i];
		(*vars)->map[(*vars)->game_scr.y - 1][i] = 0;
	}
	i = -1;
	i = check_line_and_init_map2(vars, line, i);
	if (line && line[i - 1] != '1')
		end_game(vars, "The right wall contains a non-valid character!", 1);
	if (!line)
		if ((*vars)->kind.player != 1 || (*vars)->kind.collect == 0 \
			|| (*vars)->kind.exit == 0)
			end_game(vars, "Something is missing from the map!", 1);
}

static int	check_line_and_init_map2(t_vars **vars, char *line, int i)
{
	if (!line)
	{	
		(*vars)->map[(*vars)->game_scr.y] = NULL;
		while ((*vars)->map[(*vars)->game_scr.y - 1][++i])
			if ((*vars)->map[(*vars)->game_scr.y - 1][i] != '1')
				end_game(vars, "There is a flaw in the last line!", 1);
	}
	else if ((*vars)->game_scr.y == 1 && line)
	{
		while (line[++i])
			if (line[i] != '1')
				end_game(vars, "Flaw in the first line!", 1);
	}
	else
		i = check_line_and_init_map3(vars, line, i);
	return (i);
}

static int	check_line_and_init_map3(t_vars **vars, char *line, int i)
{
	while (line[++i])
	{
		if (line[i] == 'P')
			(*vars)->kind.player += 1;
		else if (line[i] == 'C')
			(*vars)->kind.collect += 1;
		else if (line[i] == 'E')
			(*vars)->kind.exit += 1;
		else if (line[i] == 'G')
			(*vars)->kind.enemy += 1;
		else if (i == 0 && line[i] != '1')
			end_game(vars, "The left wall contains a non-valid character!", 1);
		else if (line[i] == '0' || line[i] == '1')
			continue ;
		else
			end_game(vars, "Extra symbols on the map!", 1);
	}
	return (i);
}
