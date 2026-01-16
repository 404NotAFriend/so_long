/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:04:42 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/16 01:49:31 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_game *game)
{
	int	i;

	ft_printf("\n✅ Map read successfully!\n");
	ft_printf("Width: %d, Height: %d\n\n", game->map.width, game->map.height);
	i = 0;
	while (i < game->map.height)
	{
		ft_printf("%s", game->map.grid[i]);
		i++;
	}
	count_map_elements(game);
}

void	render_tile(t_game *game, int x, int y, char tile)
{
	void	*img;

	if (tile != '1')
		mlx_put_image_to_window(game->gfx.mlx, game->gfx.window,
			game->gfx.img_floor, x * TILE_SIZE, y * TILE_SIZE);
	if (tile == 'D')
		draw_transparent_sprite(game, game->gfx.img_dead_enemy,
			x * TILE_SIZE, y * TILE_SIZE);
	if (game->player.x == x && game->player.y == y)
	{
		render_player(game, x, y);
		return ;
	}
	img = get_tile_sprite(game, tile);
	if (!img)
		return ;
	if (tile == '0' || tile == '1' || tile == 'D')
		mlx_put_image_to_window(game->gfx.mlx, game->gfx.window,
			img, x * TILE_SIZE, y * TILE_SIZE);
	else
		draw_transparent_sprite(game, img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_tile(game, x, y, game->map.grid[y][x]);
			x++;
		}
		y++;
	}
	display_moves(game);
}
