/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:10:32 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/12/16 14:44:37 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	count_elements_loop(t_game *game, int *players, int *exits,
		int *collectibles)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.grid[i][j] == 'P')
				(*players)++;
			else if (game->map.grid[i][j] == 'E')
				(*exits)++;
			else if (game->map.grid[i][j] == 'C')
				(*collectibles)++;
			j++;
		}
		i++;
	}
}

void	count_map_elements(t_game *game)
{
	int	players;
	int	exits;
	int	collectibles;

	players = 0;
	exits = 0;
	collectibles = 0;
	count_elements_loop(game, &players, &exits, &collectibles);
	ft_printf("\n📊 Map Statistics:\n");
	ft_printf("👤 Players (P): %d\n", players);
	ft_printf("🚪 Exits (E): %d\n", exits);
	ft_printf("💎 Collectibles (C): %d\n\n", collectibles);
}
