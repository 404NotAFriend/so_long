/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:51:25 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/12/16 11:58:29 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static int	check_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit(ERR_ARGS);
	if (!check_file_extension(argv[1]))
		error_exit(ERR_FILE_EXTENSION);
	ft_bzero(&game, sizeof(t_game));
	ft_printf("\n\n✅ Arguments Validated!\n");
	ft_printf("Map file: %s\n", argv[1]);
	read_map(argv[1], &game);
	print_map(&game);
	cleanup_and_exit(&game, 0);
}
