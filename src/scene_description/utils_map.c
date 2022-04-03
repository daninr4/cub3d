/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:35:15 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/25 13:27:41 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_description.h"

size_t	get_current_width(char *line)
{
	int		len;

	len = ft_strlen(line);
	while (len > 0)
	{
		if (!(ft_isspace(line[len - 1])))
			break ;
		len--;
	}
	return (len);
}

void	copy_map_line(char *map, char *list, int width)
{
	int	len;

	len = ft_strlen(list);
	if (width < len)
		len = width;
	ft_memcpy(map, list, len);
	while (len < width)
		map[len++] = ' ';
	map[width] = '\0';
}

t_spritelst	*create_sprite_lst(t_game *game, char obj, t_point *pos)
{
	t_spritelst	*new;

	new = (t_spritelst *)malloc(sizeof(t_spritelst));
	if (new == NULL)
		exit_failure(game, "%s\n", strerror(errno));
	new->obj = obj;
	new->x = (int)(pos->x);
	new->y = (int)(pos->y);
	new->next = NULL;
	return (new);
}

static t_spritelst	*ft_sptlstlast(t_spritelst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	spritelst_add_back(t_spritelst **lst, t_spritelst *newlst)
{
	if (lst == NULL || newlst == NULL)
		return ;
	if (*lst == NULL)
		*lst = newlst;
	else
		ft_sptlstlast(*lst)->next = newlst;
}
