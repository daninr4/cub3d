/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digital_diferential_analysis.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:16:29 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/15 23:09:57 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"

static void	perform_dda(t_player_data *player, t_map_data *map)
{
	while (player->hit == FALSE)
	{
		if (player->side_dist_x < player->side_dist_y)
		{
			player->side_dist_x += player->delta_x;
			player->map_x += player->step_x;
			player->side = 0;
		}
		else
		{
			player->side_dist_y += player->delta_y;
			player->map_y += player->step_y;
			player->side = 1;
		}
		if (ft_strchr(NOT_TRAVERSABLE, map->map[player->map_y][player->map_x]))
			player->hit = TRUE;
	}
}

static void	set_step_dda(t_player_data *player)
{
	if (player->rc_dir_x < 0)
	{
		player->step_x = -1;
		player->side_dist_x = \
			(player->pos_x - player->map_x) * player->delta_x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist_x = \
			(player->map_x + 1.0 - player->pos_x) * player->delta_x;
	}
	if (player->rc_dir_y < 0)
	{
		player->step_y = -1;
		player->side_dist_y = \
			(player->pos_y - player->map_y) * player->delta_y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist_y = \
			(player->map_y + 1.0 - player->pos_y) * player->delta_y;
	}
}

void	digital_diferential_analysis(t_game *game, int x)
{
	t_player_data	*player;

	player = &(game->player_data);
	player->camera_x = 2 * x / (double)(game->mlx_data.width) - 1;
	player->rc_dir_x = player->dir_x + player->plane_x * player->camera_x;
	player->rc_dir_y = player->dir_y + player->plane_y * player->camera_x;
	player->map_x = (int)player->pos_x;
	player->map_y = (int)player->pos_y;
	if (player->rc_dir_x != 0)
		player->delta_x = ft_absd(1.0 / player->rc_dir_x);
	if (player->rc_dir_y != 0)
		player->delta_y = ft_absd(1.0 / player->rc_dir_y);
	player->hit = FALSE;
	set_step_dda(player);
	perform_dda(player, &(game->scene_data.map_data));
}
