/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 10:34:55 by jcarrete          #+#    #+#             */
/*   Updated: 2021/01/31 16:10:01 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	reassign_fpoint(t_fpoint *point, double x, double y)
{
	point->x = x;
	point->y = y;
}

void	reassign_point(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}
