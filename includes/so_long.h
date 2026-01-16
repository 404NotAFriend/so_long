/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:46:39 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/16 16:00:28 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ========================================================================== */
/*                              INCLUDES                                      */
/* ========================================================================== */

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "constants.h"
# include "structs.h"

/* ========================================================================== */
/*                              MAP READER                                    */
/* ========================================================================== */

void	read_map(char *filename, t_game *game);

/* ========================================================================== */
/*                              MAP VALIDATION                                */
/* ========================================================================== */

int		validate_map(t_game *game);
int		check_rectangular(t_game *game);
int		check_walls(t_game *game);
int		check_characters(t_game *game);
int		check_valid_path(t_game *game);
void	count_map_elements(t_game *game);
void	count_elements_loop(t_game *game, int *players, int *exits,
			int *collectibles);

/* ========================================================================== */
/*                              INITIALIZATION                                */
/* ========================================================================== */

void	init_game(t_game *game);
void	init_graphics(t_game *game);
void	load_sprites(t_game *game);

/* ========================================================================== */
/*                              RENDERING                                     */
/* ========================================================================== */

void	render_game(t_game *game);
void	render_tile(t_game *game, int x, int y, char tile);
void	render_player(t_game *game, int x, int y);
void	render_player_only(t_game *game);
void	display_moves(t_game *game);
void	print_map(t_game *game);
void	*get_tile_sprite(t_game *game, char tile);
void	draw_transparent_sprite(t_game *game, void *img, int x, int y);

/* ========================================================================== */
/*                              INPUT HANDLER                                 */
/* ========================================================================== */

int		key_press(int keycode, t_game *game);
int		close_window(t_game *game);

/* ========================================================================== */
/*                              GAME LOGIC                                    */
/* ========================================================================== */

void	move_player(t_game *game, int dx, int dy);
void	attack_enemy(t_game *game);
void	check_collectible(t_game *game, int x, int y);
void	check_exit(t_game *game, int x, int y);

/* ========================================================================== */
/*                              GAME SCREENS                                  */
/* ========================================================================== */

void	show_game_over(t_game *game);
void	show_victory(t_game *game);

/* ========================================================================== */
/*                              CLEANUP & EXIT                                */
/* ========================================================================== */

void	cleanup_and_exit(t_game *game, int exit_code);
void	free_map(t_game *game);
void	error_exit(char *message);

#endif
