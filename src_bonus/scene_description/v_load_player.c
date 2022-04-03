/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_load_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:23:16 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/12 21:50:22 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_description.h"

static void	set_player(t_game *game, char obj)
{
	int	sign;

	if (obj == 'N' || obj == 'S')
	{
		sign = 1 - (2 * (obj == 'S'));
		game->player_data.dir_x = 0;
		game->player_data.dir_y = -1 * sign;
		game->player_data.plane_x = tan(deg_to_rad(PLAYER_FOV) / 2) * sign;
		game->player_data.plane_y = 0;
	}
	else if (obj == 'W' || obj == 'E')
	{
		sign = 1 - (2 * (obj == 'W'));
		game->player_data.dir_x = 1 * sign;
		game->player_data.dir_y = 0;
		game->player_data.plane_x = 0;
		game->player_data.plane_y = tan(deg_to_rad(PLAYER_FOV) / 2) * sign;
	}
}

void	load_player(t_game *game, t_point *pos, char obj)
{
	if (game->player_data.pos_x != -1)
		exit_failure(game, "Player can't be initialize twice");
	game->player_data.pos_x = pos->x + 0.5f;
	game->player_data.pos_y = pos->y + 0.5f;
	set_player(game, obj);
}
