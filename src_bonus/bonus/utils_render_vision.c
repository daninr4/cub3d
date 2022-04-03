/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_vision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:26:17 by jcarrete          #+#    #+#             */
/*   Updated: 2021/05/03 13:20:07 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"

static void	draw_ray(t_game *game, t_point origen, \
	t_point dest, t_fpoint ray)
{
	dest.x = adjust_player(game->player_data.pos_x) + \
		adjust_ray(game->player_data.dir_x * 25) - adjust_ray(ray.x);
	dest.y = adjust_player(game->player_data.pos_y) + \
		adjust_ray(game->player_data.dir_y * 25) - adjust_ray(ray.y);
	mlx_draw_line(&(game->mlx_data.image), \
		origen, \
		dest, \
		CLR_BLUE);
}

double	adjust_player(double point)
{
	return ((point * 9) + 10);
}

double	adjust_ray(double point)
{
	return ((point * 9));
}

void	render_positive_x(t_game *game, t_point origen, \
	t_point dest, t_fpoint ray)
{
	if (game->player_data.plane_y > 0)
	{
		while (ray.x < game->player_data.plane_x * 25 || \
			ray.y < game->player_data.plane_y * 25)
		{
			draw_ray(game, origen, dest, ray);
			if (ray.x < game->player_data.plane_x * 25)
				ray.x += 0.1;
			if (ray.y < game->player_data.plane_y * 25)
				ray.y += 0.1;
		}
	}
	else
	{
		while (ray.x < game->player_data.plane_x * 25 || \
			ray.y > game->player_data.plane_y * 25)
		{
			draw_ray(game, origen, dest, ray);
			if (ray.x < game->player_data.plane_x * 25)
				ray.x += 0.1;
			if (ray.y > game->player_data.plane_y * 25)
				ray.y -= 0.1;
		}
	}
}

void	render_negative_x(t_game *game, t_point origen,
	t_point dest, t_fpoint ray)
{
	if (game->player_data.plane_y > 0)
	{
		while (ray.x > game->player_data.plane_x * 25 || \
			ray.y < game->player_data.plane_y * 25)
		{
			draw_ray(game, origen, dest, ray);
			if (ray.x > game->player_data.plane_x * 25)
				ray.x -= 0.1;
			if (ray.y < game->player_data.plane_y * 25)
				ray.y += 0.1;
		}
	}
	else
	{
		while (ray.x > game->player_data.plane_x * 25 || \
			ray.y > game->player_data.plane_y * 25)
		{
			draw_ray(game, origen, dest, ray);
			if (ray.x > game->player_data.plane_x * 25)
				ray.x -= 0.1;
			if (ray.y > game->player_data.plane_y * 25)
				ray.y -= 0.1;
		}
	}	
}
