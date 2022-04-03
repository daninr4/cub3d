/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:10:40 by jcarrete          #+#    #+#             */
/*   Updated: 2021/02/07 23:46:55 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LOOP_H
# define GAME_LOOP_H

# include "cub3d_bonus.h"

void	process_input(t_game *game);
void	render_textures(t_game *game);
void	digital_diferential_analysis(t_game *game, int x);
void	render_sprites(t_game *game);
int		key_press_use(int key, t_game *game);
int		key_release_use(int key, t_game *game);
void	mm_render_map(t_game *game);
void	draw_sprite(t_game *game, int type);
#endif
