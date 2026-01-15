/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:47:07 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/15 21:10:00 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* ========================================================================== */
/*                              MAP STRUCTURE                                 */
/* ========================================================================== */

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles_counter;
	int		collected_counter;
	int		enemies_counter;
	int		enemies_killed;
	int		exit_x;
	int		exit_y;
}	t_map;

/* ========================================================================== */
/*                              PLAYER STRUCTURE                              */
/* ========================================================================== */

typedef struct s_player
{
	int	x;
	int	y;
	int	moves_counter;
	int	facing_right;
}	t_player;

/* ========================================================================== */
/*                              GRAPHICS STRUCTURE                            */
/* ========================================================================== */

typedef struct s_graphics
{
	void	*mlx;
	void	*window;
	void	*img_floor;
	void	*img_wall;
	void	*img_collectibles;
	void	*img_exit;
	void	*img_player;
	void	*img_player_left;
	void	*img_enemy;
	void	*img_dead_enemy;
	void	*img_attack;
	int		tile_size;
}	t_graphics;

/* ========================================================================== */
/*                              MAIN GAME STRUCTURE                           */
/* ========================================================================== */

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_graphics	gfx;
}	t_game;

#endif
