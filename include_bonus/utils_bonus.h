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

# include "cub3d_bonus.h"
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
int					mlx_draw_player(t_mlx_image *img, double posx, \
								double posy, int color);
void				mlx_draw_line(t_mlx_image *img, t_point start, \
								t_point end, int color);
void				reassign_point(t_point *point, int x, int y);
void				reassign_fpoint(t_fpoint *point, double x, double y);

void				player_rotation(t_game *game, int v);
int					event_mouse_move(int x, int y, t_game *game);
void				render_positive_x(t_game *game, t_point origen, \
								t_point dest, t_fpoint ray);
void				render_negative_x(t_game *game, t_point origen, \
								t_point dest, t_fpoint ray);
double				adjust_ray(double point);
double				adjust_player(double point);
void				load_textures(t_game *game);
void				process_metal_doors(t_game *game);
void				check_door_closed(t_game *game);
void				extend_raycasting(t_game *game);
void				load_doors_data(t_game *game, char obj, int x, int y);
void				check_door(t_game *game, t_point *pos);
t_mlx_image			*select_texture(t_game *game, \
						t_player_data *player, double dir);
#endif
