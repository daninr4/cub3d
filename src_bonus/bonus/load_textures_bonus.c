/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iv_load_textures_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:07:53 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/12 22:24:03 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_description_bonus.h"

static void	assign_animation_texture(t_game *game,
	t_mlx_image *tex, char info[3][128], int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		tex[i].img = mlx_xpm_file_to_image((game->mlx_data).mlx, info[i], \
			&tex[i].width, &tex[i].height);
		if (tex[i].img == NULL)
			exit_failure(game, \
			"Failed creating mlx image instance from file %s: %s\n", \
			info[i], strerror(errno));
		tex[i].addr = mlx_get_data_addr(tex[i].img, \
			&tex[i].bits_per_pixel, &tex[i].line_length, &tex[i].endian);
		i++;
	}
}

void	load_textures(t_game *game)
{
	t_textures	*textures;
	void		*temp_image;
	int			temp_width;
	int			temp_height;

	temp_image = mlx_xpm_file_to_image((game->mlx_data).mlx,
			"./resources/textures/walls/12_Metal_Door.xpm", \
				&temp_width, &temp_height);
	textures = &(game->scene_data.textures);
	assign_animation_texture(game, textures->barrel, \
		g_texture_barrel, NUMTEXTURESBARREL);
	mlx_image_set(&(game->scene_data.textures.door), \
		temp_image, temp_width, temp_height);
}
