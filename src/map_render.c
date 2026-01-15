/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:04:42 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/15 19:13:30 by bramalho@st      ###   ########.fr       */
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

static void	*get_tile_sprite(t_game *game, char tile)
{
	if (tile == '1')
		return (game->gfx.img_wall);
	else if (tile == '0')
		return (game->gfx.img_floor);
	else if (tile == 'P')
		return (game->gfx.img_player);
	else if (tile == 'C')
		return (game->gfx.img_collectibles);
	else if (tile == 'E')
		return (game->gfx.img_exit);
	return (NULL);
}

static void	draw_transparent_sprite(t_game *game, void *img, int x, int y)
{
	int	*data;
	int	bpp;
	int	len;
	int	color;

	data = (int *)mlx_get_data_addr(img, &bpp, &len, &color);
	if (!data)
		return ;
	color = len / 4;
	bpp = -1;
	while (++bpp < TILE_SIZE)
	{
		len = -1;
		while (++len < TILE_SIZE)
		{
			if ((data[bpp * color + len] & 0xFFFFFF) != 0xFF00FF)
				mlx_pixel_put(game->gfx.mlx, game->gfx.window,
					x + len, y + bpp, data[bpp * color + len]);
		}
	}
}

void	render_tile(t_game *game, int x, int y, char tile)
{
	void	*img;

	if (tile != '1')
		mlx_put_image_to_window(game->gfx.mlx, game->gfx.window,
			game->gfx.img_floor, x * TILE_SIZE, y * TILE_SIZE);
	if (game->player.x == x && game->player.y == y)
	{
		draw_transparent_sprite(game, game->gfx.img_player,
			x * TILE_SIZE, y * TILE_SIZE);
		return ;
	}
	img = get_tile_sprite(game, tile);
	if (!img)
		return ;
	if (tile == '0' || tile == '1')
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
}
