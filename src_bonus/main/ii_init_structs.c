/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ii_init_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:20:38 by jcarrete          #+#    #+#             */
/*   Updated: 2021/05/04 21:28:37 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_loop.h"

void	init_mlx_data(t_game *game)
{
	(game->mlx_data).mlx = mlx_init();
	if ((game->mlx_data).mlx == NULL)
		exit_failure(game, "Failed initializing MLX\n");
	(game->mlx_data).win = NULL;
	(game->mlx_data).image.img = NULL;
	(game->mlx_data).width = 0;
	(game->mlx_data).height = 0;
	(game->mlx_data).timestamp_start = clock();
}

void	init_keycode_states(t_keycode_states *states)
{
	states->key_a = KEY_RELEASED;
	states->key_w = KEY_RELEASED;
	states->key_s = KEY_RELEASED;
	states->key_d = KEY_RELEASED;
	states->key_down = KEY_RELEASED;
	states->key_up = KEY_RELEASED;
	states->key_left = KEY_RELEASED;
	states->key_right = KEY_RELEASED;
}

void	init_player(t_player_data *player)
{
	player->pos_x = -1;
	player->pos_y = -1;
	player->move_speed = PLAYER_MOVE_SPEED;
	player->rot_speed = PLAYER_ROT_SPEED;
	player->fov_angle = PLAYER_FOV * (PI / 180);
}

void	init_scene(t_scene_data *scene)
{
	scene->sprites.num_sprites = 0;
	scene->ceiling_color = -1;
	scene->floor_color = -1;
	scene->map_data.ones = 0;
	scene->textures.num_dif_sprites = 0;
}

void	initialize_game_struct(t_game *game)
{
	game->minimap.x = MINIMAP_OFFSET;
	game->minimap.y = MINIMAP_OFFSET;
	init_mlx_data(game);
	init_keycode_states(&(game->keycode_states));
	init_player(&(game->player_data));
	init_scene(&(game->scene_data));
}
