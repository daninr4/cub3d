/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_floodfill_sides.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:13:36 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/12 21:52:09 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_description.h"

int	ff_check_position(int cell, int val, t_fpoint *pos, int d)
{
	if (cell == val)
	{
		if (d == 1)
			(pos->x)++;
		else if (d == 2)
			(pos->x)--;
		else if (d == 3)
			(pos->y)++;
		else if (d == 4)
			(pos->y)--;
		return (TRUE);
	}
	return (FALSE);
}

int	ff_check_corner_r(t_game *game, int **hash, t_fpoint *pos, int v)
{
	t_map_data	*md;

	md = &(game->scene_data.map_data);
	if ((pos->x == md->width - 1) && pos->y == 0)
	{
		if (ff_check_position(hash[(int)(pos->y)] \
				[(int)(pos->x) - 1], v, pos, 2))
			return (TRUE);
		else if (ff_check_position(hash[(int)(pos->y) + 1] \
				[(int)(pos->x)], v, pos, 3))
			return (TRUE);
	}
	else if ((pos->x == md->width - 1) && (pos->y == md->height - 1))
	{
		if (ff_check_position(hash[(int)(pos->y)] \
				[(int)(pos->x) - 1], v, pos, 2))
			return (TRUE);
		else if (ff_check_position(hash[(int)(pos->y) - 1] \
				[(int)(pos->x)], v, pos, 4))
			return (TRUE);
	}
	return (FALSE);
}

int	ff_check_corner_l(t_game *game, int **hash, t_fpoint *pos, int v)
{
	t_map_data	*md;

	md = &(game->scene_data.map_data);
	if ((int)(pos->x) == 0 && (int)(pos->y) == 0)
	{
		if (ff_check_position(hash[(int)(pos->y)] \
			[(int)(pos->x) + 1], v, pos, 1))
			return (TRUE);
		else if (ff_check_position(hash[(int)(pos->y) + 1] \
			[(int)(pos->x)], v, pos, 3))
			return (TRUE);
	}
	else if ((int)(pos->x) == 0 && ((int)(pos->y) == md->height - 1))
	{
		if (ff_check_position(hash[(int)(pos->y)] \
			[(int)(pos->x) + 1], v, pos, 1))
			return (TRUE);
		else if (ff_check_position(hash[(int)(pos->y) - 1] \
			[(int)(pos->x)], v, pos, 4))
			return (TRUE);
	}
	return (FALSE);
}

int	ff_check_side_r(t_game *game, int **hash, t_fpoint *pos, int v)
{
	if (((int)(pos->x) == game->scene_data.map_data.width - 1) && \
		((int)(pos->y) > 0 && \
		((int)(pos->y) < game->scene_data.map_data.height - 1)))
	{
		if (ff_check_position(hash[(int)(pos->y)] \
				[(int)(pos->x) - 1], v, pos, 2) || \
				ff_check_position(hash[(int)(pos->y) + 1] \
				[(int)(pos->x)], v, pos, 3) || \
				ff_check_position(hash[(int)(pos->y) - 1] \
				[(int)(pos->x)], v, pos, 4))
			return (TRUE);
	}
	else if ((int)(pos->x) == 0 && ((int)(pos->y) > 0 && \
		((int)(pos->y) < game->scene_data.map_data.height - 1)))
	{
		if (ff_check_position(hash[(int)(pos->y)] \
				[(int)(pos->x) + 1], v, pos, 1) || \
				ff_check_position(hash[(int)(pos->y) + 1] \
				[(int)(pos->x)], v, pos, 3) || \
				ff_check_position(hash[(int)(pos->y) - 1] \
				[(int)(pos->x)], v, pos, 4))
			return (TRUE);
	}
	return (FALSE);
}

int	ff_check_side_l(t_game *game, int **hash, t_fpoint *pos, int v)
{
	if (((int)(pos->y) == game->scene_data.map_data.height - 1) && \
			((int)(pos->x) > 0 && \
			((int)(pos->x) < game->scene_data.map_data.width - 1)))
	{
		if (ff_check_position(hash[(int)(pos->y)] \
				[(int)(pos->x) + 1], v, pos, 1) || \
				ff_check_position(hash[(int)(pos->y)] \
				[(int)(pos->x) - 1], v, pos, 2) || \
				ff_check_position(hash[(int)(pos->y) - 1] \
				[(int)(pos->x)], v, pos, 4))
			return (TRUE);
	}
	else if ((int)(pos->y) == 0 && \
			((int)(pos->x) > 0 && \
			((int)(pos->x) < game->scene_data.map_data.width - 1)))
	{
		if (ff_check_position(hash[(int)(pos->y)] \
				[(int)(pos->x) + 1], v, pos, 1) || \
				ff_check_position(hash[(int)(pos->y)] \
				[(int)(pos->x) - 1], v, pos, 2) || \
				ff_check_position(hash[(int)(pos->y) + 1] \
				[(int)(pos->x)], v, pos, 3))
			return (TRUE);
	}
	return (FALSE);
}
