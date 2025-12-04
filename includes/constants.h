/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:47:20 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/12/04 15:36:13 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

/* ========================================================================== */
/*                                 Tile Size                                  */
/* ========================================================================== */

# define TILE_SIZE 32

/* ========================================================================== */
/*                              MAP CHARACTERS                                */
/* ========================================================================== */

# define CHAR_EMPTY '0'
# define CHAR_WALL '1'
# define CHAR_COLLECTIBLE 'C'
# define CHAR_EXIT 'E'
# define CHAR_PLAYER 'P'
# define CHAR_ENEMY 'D'

/* ========================================================================== */
/*                              KEY CODES (Linux)                             */
/* ========================================================================== */

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

/* ========================================================================== */
/*                              EVENT CODES                                   */
/* ========================================================================== */

# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_DESTROY_NOTIFY 17

/* ========================================================================== */
/*                              ERROR MESSAGES                                */
/* ========================================================================== */

# define ERR_ARGS "Usage: ./so_long <map.ber>\n"
# define ERR_FILE_OPEN "Could not open file\n"
# define ERR_FILE_EXTENSION "File must have .ber extension\n"
# define ERR_FILE_EMPTY "The File is Empty\n"
# define ERR_MAP_NOT_RECTANGULAR "Map is not rectangular\n"
# define ERR_MAP_NO_WALLS "Map must be surrounded by walls\n"
# define ERR_MAP_INVALID_CHAR "Map contains invalid characters\n"
# define ERR_MAP_NO_PLAYER "Map must have exactly one player (P)\n"
# define ERR_MAP_NO_EXIT "Map must have exactly one exit (E)\n"
# define ERR_MAP_NO_COLLECTIBLES "Map must have at one collectible\n"
# define ERR_MAP_NO_PATH "No valid path to collect all and reach exit\n"
# define ERR_MEM_ALLOC "Memory allocation failed\n"
# define ERR_MLX_INIT "Failed to initialize MiniLibX\n"
# define ERR_WINDOW "Failed to create window\n"
# define ERR_IMAGE "Failed to load image\n"

#endif
