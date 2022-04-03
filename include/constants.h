/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:57:30 by jcarrete          #+#    #+#             */
/*   Updated: 2021/02/12 22:35:49 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define TRUE				1
# define FALSE				0

# define PI					3.14159265358979323846f
# define TWO_PI				6.28318530717958647692f

# define MINIMAP_OFFSET		10
# define TILE_SIZE			64
# define MAP_SCALE			0.15f

# define PLAYER_MOVE_SPEED	0.03f
# define PLAYER_ROT_SPEED	0.02f
# define PLAYER_FOV			60

# define MAP_OBJECTS		"012NSWE "
# define NOT_TRAVERSABLE	"1"

# define BPP				4
# define HEADER_SIZE		54

# define TICKBASE			70

# define WINDOW_TITLE		"cub3D"

# ifdef __APPLE__
#  define LINUX FALSE
# elif defined __unix__
#  define LINUX TRUE
#  define MLX_SYNC_WIN_CMD_COMPLETED FALSE
# endif
#endif
