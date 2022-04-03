/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_geometry.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:13:36 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/12 22:07:15 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	mlx_draw_rectangle(t_mlx_image *img, t_point pos, int color)
{
	int		i;
	int		j;
	int		size;

	size = TILE_SIZE * MAP_SCALE;
	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j <= size)
		{
			mlx_pixel_set(img, pos.x + i, pos.y + j, color);
			j++;
		}
		i++;
	}
	return (TRUE);
}
