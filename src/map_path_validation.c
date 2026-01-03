/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:31:17 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/03 09:52:43 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**create_visited_map(t_game *game)
{
	char	**visited;
	int		i;
	int		j;

	visited = malloc(sizeof(char *) * game->map.height);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		visited[i] = malloc(sizeof(char *) * game->map.width);
		if (!visited[i])
			return (NULL);
		j = 0;
		while (j < game->map.width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (visited);
}

static void	free_visited_map(char **visited, int height)
{
	int	i;

	if (!visited)
		return ;
	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static void	flood_fill(t_game *game, char **visited, int x, int y)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return ;
	if (visited[y][x] == 1)
		return ;
	if (game->map.grid[y][x] == '1')
		return ;
	visited[y][x] = 1;
	flood_fill(game, visited, x + 1, y);
	flood_fill(game, visited, x - 1, y);
	flood_fill(game, visited, x, y + 1);
	flood_fill(game, visited, x, y - 1);
}

static int	count_reachable(t_game *game, char **visited)
{
	int	i;
	int	j;
	int	collectibles;

	i = 0;
	collectibles = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (visited[i][j] == 1 && game->map.grid[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	return (collectibles);
}

int	check_valid_path(t_game *game)
{
	char	**visited;
	int		reachable;

	visited = create_visited_map(game);
	if (!visited)
		return (0);
	flood_fill(game, visited, game->player.x, game->player.y);
	reachable = count_reachable(game, visited);
	if (visited[game->map.exit_y][game->map.exit_x] != 1)
		reachable = -1;
	free_visited_map(visited, game->map.height);
	if (reachable == game->map.collectibles_counter)
		return (1);
	return (0);
}
