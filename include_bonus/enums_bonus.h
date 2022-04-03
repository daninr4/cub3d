/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:33:34 by jcarrete          #+#    #+#             */
/*   Updated: 2021/01/17 00:09:26 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

enum	e_key_states
{
	KEY_RELEASED,
	KEY_PRESSED
};

enum	e_info
{
	INFO_LOADING,
	INFO_COMPLETE
};

enum	e_set_parameters
{
	EMPTY = 0,
	RESOLUTION_PARAM = (1 << 0),
	SPRITE_PARAM = (1 << 1),
	FLOOR_PARAM = (1 << 2),
	CEILING_PARAM = (1 << 3),
	NORTH_PARAM = (1 << 4),
	SOUTH_PARAM = (1 << 5),
	WEST_PARAM = (1 << 6),
	EAST_PARAM = (1 << 7),
	ALL_PARAMS = ((1 << 8) - 1)
};

enum	e_game_state
{
	S_START,
	S_SAVEMODE,
	S_RENDER_START,
	S_RENDER_STARTED,
	S_RUNNING,
	S_EXIT
};

enum	e_doors_state
{
	D_OPEN,
	D_CLOSED,
	D_OPENING,
	D_CLOSING
};

enum	e_doors_type
{
	D_NONE,
	D_DOOR_N,
	D_DOOR_EW
};

#endif
