/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_description_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:05:38 by jcarrete          #+#    #+#             */
/*   Updated: 2021/08/12 00:26:50 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_DESCRIPTION_BONUS_H
# define SCENE_DESCRIPTION_BONUS_H

# include "cub3d_bonus.h"

typedef struct s_spritelst
{
	int					x;
	int					y;
	int					type;
	char				obj;
	struct s_spritelst	*next;
}				t_spritelst;

void			set_color(t_game *game, int *elements, char **info);
void			set_resolution(t_game *game, int *elements, char **info);
void			set_sprite(t_game *game, int *elements, char **info);
void			set_texture(t_game *game, int *elements, char **info);
void			check_resolution(t_game *game, int temp_width, int temp_height);
void			check_color_format(t_game *game, char *info);
void			check_color_value(t_game *game, char **rgb, \
						char **info, int *color);
int				check_str_isdigit(char *str);
int				check_str_val_len(char *str, int num);
void			assign_texture(t_game *game, char **info, char orien);

void			extract_line_map(t_game *game, int fd, char **line, \
						t_list **list);
char			**set_map(t_game *game, t_list *list, t_map_data *data);
void			set_map_size(t_list *list, int *width, int *height);
void			check_map_info(t_game *game);
void			check_round_spaces(t_game *game, t_point *pos);
void			copy_map_line(char *map, char *list, int width);
t_spritelst		*create_sprite_lst(t_game *game, char obj, \
					t_point *pos, int type);
size_t			get_current_width(char *line);
void			spritelst_add_back(t_spritelst **lst, t_spritelst *newlst);
void			spritelst_clear(t_spritelst **lst);

void			load_player(t_game *game, t_point *pos, char obj);

void			floodfilling_check(t_game *game);
int				floodfill_check_pos(t_game *game, char **hash, \
									t_fpoint *pos, char c);
void			ff_change_value(int old, int *new, int v);
int				ff_copy_coords(double x, double y, \
					double *new_x, double *new_y);
int				ff_check_position(int cell, int val, t_fpoint *pos, int d);
int				ff_check_side_l(t_game *game, int **hash, t_fpoint *pos, int v);
int				ff_check_side_r(t_game *game, int **hash, \
									t_fpoint *pos, int v);
int				ff_check_corner_l(t_game *game, int **hash, \
									t_fpoint *pos, int v);
int				ff_check_corner_r(t_game *game, int **hash, \
									t_fpoint *pos, int v);
void			ff_print_map(t_game *game, int **hash);
void			ff_change_values(int **hash, int i, int j);
void			free_hash(t_game *game, int **hash);

char	g_texture_barrel[NUMTEXTURESBARREL][128] = {
	"./resources/textures/barrel/Barrel01.xpm",
	"./resources/textures/barrel/Barrel02.xpm",
	"./resources/textures/barrel/Barrel03.xpm"
};

char	*g_texture_door = "./resources/textures/80.xpm";

#endif
