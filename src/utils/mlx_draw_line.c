/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:13:36 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/12 22:07:32 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	add_step(int *err, int *start, int delta, int step)
{
	*err += delta;
	*start += step;
}

void	mlx_draw_line(t_mlx_image *img, t_point start, \
							t_point end, int color)
{
	t_point	delta;
	t_point	step;
	int		err[2];

	delta.x = ft_abs(end.x - start.x);
	delta.y = -1 * ft_abs(end.y - start.y);
	step.x = 1 - (2 * (start.x >= end.x));
	step.y = 1 - (2 * (start.y >= end.y));
	err[0] = delta.x + delta.y;
	while (TRUE)
	{
		mlx_pixel_set(img, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		err[1] = err[0] * 2;
		if (err[1] >= delta.y)
			add_step(&(err[0]), &(start.x), delta.y, step.x);
		if (err[1] <= delta.x)
			add_step(&(err[0]), &(start.y), delta.x, step.y);
	}
}

void	mlx_draw_vertical_line(t_mlx_image *img, t_point start, \
									t_point end, int color)
{
	if (start.x != end.x)
		return ;
	if (start.y > end.y)
		ft_swap(&(start.y), &(end.y), sizeof(int));
	while (start.y <= end.y)
	{
		mlx_pixel_set(img, start.x, start.y, color);
		(start.y)++;
	}
}

void	mlx_draw_horizontal_line(t_mlx_image *img, t_point start, \
									t_point end, int color)
{
	if (start.y != end.y)
		return ;
	if (start.x > end.x)
		ft_swap(&(start.x), &(end.x), sizeof(int));
	while (start.x <= end.x)
	{
		mlx_pixel_set(img, start.x, start.y, color);
		(start.x)++;
	}
}
