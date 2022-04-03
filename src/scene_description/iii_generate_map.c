/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iii_generate_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:00:42 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/15 22:52:50 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_description.h"

void	set_map_size(t_list *list, int *width, int *height)
{
	int	current;
	int	max;

	*width = 0;
	*height = 0;
	current = 0;
	max = 0;
	while (list)
	{
		*height += (*(char *)(list->content) != '\0');
		current = get_current_width(list->content);
		if (current > max)
			max = current;
		list = list->next;
	}
	*width = max;
}

char	**set_map(t_game *game, t_list *list, t_map_data *data)
{
	int		i;
	char	**temp_map;

	set_map_size(list, &(data->width), &(data->height));
	temp_map = malloc(data->height * sizeof(char *));
	if (temp_map == NULL)
		exit_failure(game, "%s\n", strerror(errno));
	i = 0;
	while (i < data->height)
	{
		temp_map[i] = malloc((data->width * sizeof(char)) + 1);
		if (temp_map[i] == NULL)
			exit_failure(game, "%s\n", strerror(errno));
		copy_map_line(temp_map[i], list->content, data->width);
		list = list->next;
		i++;
	}
	return (temp_map);
}

void	extract_line_map(t_game *game, int fd, char **line, t_list **list)
{
	int		value;
	t_list	*element;

	element = NULL;
	value = ft_get_next_line(fd, line);
	while (value > 0)
	{
		element = ft_lstnew(*line);
		if (ft_strlen(*line) == 0)
			exit_failure(game, "Map can´t contain empty lines\n");
		else if (element == NULL)
			exit_failure(game, "%s\n", strerror(errno));
		ft_lstadd_back(list, element);
		value = ft_get_next_line(fd, line);
	}
	if (value >= 0 && *line)
	{
		element = ft_lstnew(*line);
		if (element == NULL)
			exit_failure(game, "%s\n", strerror(errno));
		ft_lstadd_back(list, element);
	}
	if (value == -1)
		exit_failure(game, \
			"Failed reading from fd(%i): %s\n", fd, strerror(errno));
}
