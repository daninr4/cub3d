/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iii_init_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 22:20:29 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/12 21:45:06 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_loop.h"

static void	create_image(t_game *game)
{
	game->mlx_data.image.width = game->mlx_data.width;
	game->mlx_data.image.height = game->mlx_data.height;
	game->mlx_data.image.img = mlx_new_image(game->mlx_data.mlx, \
			game->mlx_data.image.width, game->mlx_data.image.height);
	if (game->mlx_data.image.img == NULL)
		exit_failure(game, "Failed creating mlx image: %s\n", strerror(errno));
	game->mlx_data.image.addr = \
			mlx_get_data_addr(game->mlx_data.image.img, \
			&(game->mlx_data.image.bits_per_pixel), \
			&(game->mlx_data.image.line_length), \
			&(game->mlx_data.image.endian));
	if (game->game_state == S_RENDER_START)
		game->game_state = S_RENDER_STARTED;
}

void	initialize_window(t_game *game)
{
	game->player_data.z_buffer = \
		(double *)(ft_memalloc(sizeof(double) * game->mlx_data.width));
	if (game->player_data.z_buffer == NULL)
		exit_failure(game, "Failed Z_Buffer allocation: %s\n", strerror(errno));
	create_image(game);
	if (game->game_state == S_SAVEMODE)
		render_image(game);
	else
	{
		game->mlx_data.win = mlx_new_window(game->mlx_data.mlx, \
			game->mlx_data.width, game->mlx_data.height, WINDOW_TITLE);
		if (game->mlx_data.win == NULL)
			exit_failure(game, "Failed to create a new Window\n");
		game->game_state = S_RUNNING;
	}
}
