/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:12:23 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/16 02:10:39 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	execute_attack(t_game *game, int enemy_x, int enemy_y)
{
	if (enemy_x != -1 && enemy_y != -1)
	{
		game->map.grid[enemy_y][enemy_x] = 'D';
		game->map.enemies_killed++;
		ft_printf("⚔️  Enemy killed! (%d/%d)\n",
			game->map.enemies_killed, game->map.enemies_counter);
	}
}

void	attack_enemy(t_game *game)
{
	int		enemy_x;
	int		enemy_y;
	char	tile;

	enemy_x = -1;
	enemy_y = -1;
	if (game->player.facing_right)
		tile = game->map.grid[game->player.y][game->player.x + 1];
	else
		tile = game->map.grid[game->player.y][game->player.x - 1];
	game->player.is_attacking = 1;
	render_player_only(game);
	usleep(150000);
	if (tile == 'N')
	{
		if (game->player.facing_right)
			enemy_x = game->player.x + 1;
		else
			enemy_x = game->player.x - 1;
		enemy_y = game->player.y;
		execute_attack(game, enemy_x, enemy_y);
	}
	game->player.is_attacking = 0;
	render_game(game);
}
