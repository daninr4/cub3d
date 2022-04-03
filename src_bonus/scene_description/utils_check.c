/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 23:28:10 by jcarrete          #+#    #+#             */
/*   Updated: 2021/05/03 12:49:00 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_description.h"

void	spritelst_clear(t_spritelst **lst)
{
	t_spritelst	*aux;

	while (*lst)
	{
		aux = *lst;
		*lst = (*lst)->next;
		free(aux);
	}
}

static void	check_position(t_game *game, int x, int y, char c)
{
	t_map_data	*md;

	md = &(game->scene_data.map_data);
	if (x > 0 && x < md->width - 1 && \
			y > 0 && y < md->height - 1 && \
			md->map[y][x] == c)
		exit_failure(game, "Map error at position [%s][%s]\n", \
			ft_itoa(x), ft_itoa(y));
}

void	check_round_spaces(t_game *game, t_point *pos)
{
	int			x;
	int			y;

	x = (int)(pos->x);
	y = (int)(pos->y);
	check_position(game, x - 1, y, ' ');
	check_position(game, x - 1, y - 1, ' ');
	check_position(game, x, y - 1, ' ');
	check_position(game, x + 1, y - 1, ' ');
	check_position(game, x + 1, y, ' ');
	check_position(game, x + 1, y + 1, ' ');
	check_position(game, x, y + 1, ' ');
	check_position(game, x - 1, y + 1, ' ');
	if (ft_strchr("023pNSWE", (game->scene_data.map_data.map)[y][x]) && \
		(x == (game->scene_data.map_data.width - 1) || \
		y == (game->scene_data.map_data.height - 1) || \
		(x == 0) || (y == 0)))
		exit_failure(game, "Map error at position [%s][%s]\n", \
			ft_itoa(x), ft_itoa(y));
}

void	check_door(t_game *game, t_point *pos)
{
	int	x;
	int	y;

	x = (int)(pos->x);
	y = (int)(pos->y);
	if (game->scene_data.map_data.map[y][x - 1] == '1' && \
		game->scene_data.map_data.map[y][x - 1] == '1')
	{
		if (game->scene_data.map_data.map[y - 1][x] != '0' || \
			game->scene_data.map_data.map[y + 1][x] != '0')
			exit_failure(game, "Vertical door error at position [%s][%s]\n", \
				ft_itoa(x), ft_itoa(y));
	}
	else if (game->scene_data.map_data.map[y - 1][x] == '1' && \
		game->scene_data.map_data.map[y + 1][x] == '1')
	{
		if (game->scene_data.map_data.map[y][x - 1] != '0' || \
			game->scene_data.map_data.map[y][x + 1] != '0')
			exit_failure(game, "Horizontal door error at position [%s][%s]\n", \
				ft_itoa(x), ft_itoa(y));
	}
	else
		exit_failure(game, "Door error at position [%s][%s]\n", \
				ft_itoa(x), ft_itoa(y));
}
