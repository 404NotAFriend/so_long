/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:04:27 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/15 18:55:16 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	cleanup_and_exit(game, 0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	ft_printf("🐛 Key pressed: %d\n", keycode);
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_D)
		move_player(game, 1, 0);
	return (0);
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	target_tile;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	target_tile = game->map.grid[new_y][new_x];
	if (target_tile == '1')
		return ;
	if (target_tile == 'C')
	{
		game->map.grid[new_y][new_x] = '0';
		game->map.collected_counter++;
	}
	if (target_tile == 'E')
	{
		if (game->map.collected_counter == game->map.collectibles_counter)
		{
			game->player.moves_counter++;
			ft_printf("🎉 You won in %d moves!\n", game->player.moves_counter);
			cleanup_and_exit(game, 0);
		}
	}
	game->player.x = new_x;
	game->player.y = new_y;
	game->player.moves_counter++;
	ft_printf("Moves: %d\n", game->player.moves_counter);
	render_game(game);
}
