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

static void	draw_vertical_stripe(t_game *game, t_mlx_image *texture, int x)
{
	t_player_data	*player;
	t_point			start;
	t_point			end;

	player = &(game->player_data);
	reassign_point(&start, x, 0);
	reassign_point(&end, x, player->draw_start - 1);
	if (player->draw_start > 0)
		mlx_draw_vertical_line(&(game->mlx_data.image), \
			start, end, game->scene_data.ceiling_color);
	start.y = player->draw_start;
	while (start.y < player->draw_end)
	{
		player->y_tex = (int)(player->pos_tex) % texture->height;
		player->pos_tex += player->step_tex;
		mlx_pixel_set(&(game->mlx_data.image), start.x, start.y, \
			mlx_pixel_get(texture, texture->width - player->x_tex - 1, \
				player->y_tex));
		(start.y) += 1;
	}
	start.y = player->draw_end;
	end.y = game->mlx_data.height - 1;
	mlx_draw_vertical_line(&(game->mlx_data.image), \
		start, end, game->scene_data.floor_color);
}

static void	set_texture(t_game *game, t_mlx_image *texture)
{
	t_player_data	*player;

	player = &(game->player_data);
	player->x_tex = (int)(player->x_w_coord * (double)(texture->width));
	if (player->side == 0 && player->rc_dir_x > 0)
		player->x_tex = texture->width - player->x_tex - 1;
	if (player->side == 1 && player->rc_dir_y < 0)
		player->x_tex = texture->width - player->x_tex - 1;
	player->step_tex = 1.0 * texture->height / player->line_height;
	player->pos_tex = (player->draw_start - game->mlx_data.height / 2 \
		+ player->line_height / 2) * player->step_tex;
}

static void	set_x_wall_coordinate(t_game *game, t_mlx_image **texture)
{
	t_player_data	*player;

	player = &(game->player_data);
	if (player->side == 0)
	{
		if (player->rc_dir_x >= 0)
			*texture = &(game->scene_data.textures.walls.east);
		else
			*texture = &(game->scene_data.textures.walls.west);
		player->x_w_coord = player->pos_y \
			+ player->wall_distance * player->rc_dir_y;
	}
	else
	{
		if (player->rc_dir_y >= 0)
			*texture = &(game->scene_data.textures.walls.south);
		else
			*texture = &(game->scene_data.textures.walls.north);
		player->x_w_coord = player->pos_x \
			+ player->wall_distance * player->rc_dir_x;
	}
	player->x_w_coord -= floor(player->x_w_coord);
}

static void	distance_from_plane(t_game *game)
{
	t_player_data	*player;

	player = &(game->player_data);
	if (player->side == 0)
		player->wall_distance = \
			(player->map_x - player->pos_x + (1 - player->step_x) / 2) \
			/ player->rc_dir_x;
	else
		player->wall_distance = \
			(player->map_y - player->pos_y + (1 - player->step_y) / 2) \
			/ player->rc_dir_y;
	player->line_height = (int)(game->mlx_data.height / player->wall_distance);
	player->draw_start = (-1 * player->line_height) / 2 + \
		game->mlx_data.height / 2;
	player->draw_end = player->line_height / 2 \
		+ game->mlx_data.height / 2;
	if (player->draw_start < 0 || player->draw_start >= game->mlx_data.height)
		player->draw_start = 0;
	if (player->draw_end >= game->mlx_data.height || player->draw_end < 0)
		player->draw_end = game->mlx_data.height - 1;
}

void	render_textures(t_game *game)
{
	int			x;
	t_mlx_image	*texture;

	x = 0;
	while (x < game->mlx_data.width)
	{
		digital_diferential_analysis(game, x);
		distance_from_plane(game);
		set_x_wall_coordinate(game, &texture);
		set_texture(game, texture);
		draw_vertical_stripe(game, texture, x);
		(game->player_data.z_buffer)[x] = game->player_data.wall_distance;
		x++;
	}
}
