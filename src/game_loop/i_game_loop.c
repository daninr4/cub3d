/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_game_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:15:54 by jcarrete          #+#    #+#             */
/*   Updated: 2021/05/06 21:59:01 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"

static void	render_bmp(t_game *game)
{
	if (mlx_image_to_bmp(&(game->mlx_data.image), "screenshot.bmp") == -1)
		exit_failure(game, \
			"Failed creating image \"screenshot.bmp\": %s\n", \
			strerror(errno));
	else
		exit_success(game);
}

int	render_image(t_game *game)
{
	if (game->game_state == S_RUNNING)
	{
		process_input(game);
		if (LINUX == FALSE)
			mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, game->mlx_data.win);
		else
			mlx_do_sync(game->mlx_data.mlx);
	}
	render_textures(game);
	render_sprites(game);
	if (game->game_state == S_SAVEMODE)
		render_bmp(game);
	mlx_put_image_to_window(game->mlx_data.mlx, game->mlx_data.win, \
				game->mlx_data.image.img, 0, 0);
	return (EXIT_SUCCESS);
}

void	game_loop(t_game *game)
{
	mlx_do_key_autorepeatoff(game->mlx_data.mlx);
	mlx_hook(game->mlx_data.win, \
		KEY_PRESS, KEY_PRESS_MASK, key_press_use, game);
	mlx_hook(game->mlx_data.win, \
		KEY_RELEASE, KEY_RELEASE_MASK, key_release_use, game);
	if (LINUX == FALSE)
		mlx_hook(game->mlx_data.win, DESTROY_NOTIFY, \
			STRUCTURE_NOTIFY_MASK, exit_success, game);
	else
		mlx_hook(game->mlx_data.win, CLIENT_MESSAGE, \
			STRUCTURE_NOTIFY_MASK, exit_success, game);
	mlx_loop_hook(game->mlx_data.mlx, render_image, game);
	mlx_loop(game->mlx_data.mlx);
}
