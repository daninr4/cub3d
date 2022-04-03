/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_read_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:43:52 by jcarrete          #+#    #+#             */
/*   Updated: 2021/05/03 12:20:24 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_description.h"

static void	skip_empty_lines(t_game *game, int fd, char **line)
{
	int		value;

	value = ft_get_next_line(fd, line);
	while (value > 0)
	{
		if (ft_strlen(*line) > 0)
			break ;
		free(*line);
		value = ft_get_next_line(fd, line);
	}
	if (value == -1)
		exit_failure(game, \
			"Failed reading from fd(%i): %s\n", fd, strerror(errno));
	if (value == 0)
		exit_failure(game, "Map is empty\n");
}

void	load_map(t_game *game, int fd)
{
	t_list	*list;
	t_list	*element;
	char	*line;

	list = NULL;
	skip_empty_lines(game, fd, &line);
	element = ft_lstnew(line);
	if (element == NULL)
		exit_failure(game, "%s\n", strerror(errno));
	ft_lstadd_back(&list, element);
	extract_line_map(game, fd, &line, &list);
	game->scene_data.map_data.map = \
		set_map(game, list, &(game->scene_data.map_data));
	if ((game->scene_data.map_data.map) == NULL)
		exit_failure(game, "%s\n", strerror(errno));
	ft_lstclear(&list, free);
}

int	extract_line_info(t_game *game, char *line)
{
	static int	elements = 0;
	char		**info;

	if (ft_strlen(line) == 0)
		return (INFO_LOADING);
	if (line[0] == ' ' || ft_strrncmp(line, " ", 1) == 0)
		exit_failure(game, "Spaces can only be used to separate elements\n");
	info = ft_split(line, ' ');
	if (info == NULL)
		exit_failure(game, "%s\n", strerror(errno));
	if (ft_strnstr("R", info[0], 1))
		set_resolution(game, &elements, info);
	else if (ft_strnstr("S", info[0], 1))
		set_sprite(game, &elements, info);
	else if (ft_strnstr("F C", info[0], 3))
		set_color(game, &elements, info);
	else if (ft_strnstr("NO SO WE EA", info[0], 11))
		set_texture(game, &elements, info);
	else
		exit_failure(game, "Unknown element: %s\n", info[0]);
	ft_split_free(info);
	if (elements == ALL_PARAMS)
		return (INFO_COMPLETE);
	else
		return (INFO_LOADING);
}

void	load_scene_configuration(t_game *game, int fd)
{
	int		value;
	int		error;
	char	*line;

	error = 0;
	value = ft_get_next_line(fd, &line);
	while (value > 0)
	{
		error = extract_line_info(game, line);
		line = ft_memfree(line, NULL);
		if (error == INFO_COMPLETE)
			break ;
		value = ft_get_next_line(fd, &line);
	}
	if (value == -1)
		exit_failure(game, "Failed reading from fd(%i): %s\n", \
					fd, strerror(errno));
	if (error == INFO_LOADING)
		exit_failure(game, "Configuration file is missing information\n");
}

void	load_scene_description(t_game *game, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_failure(game, "Can't open %s file: %s\n", file, strerror(errno));
	load_scene_configuration(game, fd);
	ft_putstr_fd("a\n", 1);
	load_map(game, fd);
	ft_putstr_fd("b\n", 1);
	if (close(fd) == -1)
		exit_failure(game, "Can't close %s file: %s\n", file, strerror(errno));
	check_map_info(game);
	ft_putstr_fd("c\n", 1);
	if (game->player_data.pos_x == -1)
		exit_failure(game, "Invalid map. Player does not exist\n");
	floodfilling_check(game);
}
