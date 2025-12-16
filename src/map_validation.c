/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:04:46 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/12/16 12:20:42 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_rectangular(t_game *game)
{
	int	i;
	int	len;

	if (game->map.height == 0)
		return (0);
	len = ft_strlen(game->map.grid[0]);
	if (game->map.grid[0][len - 1] == '\n')
		len--;
	i = 1;
	while (i < game->map.height)
	{
		if((int)ft_strlen(game->map.grid[i]) != len
			&& (int)ft_strlen(game->map.grid[i]) != len + 1)
			return (0);
		i++;
	}
	return (1);
}
