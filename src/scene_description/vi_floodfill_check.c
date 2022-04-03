/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_floodfill_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 23:38:42 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/12 21:50:13 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_description.h"

static int	hunt_one(t_game *game, int **hash, \
					t_fpoint *pos, t_fpoint *ones_pos)
{
	t_map_data	*md;

	md = &(game->scene_data.map_data);
	if (pos->x > 0 && pos->x < md->width - 1 && \
		pos->y > 0 && pos->y < md->height - 1)
	{
		if (hash[(int)(pos->y) - 1][(int)(pos->x)] == 3)
			return (ff_copy_coords(pos->x, pos->y - 1, \
					&(ones_pos->x), &(ones_pos->y)));
		else if (hash[(int)(pos->y) + 1][(int)(pos->x)] == 3)
			return (ff_copy_coords(pos->x, pos->y + 1, \
					&(ones_pos->x), &(ones_pos->y)));
		else if (hash[(int)(pos->y)][(int)(pos->x) - 1] == 3)
			return (ff_copy_coords(pos->x - 1, pos->y, \
					&(ones_pos->x), &(ones_pos->y)));
		else if (hash[(int)(pos->y)][(int)(pos->x) + 1] == 3)
			return (ff_copy_coords(pos->x + 1, pos->y, \
					&(ones_pos->x), &(ones_pos->y)));
	}
	return (FALSE);
}

static int	hunt(t_game *game, int **hash, t_fpoint *pos, int v)
{
	t_map_data	*md;

	md = &(game->scene_data.map_data);
	if (pos->x > 0 && pos->x < md->width - 1 && \
		pos->y > 0 && pos->y < md->height - 1)
	{
		if (ff_check_position(hash[(int)(pos->y)] \
				[(int)(pos->x) + 1], v, pos, 1) || \
				ff_check_position(hash[(int)(pos->y)] \
				[(int)(pos->x) - 1], v, pos, 2) || \
				ff_check_position(hash[(int)(pos->y) + 1] \
				[(int)(pos->x)], v, pos, 3) || \
				ff_check_position(hash[(int)(pos->y) - 1] \
				[(int)(pos->x)], v, pos, 4))
			return (TRUE);
	}
	if (ff_check_side_l(game, hash, pos, v))
		return (TRUE);
	if (ff_check_side_r(game, hash, pos, v))
		return (TRUE);
	if (ff_check_corner_l(game, hash, pos, v))
		return (TRUE);
	if (ff_check_corner_r(game, hash, pos, v))
		return (TRUE);
	return (FALSE);
}

static void	floodfill_check_ones(t_game *game, int **hash, t_fpoint *pos)
{
	int	checked;

	checked = 4;
	while (checked > 3)
	{
		hash[(int)(pos->y)][(int)(pos->x)] = checked++;
		if (!hunt(game, hash, pos, 3))
		{
			hash[(int)(pos->y)][(int)(pos->x)] = 2;
			pos->extra += 1;
			checked -= 2;
			hunt(game, hash, pos, checked);
		}
	}
}

static int	**init_hashmap(t_game *game)
{
	int		i;
	int		j;
	int		**hash;
	int		row_long;

	hash = (int **)ft_memalloc(sizeof(int *) * \
				game->scene_data.map_data.height);
	row_long = game->scene_data.map_data.width * sizeof(int);
	i = 0;
	while (i < game->scene_data.map_data.height)
	{
		hash[i] = ft_memalloc(row_long);
		j = 0;
		while (j < game->scene_data.map_data.width)
		{
			hash[i][j] = game->scene_data.map_data.map[i][j] - 48;
			ff_change_value(-16, &(hash[i][j]), 0);
			ff_change_value(2, &(hash[i][j]), 0);
			ff_change_value(1, &(hash[i][j]), 3);
			j++;
		}
		i++;
	}
	i = 0;
	return (hash);
}

void	floodfilling_check(t_game *game)
{
	int			**hash;
	int			checked;
	t_fpoint	pos;
	t_fpoint	ones_pos;

	hash = init_hashmap(game);
	checked = -1;
	pos.x = (int)(game->player_data.pos_x - 0.5f);
	pos.y = (int)(game->player_data.pos_y - 0.5f);
	ones_pos.extra = 0;
	while (checked < 0)
	{
		hash[(int)(pos.y)][(int)(pos.x)] = checked--;
		if (hunt_one(game, hash, &pos, &ones_pos))
			floodfill_check_ones(game, hash, &ones_pos);
		if (!hunt(game, hash, &pos, 0))
		{
			hash[(int)(pos.y)][(int)(pos.x)] = 1;
			checked += 2;
			hunt(game, hash, &pos, checked);
		}
	}
	if (ones_pos.extra != game->scene_data.map_data.ones)
		exit_failure(game, "Invalid Map: You can only have one map\n");
	free_hash(game, hash);
}
