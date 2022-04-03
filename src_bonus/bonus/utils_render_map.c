/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:26:17 by jcarrete          #+#    #+#             */
/*   Updated: 2021/05/03 13:20:07 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"

static void	mm_render_player(t_game *game)
{
	t_point		origen;
	t_point		dest;
	t_fpoint	ray;

	origen.x = adjust_player(game->player_data.pos_x);
	origen.y = adjust_player(game->player_data.pos_y);
	mlx_draw_player(&(game->mlx_data.image), \
		adjust_player(game->player_data.pos_x), \
		adjust_player(game->player_data.pos_y), CLR_BLUE);
	ray.x = -game->player_data.plane_x * 25;
	ray.y = -game->player_data.plane_y * 25;
	if (game->player_data.plane_x > 0)
		render_positive_x(game, origen, dest, ray);
	else
		render_negative_x(game, origen, dest, ray);
}

static void	draw_figure(t_game *game, int i, int j)
{
	if (game->scene_data.map_data.map[i][j] == '1')
		mlx_draw_rectangle(&(game->mlx_data.image), \
				game->minimap, CLR_WHITE);
	else if (game->scene_data.map_data.map[i][j] == 'p')
		mlx_draw_rectangle(&(game->mlx_data.image), \
				game->minimap, CLR_RED);
	else if (game->scene_data.map_data.map[i][j] == 'q')
		mlx_draw_rectangle(&(game->mlx_data.image), \
				game->minimap, CLR_GREEN);
	else if (game->scene_data.map_data.map[i][j] == '2')
		mlx_draw_rectangle(&(game->mlx_data.image), \
				game->minimap, CLR_PURPLE);
	else if (game->scene_data.map_data.map[i][j] == '3')
		mlx_draw_rectangle(&(game->mlx_data.image), \
				game->minimap, CLR_FUCHSIA);
	else
		mlx_draw_rectangle(&(game->mlx_data.image), \
				game->minimap, CLR_MAROON);
}

static void	mm_render_minimap(t_game *game)
{
	int		i;
	int		j;
	t_point	pos;

	i = -1;
	pos.x = game->minimap.x;
	pos.y = game->minimap.y;
	while (++i < (game->scene_data.map_data.height))
	{
		j = -1;
		game->minimap.x = pos.x;
		while (++j < (game->scene_data.map_data.width))
		{
			draw_figure(game, i, j);
			game->minimap.x = game->minimap.x + TILE_SIZE * MAP_SCALE;
		}
		game->minimap.y = game->minimap.y + TILE_SIZE * MAP_SCALE;
	}
	reassign_point(&(game->minimap), pos.x, pos.y);
}

void	mm_render_map(t_game *game)
{
	if ((game->mlx_data.height > \
		((game->scene_data.map_data.height * 64) * 0.15f)) && \
		(game->mlx_data.width > \
		((game->scene_data.map_data.width * 64) * 0.15f)))
	{
		mm_render_minimap(game);
		mm_render_player(game);
	}
}
