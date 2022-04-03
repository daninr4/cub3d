/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:42:51 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/12 22:07:10 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	mlx_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	mlx_get_alpha(int color)
{
	return ((color & (0xFF << 24)) >> 24);
}

int	mlx_get_red(int color)
{
	return ((color & (0xFF << 16)) >> 16);
}

int	mlx_get_green(int color)
{
	return ((color & (0xFF << 8)) >> 8);
}

int	mlx_get_blue(int color)
{
	return (color & 0xFF);
}
