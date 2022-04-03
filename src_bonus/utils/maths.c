/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:51:54 by jcarrete          #+#    #+#             */
/*   Updated: 2021/01/10 17:42:47 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	deg_to_rad(double degrees)
{
	return (degrees * (PI / 180));
}

double	rad_to_deg(double radians)
{
	return (radians * (180 / PI));
}
