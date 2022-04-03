/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:18:19 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/27 23:52:13 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"

static void	mouse_move_right(t_game *game, int diff, int x, int y)
{
	game->player_data.mousex = x;
	while (diff-- != 0)
		player_rotation(game, 1);
	if (x > (int)(game->mlx_data.width * 0.7))
	{
		mlx_mouse_move(game->mlx_data.mlx, game->mlx_data.win,
			(int)(game->mlx_data.width / 2), y);
		game->player_data.mousex = (int)(game->mlx_data.width / 2);
	}
}

static void	mouse_move_left(t_game *game, int diff, int x, int y)
{
	game->player_data.mousex = x;
	while (diff-- != 0)
		player_rotation(game, -1);
	if (x < (int)(game->mlx_data.width * 0.3))
	{
		mlx_mouse_move(game->mlx_data.mlx, game->mlx_data.win,
			(int)(game->mlx_data.width / 2), y);
		game->player_data.mousex = (int)(game->mlx_data.width / 2);
	}
}

int	event_mouse_move(int x, int y, t_game *game)
{
	int	diff;

	diff = abs(game->player_data.mousex - x);
	if (diff > 6)
		diff = 6;
	if (y < (int)(game->mlx_data.height * 0.3) || \
		y > (int)(game->mlx_data.height * 0.7))
		mlx_mouse_move(game->mlx_data.mlx, game->mlx_data.win, x,
			(int)(game->mlx_data.height / 2));
	if (x > game->player_data.mousex)
		mouse_move_right(game, diff, x, y);
	else if (x < game->player_data.mousex)
		mouse_move_left(game, diff, x, y);
	return (0);
}
