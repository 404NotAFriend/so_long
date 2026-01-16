/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:04:46 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/16 01:16:21 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_game *game)
{
	int	i;
	int	len;
	int	current_len;

	if (game->map.height == 0)
		return (0);
	len = ft_strlen(game->map.grid[0]);
	if (game->map.grid[0][len - 1] == '\n')
		len--;
	i = 1;
	while (i < game->map.height)
	{
		current_len = ft_strlen(game->map.grid[i]);
		if (game->map.grid[i][current_len - 1] == '\n')
			current_len--;
		if (current_len != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.grid[0][i] != '1'
			|| game->map.grid[game->map.height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (game->map.grid[i][j] && game->map.grid[i][j] != '\n')
			j++;
		j--;
		if (game->map.grid[i][0] != '1' || game->map.grid[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

static void	store_element_position(t_game *game, char c, int i, int j)
{
	if (c == 'P')
	{
		game->player.x = j;
		game->player.y = i;
	}
	else if (c == 'E')
	{
		game->map.exit_x = j;
		game->map.exit_y = i;
	}
}

int	check_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			store_element_position(game, game->map.grid[i][j], i, j);
			if (game->map.grid[i][j] != 'P'
				&& game->map.grid[i][j] != 'E'
				&& game->map.grid[i][j] != 'C'
				&& game->map.grid[i][j] != 'N'
				&& game->map.grid[i][j] != '0'
				&& game->map.grid[i][j] != '1'
				&& game->map.grid[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	int	players;
	int	exits;
	int	collectibles;

	players = 0;
	exits = 0;
	collectibles = 0;
	if (!check_rectangular(game))
		error_exit(ERR_MAP_NOT_RECTANGULAR);
	if (!check_walls(game))
		error_exit(ERR_MAP_NO_WALLS);
	if (!check_characters(game))
		error_exit(ERR_MAP_INVALID_CHAR);
	count_elements_loop(game, &players, &exits, &collectibles);
	if (players != 1)
		error_exit(ERR_MAP_NO_PLAYER);
	if (exits != 1)
		error_exit(ERR_MAP_NO_EXIT);
	if (collectibles < 1)
		error_exit(ERR_MAP_NO_COLLECTIBLES);
	game->map.collectibles_counter = collectibles;
	if (!check_valid_path(game))
		error_exit(ERR_MAP_NO_PATH);
	return (1);
}
