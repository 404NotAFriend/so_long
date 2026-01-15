/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:04:20 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/15 20:06:43 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->gfx.mlx = mlx_init();
	if (!game->gfx.mlx)
		error_exit(ERR_MLX_INIT);
	game->gfx.window = mlx_new_window(game->gfx.mlx,
			game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE,
			"so_long");
	if (!game->gfx.window)
		error_exit(ERR_WINDOW);
}

void	load_sprites(t_game *game)
{
	int	img_width;
	int	img_heigth;

	game->gfx.img_floor = mlx_xpm_file_to_image(game->gfx.mlx,
			"textures/floor.xpm", &img_width, &img_heigth);
	if (!game->gfx.img_floor)
		error_exit("❌ Failed to load floor.xpm");
	game->gfx.img_wall = mlx_xpm_file_to_image(game->gfx.mlx,
			"textures/wall.xpm", &img_width, &img_heigth);
	if (!game->gfx.img_wall)
		error_exit("❌ Failed to load wall.xpm");
	game->gfx.img_player = mlx_xpm_file_to_image(game->gfx.mlx,
			"textures/player.xpm", &img_width, &img_heigth);
	if (!game->gfx.img_player)
		error_exit("❌ Failed to load player.xpm");
	game->gfx.img_player_left = mlx_xpm_file_to_image(game->gfx.mlx,
			"textures/player_left.xpm", &img_width, &img_heigth);
	if (!game->gfx.img_player_left)
		error_exit("❌ Failed to load player_left.xpm");
	game->gfx.img_collectibles = mlx_xpm_file_to_image(game->gfx.mlx,
			"textures/collectible.xpm", &img_width, &img_heigth);
	if (!game->gfx.img_collectibles)
		error_exit("❌ Failed to load collectible.xpm");
	game->gfx.img_exit = mlx_xpm_file_to_image(game->gfx.mlx,
			"textures/exit.xpm", &img_width, &img_heigth);
	if (!game->gfx.img_exit)
		error_exit("❌ Failed to load exit.xpm");
}
