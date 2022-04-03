/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_draw_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:06:03 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/12 21:29:23 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"

static void	put_color_sprite(t_textures *tex, t_mlx_data *md, \
								t_sprites_data *sd)
{
	int			c;

	c = mlx_pixel_get(&(tex)->sprite, sd->tex_x, sd->tex_y);
	if (c != CLR_BACKGROUND)
		mlx_pixel_set(&(md->image), sd->stripe, sd->y, c);
}

static void	loop_vertical_stripe(t_game *game, t_sprites_data *sd)
{
	t_textures	*tex;
	t_mlx_data	*md;

	tex = &(game->scene_data.textures);
	md = &(game->mlx_data);
	sd->stripe = sd->d_start_x;
	while (sd->stripe < sd->d_end_x)
	{
		sd->tex_x = (int)(256 * (sd->stripe - (-1 * sd->s_width / 2 \
			+ sd->sscreen_x)) * tex->sprite.width / sd->s_width) / 256;
		sd->y = sd->d_start_y;
		if (sd->transform_y > 0 && sd->stripe > 0 && sd->stripe < md->width \
			&& sd->transform_y < (game->player_data.z_buffer)[sd->stripe])
		{
			while (sd->y < sd->d_end_y)
			{
				sd->d = sd->y * 256 - md->height * 128 + sd->s_height * 128;
				sd->tex_y = ((sd->d * tex->sprite.height) / sd->s_height) / 256;
				put_color_sprite(tex, md, sd);
				(sd->y)++;
			}
		}
		(sd->stripe)++;
	}
}

static void	calculate_sprite(t_game *game, t_sprites_data *data)
{
	data->s_height = \
		ft_abs((int)(game->mlx_data.image.height / data->transform_y));
	data->d_start_y = (-1 * data->s_height / 2) \
				+ game->mlx_data.image.height / 2;
	data->d_end_y = data->s_height / 2 + game->mlx_data.image.height / 2;
	if (data->d_start_y < 0)
		data->d_start_y = 0;
	if (data->d_end_y >= game->mlx_data.image.height)
		data->d_end_y = game->mlx_data.image.height - 1;
	data->s_width = \
		ft_abs((int)(game->mlx_data.image.height / data->transform_y));
	data->d_start_x = -1 * data->s_width / 2 + data->sscreen_x;
	data->d_end_x = data->s_width / 2 + data->sscreen_x;
	if (data->d_start_x < 0)
		data->d_start_x = 0;
	if (data->d_end_x >= game->mlx_data.image.width)
		data->d_end_x = game->mlx_data.image.width - 1;
	loop_vertical_stripe(game, data);
}

void	draw_sprite(t_game *game)
{
	t_player_data	*player;
	t_sprites_data	*data;

	player = &(game->player_data);
	data = &(game->scene_data.sprites);
	data->inv_matrix = 1.0f / (player->plane_x * player->dir_y \
					- player->plane_y * player->dir_x);
	data->transform_x = data->inv_matrix * (player->dir_y * data->sprite_x \
					- player->dir_x * data->sprite_y);
	data->transform_y = data->inv_matrix * ((-1 * player->plane_y * \
					data->sprite_x) + player->plane_x * data->sprite_y);
	data->sscreen_x = (int)(game->mlx_data.image.width / 2 \
					* (1 + data->transform_x / data->transform_y));
	calculate_sprite(game, data);
}
