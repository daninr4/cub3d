/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_description.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:45:03 by jcarrete          #+#    #+#             */
/*   Updated: 2021/05/03 11:02:37 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_description.h"

void	check_resolution(t_game *game, int temp_width, int temp_height)
{
	mlx_get_screen_size(game->mlx_data.mlx, \
			&(game->mlx_data.width), &(game->mlx_data.height));
	if (temp_width < game->mlx_data.width)
		game->mlx_data.width = temp_width;
	if (temp_height < game->mlx_data.height)
		game->mlx_data.height = temp_height;
	if (temp_width > game->mlx_data.width \
			|| temp_height > game->mlx_data.height)
		ft_printf("Big resolution adapted to screen size\n");
}

void	check_color_format(t_game *game, char *info)
{
	int	i;
	int	commas;

	commas = 0;
	if (info[0] == ',' || info[ft_strlen(info) - 1] == ',')
		exit_failure(game, \
			"You cannot start or end 'C' or 'F' with commas: %s\n", info);
	i = 0;
	while (info[i] != '\0')
		if (info[i++] == ',')
			commas++;
	if (commas != 2)
		exit_failure(game, \
			"Incorrect number of parameters in RGB value: %s\n", info);
}

void	check_color_value(t_game *game, char **rgb, char **info, int *color)
{
	int	i;

	if (!(check_str_isdigit(rgb[0])) || !(check_str_isdigit(rgb[1])) || \
		!(check_str_isdigit(rgb[2])))
		exit_failure(game, \
			"Incorrect R,G,B format or negative value: %s\n", info[1]);
	i = 0;
	while (i < 3)
	{
		color[i] = INT_MAX;
		if (check_str_val_len(rgb[i], INT_MAX))
			color[i] = ft_atoi(rgb[i]);
		i++;
	}
	ft_split_free(rgb);
	if (color[0] > 255 || color[1] > 255 || color[2] > 255)
		exit_failure(game, "R,G,B value bigger than 255: %s\n", info[1]);
}

void	assign_texture(t_game *game, char **info, char orien)
{
	void	*temp_image;
	int		temp_width;
	int		temp_height;

	temp_image = mlx_xpm_file_to_image((game->mlx_data).mlx, info[1], \
		&temp_width, &temp_height);
	if (temp_image == NULL)
		exit_failure(game, \
			"Failed creating mlx image instance from file %s: %s\n", \
			info[1], strerror(errno));
	if (orien == 'N')
		mlx_image_set(&(game->scene_data.textures.walls.north), \
			temp_image, temp_width, temp_height);
	else if (orien == 'S')
		mlx_image_set(&(game->scene_data.textures.walls.south), \
			temp_image, temp_width, temp_height);
	else if (orien == 'W')
		mlx_image_set(&(game->scene_data.textures.walls.west), \
			temp_image, temp_width, temp_height);
	else if (orien == 'E')
		mlx_image_set(&(game->scene_data.textures.walls.east), \
			temp_image, temp_width, temp_height);
}
