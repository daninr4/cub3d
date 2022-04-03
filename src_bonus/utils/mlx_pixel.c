/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:50:07 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/12 22:07:56 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	invert_alpha(int color)
{
	int	new_color[4];

	new_color[0] = 255 - (int)(mlx_get_alpha(color));
	new_color[1] = mlx_get_red(color);
	new_color[2] = mlx_get_green(color);
	new_color[3] = mlx_get_blue(color);
	return (mlx_create_trgb(new_color[0], new_color[1], \
				new_color[2], new_color[3]));
}

int	mlx_pixel_get(t_mlx_image *img, int x, int y)
{
	int		*dst;
	int		offset;

	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	dst = (int *)(img->addr + offset);
	return (*dst);
}

void	mlx_pixel_set(t_mlx_image *img, int x, int y, int color)
{
	int		*dst;
	int		offset;

	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	dst = (int *)(img->addr + offset);
	*dst = color;
}

int	mlx_image_set(t_mlx_image *mlx_image, \
					void *img, int width, int height)
{
	if (mlx_image->img != NULL)
		return (FALSE);
	mlx_image->img = img;
	mlx_image->width = width;
	mlx_image->height = height;
	mlx_image->addr = mlx_get_data_addr(mlx_image->img, \
			&(mlx_image->bits_per_pixel), &(mlx_image->line_length), \
			&(mlx_image->endian));
	return (TRUE);
}
