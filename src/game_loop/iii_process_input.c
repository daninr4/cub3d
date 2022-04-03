/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iii_process_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:04:35 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/12 21:37:25 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"

static void	player_rotation(t_game *game, int v)
{
	double	last_dir;
	double	last_plane;

	last_dir = game->player_data.dir_x;
	last_plane = game->player_data.plane_x;
	game->player_data.dir_x = \
		game->player_data.dir_x * cos(v * game->player_data.rot_speed) \
		- game->player_data.dir_y * sin(v * game->player_data.rot_speed);
	game->player_data.dir_y = \
		last_dir * sin(v * game->player_data.rot_speed) \
		+ game->player_data.dir_y * cos(v * game->player_data.rot_speed);
	game->player_data.plane_x = \
		game->player_data.plane_x * cos(v * game->player_data.rot_speed) \
		- game->player_data.plane_y * sin(v * game->player_data.rot_speed);
	game->player_data.plane_y = \
		last_plane * sin(v * game->player_data.rot_speed) \
		+ game->player_data.plane_y * cos(v * game->player_data.rot_speed);
}

static void	player_movement_horizontal(t_game *game, int v)
{
	double	dir_x;
	double	dir_y;

	dir_x = game->player_data.dir_x;
	dir_y = game->player_data.dir_y;
	if ((game->scene_data.map_data.map)[(int)(game->player_data.pos_y)] \
			[(int)(game->player_data.pos_x + \
			((v * dir_y) * game->player_data.move_speed))] == '0')
		game->player_data.pos_x += (dir_y * game->player_data.move_speed * v);
	if ((game->scene_data.map_data.map)[(int)(game->player_data.pos_y - \
			((v * dir_x) * game->player_data.move_speed))] \
			[(int)(game->player_data.pos_x)] == '0')
		game->player_data.pos_y -= (dir_x * game->player_data.move_speed * v);
}

static void	player_movement_vertical(t_game *game, int v)
{
	double	dir_x;
	double	dir_y;

	dir_x = game->player_data.dir_x;
	dir_y = game->player_data.dir_y;
	if ((game->scene_data.map_data.map)[(int)(game->player_data.pos_y)] \
			[(int)(game->player_data.pos_x \
			+ ((v * dir_x) * game->player_data.move_speed))] == '0')
		game->player_data.pos_x += (dir_x * game->player_data.move_speed * v);
	if ((game->scene_data.map_data.map)[(int)(game->player_data.pos_y \
			+ ((v * dir_y) * game->player_data.move_speed))] \
			[(int)(game->player_data.pos_x)] == '0')
		game->player_data.pos_y += (dir_y * game->player_data.move_speed * v);
}

void	process_input(t_game *game)
{
	t_keycode_states	*k_s;

	k_s = &(game->keycode_states);
	if (k_s->key_w == KEY_PRESSED)
		player_movement_vertical(game, 1);
	if (k_s->key_s == KEY_PRESSED)
		player_movement_vertical(game, -1);
	if (k_s->key_a == KEY_PRESSED)
		player_movement_horizontal(game, 1);
	if (k_s->key_d == KEY_PRESSED)
		player_movement_horizontal(game, -1);
	if (k_s->key_right == KEY_PRESSED)
		player_rotation(game, 1);
	if (k_s->key_left == KEY_PRESSED)
		player_rotation(game, -1);
}
