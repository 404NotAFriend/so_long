/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:04:20 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/03 09:10:10 by bramalho@st      ###   ########.fr       */
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
