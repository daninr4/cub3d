/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iv_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:09:01 by jcarrete          #+#    #+#             */
/*   Updated: 2021/05/03 12:20:03 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_description.h"

static void	load_sprites(t_game *game, t_spritelst *lst)
{
	t_sprites_data	*data;
	int				i;

	data = &(game->scene_data.sprites);
	data->sprites = ft_memalloc(data->num_sprites * sizeof(t_sprite));
	if (data->sprites == NULL)
		exit_failure(game, "%s\n", strerror(errno));
	i = 0;
	while (i < data->num_sprites)
	{
		(data->sprites)[i].x = (lst->x) + 0.5;
		(data->sprites)[i].y = (lst->y) + 0.5;
		(data->sprites)[i].type = (lst->type);
		lst = lst->next;
		i++;
	}
}

static void	check_map_object_ii(t_game *game, t_point *pos, \
								char obj)
{
	if (ft_strchr(MAP_DOORS, obj))
	{
		check_round_spaces(game, pos);
		check_door(game, pos);
	}
	else if (ft_strchr("NSWE", obj))
	{
		check_round_spaces(game, pos);
		load_player(game, pos, obj);
		(game->scene_data.map_data.map)[(int)(pos->y)][(int)(pos->x)] = '0';
	}
}

static void	check_map_object(t_game *game, t_point *pos, \
								char obj, t_spritelst **list)
{
	t_spritelst	*element;
	t_spritelst	**templst;

	if (obj == '1')
		(game->scene_data.map_data.ones) += 1;
	else if (obj == '0')
		check_round_spaces(game, pos);
	else if (obj == '2' || obj == '3')
	{
		templst = list;
		check_round_spaces(game, pos);
		if (obj == '2')
			element = create_sprite_lst(game, obj, pos, GUARD_SPRITE);
		else
			element = create_sprite_lst(game, obj, pos, BARREL_SPRITE);
		spritelst_add_back(templst, element);
		(game->scene_data.sprites.num_sprites) += 1;
	}
	check_map_object_ii(game, pos, obj);
}

void	check_map_info(t_game *game)
{
	t_point		pos;
	char		obj;
	t_map_data	map;
	t_spritelst	*list;

	list = NULL;
	map = game->scene_data.map_data;
	pos.y = 0;
	while (pos.y < map.height)
	{
		pos.x = 0;
		while (pos.x < map.width)
		{
			obj = map.map[pos.y][pos.x];
			if (!(ft_strchr(MAP_OBJECTS, obj)))
				exit_failure(game, \
					"Invalid map char %c at (%i, %i)\n", \
					obj, pos.x + 1, pos.y + 1);
			check_map_object(game, &pos, obj, &list);
			(pos.x)++;
		}
		(pos.y)++;
	}
	load_sprites(game, list);
	spritelst_clear(&list);
}
