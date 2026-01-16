/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:59:53 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/16 02:54:48 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "so_long.h"

void	error_exit(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit(1);
}

void	free_map(t_game *game)
{
	int	i;

	if (!game->map.grid)
		return ;
	i = 0;
	while (i < game->map.height)
	{
		free(game->map.grid[i]);
		i++;
	}
	free(game->map.grid);
	game->map.grid = NULL;
}

static void	destroy_images(t_game *game)
{
	if (game->gfx.img_floor)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_floor);
	if (game->gfx.img_wall)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_wall);
	if (game->gfx.img_player)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_player);
	if (game->gfx.img_player_left)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_player_left);
	if (game->gfx.img_collectibles)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_collectibles);
	if (game->gfx.img_exit)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_exit);
	if (game->gfx.img_enemy)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_enemy);
	if (game->gfx.img_dead_enemy)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_dead_enemy);
	if (game->gfx.img_attack)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_attack);
	if (game->gfx.img_attack_left)
		mlx_destroy_image(game->gfx.mlx, game->gfx.img_attack_left);
}

void	cleanup_and_exit(t_game *game, int exit_code)
{
	if (game->gfx.mlx)
	{
		destroy_images(game);
		if (game->gfx.window)
			mlx_destroy_window(game->gfx.mlx, game->gfx.window);
		mlx_destroy_display(game->gfx.mlx);
		free(game->gfx.mlx);
	}
	free_map(game);
	exit(exit_code);
}
