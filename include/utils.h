/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:51:15 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/11 22:38:47 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Utils are extra functions to help cub3D work.
** It will comprise mlx extra files,
** ....
*/

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"
# include <sys/stat.h>

int					check_str_isdigit(char *str);
int					check_str_val_len(char *str, int max);

double				deg_to_rad(double degrees);
double				rad_to_deg(double radians);

int					mlx_create_trgb(int t, int r, int g, int b);
int					invert_alpha(int color);
int					mlx_get_alpha(int color);
int					mlx_get_red(int color);
int					mlx_get_green(int color);
int					mlx_get_blue(int color);

int					mlx_image_set(t_mlx_image *mlx_image, void *img, \
								int width, int height);
int					mlx_image_to_bmp(t_mlx_image *img, const char *name);

int					mlx_pixel_get(t_mlx_image *img, int x, int y);
void				mlx_pixel_set(t_mlx_image *img, int x, int y, int color);

void				mlx_draw_vertical_line(t_mlx_image *img, t_point start, \
									t_point end, int color);
int					mlx_draw_rectangle(t_mlx_image *img, \
								t_point pos, int color);

void				reassign_point(t_point *point, int x, int y);
void				reassign_fpoint(t_fpoint *point, double x, double y);
#endif
