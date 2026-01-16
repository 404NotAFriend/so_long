/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:32:26 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/16 01:48:03 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_tile_sprite(t_game *game, char tile)
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
	else if (tile == 'N')
		return (game->gfx.img_enemy);
	return (NULL);
}

void	draw_transparent_sprite(t_game *game, void *img, int x, int y)
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

void	render_player(t_game *game, int x, int y)
{
	if (game->player.is_attacking)
	{
		if (game->player.facing_right)
			draw_transparent_sprite(game, game->gfx.img_attack,
				x * TILE_SIZE, y * TILE_SIZE);
		else
			draw_transparent_sprite(game, game->gfx.img_attack_left,
				x * TILE_SIZE, y * TILE_SIZE);
	}
	else
	{
		if (game->player.facing_right)
			draw_transparent_sprite(game, game->gfx.img_player,
				x * TILE_SIZE, y * TILE_SIZE);
		else
			draw_transparent_sprite(game, game->gfx.img_player_left,
				x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	display_moves(t_game *game)
{
	char	*moves_num;
	char	*full_text;

	moves_num = ft_itoa(game->player.moves_counter);
	if (!moves_num)
		return ;
	full_text = ft_strjoin("Moves: ", moves_num);
	free(moves_num);
	if (!full_text)
		return ;
	mlx_string_put(game->gfx.mlx, game->gfx.window,
		10, 20, 0xFFFFFF, full_text);
	free(full_text);
}
