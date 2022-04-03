/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_floodfill_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 23:38:42 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/12 21:50:13 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_description.h"

void	ff_change_values(int **hash, int i, int j)
{
	ff_change_value(-16, &(hash[i][j]), 0);
	ff_change_value(3, &(hash[i][j]), 0);
	ff_change_value(3, &(hash[i][j]), 0);
	ff_change_value(2, &(hash[i][j]), 0);
	ff_change_value(64, &(hash[i][j]), 0);
	ff_change_value(65, &(hash[i][j]), 0);
	ff_change_value(1, &(hash[i][j]), 3);
}
