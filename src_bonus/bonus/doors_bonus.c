/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:14:46 by jcarrete          #+#    #+#             */
/*   Updated: 2021/05/17 19:09:07 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_door_closed(t_game *game)
{
	int	i;
	int	j;

	i = -2;
	j = -1;
	while (i++ < 2)
	{
		while (j < 2)
		{
			if (!(i == 0 && j == 0) && game->scene_data.map_data.map
				[(int)game->player_data.pos_y + j] \
				[(int) game->player_data.pos_x + i] == 'q')
				game->scene_data.map_data.map[(int)game->player_data.pos_y + j] \
					[(int) game->player_data.pos_x + i] = 'p';
			j++;
		}
		j = -1;
	}
	if (game->scene_data.map_data.map[game->player_data.mid_ray_y] \
		[game->player_data.mid_ray_x] == 'p' && \
		game->player_data.mid_wall_distance <= 1)
		game->scene_data.map_data.map[game->player_data.mid_ray_y] \
			[game->player_data.mid_ray_x] = 'q';
}
