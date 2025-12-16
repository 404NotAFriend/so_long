/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:20:28 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/12/16 11:02:15 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**realloc_grid(char **grid, int new_size)
{
	char	**new_grid;
	int		i;

	new_grid = malloc(sizeof(char *) * (new_size + 1));
	if (!new_grid)
		return (NULL);
	i = 0;
	if (grid)
	{
		while (i < new_size - 1)
		{
			new_grid[i] = grid[i];
			i++;
		}
		free(grid);
	}
	new_grid[new_size - 1] = NULL;
	new_grid[new_size] = NULL;
	return (new_grid);
}

void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(ERR_FILE_OPEN);
	game->map.height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map.grid = realloc_grid(game->map.grid, game->map.height + 1);
		if (!game->map.grid)
			error_exit(ERR_MEM_ALLOC);
		game->map.grid[game->map.height] = line;
		game->map.height++;
	}
	close(fd);
	if (game->map.height == 0)
		error_exit(ERR_FILE_EMPTY);
	game->map.width = ft_strlen(game->map.grid[0]);
	if (game->map.grid[0][game->map.width - 1] == '\n')
		game->map.width--;
}
