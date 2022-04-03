/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ii_set_description.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 23:28:52 by jcarrete          #+#    #+#             */
/*   Updated: 2021/05/03 13:04:21 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_description.h"

void	set_resolution(t_game *game, int *elements, char **info)
{
	int	temp_width;
	int	temp_height;

	if (*elements & RESOLUTION_PARAM)
		exit_failure(game, "File has 2+ Resolution elements\n");
	if (ft_strcount(info) != 3)
		exit_failure(game, \
			"Incorrect number of parameteres in Resolution\n");
	if (!(check_str_isdigit(info[1])) || !(check_str_isdigit(info[2])))
		exit_failure(game, \
			"Incorrect resolution format: %s, %s\n", info[1], info[2]);
	temp_width = INT_MAX;
	temp_height = INT_MAX;
	if (check_str_val_len(info[1], INT_MAX))
		temp_width = ft_atoi(info[1]);
	if (check_str_val_len(info[2], INT_MAX))
		temp_height = ft_atoi(info[2]);
	if (temp_width == 0)
		exit_failure(game, "Invalid resolution value: %s\n", info[1]);
	if (temp_height == 0)
		exit_failure(game, "Invalid resolution value: %s\n", info[2]);
	check_resolution(game, temp_width, temp_height);
	*elements |= RESOLUTION_PARAM;
}

void	set_sprite(t_game *game, int *elements, char **info)
{
	void	*temp_image;
	int		temp_width;
	int		temp_height;

	if (*elements & SPRITE_PARAM)
		exit_failure(game, "File has 2+ Sprite elements\n");
	if (ft_strcount(info) != 2)
		exit_failure(game, \
			"Incorrect number of parameteres in Sprites\n");
	temp_image = mlx_xpm_file_to_image((game->mlx_data).mlx, info[1], \
			&temp_width, &temp_height);
	if (temp_image == NULL)
		exit_failure(game, \
			"Failed creating mlx image instance from file %s: %s\n", \
			info[1], strerror(errno));
	if (!(mlx_image_set(&(game->scene_data.textures.sprite), \
			temp_image, temp_width, temp_height)))
		exit_failure(game, \
			"Tried to load 2+ times the same Sprite\n");
	game->scene_data.textures.num_dif_sprites += 1;
	*elements |= SPRITE_PARAM;
}

void	set_color(t_game *game, int *elements, char **info)
{
	int		color[3];
	char	**rgb;

	if (ft_strcount(info) != 2)
		exit_failure(game, \
			"Incorrect number of parameteres in Colors\n");
	check_color_format(game, info[1]);
	rgb = ft_split(info[1], ',');
	if (rgb == NULL)
		exit_failure(game, "%s\n", strerror(errno));
	check_color_value(game, rgb, info, color);
	if (!ft_strcmp("F", info[0]) && !(*elements & FLOOR_PARAM))
	{
		game->scene_data.floor_color = \
			mlx_create_trgb(0, color[0], color[1], color[2]);
		*elements |= FLOOR_PARAM;
	}
	else if (!ft_strcmp("C", info[0]) && !(*elements & CEILING_PARAM))
	{
		game->scene_data.ceiling_color = \
			mlx_create_trgb(0, color[0], color[1], color[2]);
		*elements |= CEILING_PARAM;
	}
	else
		exit_failure(game, "File has 2+ %s elements\n", info[0]);
}

void	set_texture(t_game *game, int *elements, char **info)
{
	if (ft_strcount(info) != 2)
		exit_failure(game, \
			"Incorrect number of parameteres in Texture: %s\n", info[0]);
	if (!ft_strcmp("NO", info[0]) && !(*elements & NORTH_PARAM))
	{
		assign_texture(game, info, 'N');
		*elements |= NORTH_PARAM;
	}
	else if (!ft_strcmp("SO", info[0]) && !(*elements & SOUTH_PARAM))
	{
		assign_texture(game, info, 'S');
		*elements |= SOUTH_PARAM;
	}
	else if (!ft_strcmp("WE", info[0]) && !(*elements & WEST_PARAM))
	{
		assign_texture(game, info, 'W');
		*elements |= WEST_PARAM;
	}
	else if (!ft_strcmp("EA", info[0]) && !(*elements & EAST_PARAM))
	{
		assign_texture(game, info, 'E');
		*elements |= EAST_PARAM;
	}
	else
		exit_failure(game, "File has 2+ %s elements\n", info[0]);
}
