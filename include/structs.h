/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:12:19 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/11 22:38:08 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
** ENGINE / MAIN STRUCTS
*/

typedef struct s_point
{
	int			x;
	int			y;
	int			extra;
}				t_point;

typedef struct s_fpoint
{
	double		x;
	double		y;
	int			extra;
}				t_fpoint;

typedef struct s_line
{
	t_fpoint	start;
	t_fpoint	end;
}				t_line;

typedef struct s_bmp_data
{
	int				fd;
	unsigned int	pixel_bytes_row;
	unsigned int	padding_bytes_row;
	unsigned int	width;
	unsigned int	height;
	unsigned char	*file_header;
	unsigned char	*info_header;
	unsigned char	*img;
}				t_bmp_data;

typedef struct s_mlx_image
{
	int			width;
	int			height;

	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*img;
	char		*addr;
}				t_mlx_image;

typedef struct s_map_data
{
	int			width;
	int			height;

	int			ones;
	char		**map;
}				t_map_data;

typedef struct s_sprite
{
	double	x;
	double	y;
	double	dist;

}				t_sprite;

typedef struct s_sprites_data
{
	int			num_sprites;
	t_sprite	*sprites;

	double		sprite_x;
	double		sprite_y;
	int			s_height;
	int			s_width;

	double		inv_matrix;
	double		transform_x;
	double		transform_y;
	int			sscreen_x;

	int			d_start_x;
	int			d_start_y;
	int			d_end_x;
	int			d_end_y;
	int			stripe;

	int			tex_x;
	int			tex_y;
	int			y;
	int			d;
}				t_sprites_data;

typedef struct s_walls
{
	t_mlx_image	north;
	t_mlx_image	south;
	t_mlx_image	east;
	t_mlx_image	west;

}				t_walls;

typedef struct s_textures
{
	t_walls		walls;
	t_mlx_image	sprite;
	int			num_dif_sprites;

}				t_textures;

typedef struct s_scene_data
{
	t_textures		textures;
	t_sprites_data	sprites;
	t_map_data		map_data;
	int				floor_color;
	int				ceiling_color;

}				t_scene_data;

typedef struct s_player_data
{
	int			map_x;
	int			map_y;

	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;

	double		camera_x;
	double		rc_dir_x;
	double		rc_dir_y;
	double		delta_x;
	double		delta_y;
	int			hit;
	int			side;
	int			step_x;
	int			step_y;
	double		side_dist_x;
	double		side_dist_y;

	double		wall_distance;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		x_w_coord;
	int			x_tex;
	int			y_tex;
	double		step_tex;
	double		pos_tex;

	double		*z_buffer;
	float		fov_angle;

}				t_player_data;

typedef struct s_keycode_states
{
	int			key_w;
	int			key_a;
	int			key_s;
	int			key_d;
	int			key_left;
	int			key_right;
	int			key_up;
	int			key_down;

}				t_keycode_states;

typedef struct s_mlx_data
{
	int			width;
	int			height;

	void		*mlx;
	char		*win;
	t_mlx_image	image;

}				t_mlx_data;

typedef struct s_game
{
	int					game_state;
	t_mlx_data			mlx_data;
	t_keycode_states	keycode_states;
	t_player_data		player_data;
	t_scene_data		scene_data;
	t_point				minimap;
}				t_game;

#endif
