/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:46:39 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/12/04 13:31:04 by bramalho@st      ###   ########.fr       */
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
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
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

/* ========================================================================== */
/*                              INPUT HANDLER                                 */
/* ========================================================================== */

int		key_press(int keycode, t_game *game);
int		close_window(t_game *game);

/* ========================================================================== */
/*                              GAME LOGIC                                    */
/* ========================================================================== */

void	move_player(t_game *game, int dx, int dy);
void	check_collectible(t_game *game, int x, int y);
void	check_exit(t_game *game, int x, int y);

/* ========================================================================== */
/*                              CLEANUP & EXIT                                */
/* ========================================================================== */

void	cleanup_and_exit(t_game *game, int exit_code);
void	free_map(t_game *game);
void	destroy_images(t_game *game);
void	error_exit(char *message);

#endif
