/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iv_render_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:09:26 by jcarrete          #+#    #+#             */
/*   Updated: 2021/05/31 23:10:08 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"

t_mlx_image	*select_texture(t_game *game, \
	t_player_data *player, double dir)
{
	if (game->scene_data.map_data.map[player->map_y][player->map_x] == '1')
	{
		if (dir >= 0)
			return (&(game->scene_data.textures.walls.east));
		else
			return (&(game->scene_data.textures.walls.west));
	}
	else
		return (&(game->scene_data.textures.door));
}
