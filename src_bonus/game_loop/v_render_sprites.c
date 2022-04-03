/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_render_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:18:19 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/27 23:52:13 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"

static void	calculate_sprites_distance(t_game *game)
{
	int				i;
	t_sprites_data	*data;

	data = &(game->scene_data.sprites);
	i = 0;
	while (i < (data->num_sprites))
	{
		(game->scene_data.sprites.sprites)[i].dist = \
			(game->player_data.pos_x - (data->sprites)[i].x) \
			* (game->player_data.pos_x - (data->sprites)[i].x) \
			+ (game->player_data.pos_y - (data->sprites)[i].y) \
			* (game->player_data.pos_y - (data->sprites)[i].y);
		i++;
	}
}

static int	compare_function(const void *val1, const void *val2)
{
	t_sprite	*data1;
	t_sprite	*data2;

	data1 = ((t_sprite *)val1);
	data2 = ((t_sprite *)val2);
	if (data1->dist > data2->dist)
		return (-1);
	else if (data2->dist == data1->dist)
		return (0);
	return (1);
}

void	render_sprites(t_game *game)
{
	int			x;
	t_sprite	*data;

	data = game->scene_data.sprites.sprites;
	calculate_sprites_distance(game);
	ft_qsort_array(data, \
		(int)(game->scene_data.sprites.num_sprites), \
		sizeof(t_sprite), &compare_function);
	x = 0;
	while (x < (game->scene_data.sprites).num_sprites)
	{
		(game->scene_data.sprites).sprite_x = \
				(game->scene_data.sprites.sprites)[x].x
			- game->player_data.pos_x;
		(game->scene_data.sprites).sprite_y = \
			(game->scene_data.sprites.sprites)[x].y - game->player_data.pos_y;
		draw_sprite(game, (game->scene_data.sprites.sprites)[x].type);
		x++;
	}
}
