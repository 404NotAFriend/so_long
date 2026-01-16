/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_screens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 02:15:36 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/16 02:25:22 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_black_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height * TILE_SIZE)
	{
		x = 0;
		while (x < game->map.width * TILE_SIZE)
		{
			mlx_pixel_put(game->gfx.mlx, game->gfx.window,
				x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	show_game_over(t_game *game)
{
	int	center_x;
	int	center_y;

	mlx_clear_window(game->gfx.mlx, game->gfx.window);
	draw_black_background(game);
	center_x = (game->map.width * TILE_SIZE) / 2 - 40;
	center_y = (game->map.height * TILE_SIZE) / 2;
	mlx_string_put(game->gfx.mlx, game->gfx.window,
		center_x, center_y, 0xFF0000, "GAME OVER");
	mlx_string_put(game->gfx.mlx, game->gfx.window,
		center_x + 1, center_y, 0xFF0000, "GAME OVER");
	mlx_string_put(game->gfx.mlx, game->gfx.window,
		center_x, center_y + 1, 0xFF0000, "GAME OVER");
	mlx_string_put(game->gfx.mlx, game->gfx.window,
		center_x + 1, center_y + 1, 0xFF0000, "GAME OVER");
	mlx_do_sync(game->gfx.mlx);
	sleep(3);
	cleanup_and_exit(game, 0);
}

void	show_victory(t_game *game)
{
	int	center_x;
	int	center_y;

	mlx_clear_window(game->gfx.mlx, game->gfx.window);
	draw_black_background(game);
	center_x = (game->map.width * TILE_SIZE) / 2 - 40;
	center_y = (game->map.height * TILE_SIZE) / 2 - 20;
	mlx_string_put(game->gfx.mlx, game->gfx.window,
		center_x, center_y, 0x00FF00, "VICTORY!");
	mlx_string_put(game->gfx.mlx, game->gfx.window,
		center_x - 30, center_y + 40, 0xFFFFFF, "Press ESC to close");
	game->gfx.game_ended = 1;
}
