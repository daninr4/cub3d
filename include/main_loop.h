/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:55:01 by jcarrete          #+#    #+#             */
/*   Updated: 2021/02/10 19:54:20 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** MAIN header for function prototypes.
** It will comprise the main engine of the game,
** its inizialitation and the main loop of the game.
*/

#ifndef MAIN_LOOP_H
# define MAIN_LOOP_H

# include "cub3d.h"

void	initialize_game_struct(t_game *game);
void	init_keycode_states(t_keycode_states *states);
void	init_mlx_data(t_game *game);
void	init_player(t_player_data *player);
void	init_scene(t_scene_data *scene);
void	load_scene_description(t_game *game, char *file);
void	initialize_window(t_game *game);
int		render_image(t_game *game);
void	game_loop(t_game *game);
#endif
