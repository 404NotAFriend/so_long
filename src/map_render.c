/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:04:42 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/12/16 12:04:32 by bramalho@st      ###   ########.fr       */
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
