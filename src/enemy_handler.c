/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:12:23 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/15 21:12:49 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_enemy_up(t_game *game, int *enemy_x, int *enemy_y)
{
	if (game->map.grid[game->player.y - 1][game->player.x] == 'N')
	{
		*enemy_x = game->player.x;
		*enemy_y = game->player.y - 1;
		return (1);
	}
	return (0);
}

static int	check_enemy_down(t_game *game, int *enemy_x, int *enemy_y)
{
	if (game->map.grid[game->player.y + 1][game->player.x] == 'N')
	{
		*enemy_x = game->player.x;
		*enemy_y = game->player.y + 1;
		return (1);
	}
	return (0);
}

static int	check_enemy_sides(t_game *game, int *enemy_x, int *enemy_y)
{
	if (game->map.grid[game->player.y][game->player.x - 1] == 'N')
	{
		*enemy_x = game->player.x - 1;
		*enemy_y = game->player.y;
		return (1);
	}
	if (game->map.grid[game->player.y][game->player.x + 1] == 'N')
	{
		*enemy_x = game->player.x + 1;
		*enemy_y = game->player.y;
		return (1);
	}
	return (0);
}

static int	is_enemy_adjacent(t_game *game, int *enemy_x, int *enemy_y)
{
	if (check_enemy_up(game, enemy_x, enemy_y))
		return (1);
	if (check_enemy_down(game, enemy_x, enemy_y))
		return (1);
	if (check_enemy_sides(game, enemy_x, enemy_y))
		return (1);
	return (0);
}

void	attack_enemy(t_game *game)
{
	int	enemy_x;
	int	enemy_y;

	if (is_enemy_adjacent(game, &enemy_x, &enemy_y))
	{
		game->map.grid[enemy_y][enemy_x] = 'D';
		game->map.enemies_killed++;
		ft_printf("⚔️  Enemy killed! (%d/%d)\n",
			game->map.enemies_killed, game->map.enemies_counter);
		render_game(game);
	}
}
