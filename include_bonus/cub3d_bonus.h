/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:09:32 by jcarrete          #+#    #+#             */
/*   Updated: 2021/02/11 23:35:11 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
** Include Extern libraries
*/

# include <errno.h>
# include <fcntl.h>

/*
** Include Util libraries
*/
# include "ft_printf_bonus.h"
# include "libft_bonus.h"
# ifdef __APPLE__
#  include "../lib/libmlx/minilibx-darwin/mlx.h"
# elif defined __unix__
#  include "../lib/libmlx/minilibx-linux/mlx.h"
# endif

/*
** Include Cub3D libraries
*/
# include "colors_bonus.h"
# include "constants_bonus.h"
# include "enums_bonus.h"
# include "events_bonus.h"
# include "keycodes_bonus.h"
# include "structs_bonus.h"
# include "utils_bonus.h"
# include "time.h"

/*
** Error management functions
*/
int		exit_failure(t_game *game, char *format, ...);
int		exit_success(t_game *game);
void	free_game(t_game *game);
#endif
