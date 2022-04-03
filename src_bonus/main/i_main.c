/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:40:42 by jcarrete          #+#    #+#             */
/*   Updated: 2021/05/04 21:29:24 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_loop_bonus.h"

static void	check_arguments(t_game *game, int argc, char **argv)
{
	size_t	len;

	if (argc < 2)
		exit_failure(game, "No map specified.\
			Program requires at least one FILE.cub argument.\n");
	else if (argc > 3)
		exit_failure(game, "Too many arguments.\n");
	else
	{
		len = ft_strlen(argv[1]);
		if (len < 4 || ft_strrncmp(argv[1], ".cub", 4))
			exit_failure(game, "Unknown file type: %s.\
				Please introduce a FILE.cub argument.\n", argv[1]);
		if (argc == 2)
			game->game_state = S_RENDER_START;
		else if (argc == 3)
		{
			if (!ft_strcmp("--save", argv[2]))
				game->game_state = S_SAVEMODE;
			else
				exit_failure(game, "Unknown argument: %s\n", argv[2]);
		}
	}
}

static void	setup(t_game *game, char *arg)
{
	initialize_game_struct(game);
	load_textures(game);
	load_scene_description(game, arg);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (game == NULL)
		exit_failure(game, "Unable to allocate memory: %s\n", strerror(errno));
	game->game_state = 0;
	check_arguments(game, argc, argv);
	setup(game, argv[1]);
	initialize_window(game);
	game_loop(game);
	free_game(game);
	return (EXIT_SUCCESS);
}
