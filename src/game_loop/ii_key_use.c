/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ii_key_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:10:31 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/12 21:36:16 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"

static void	switch_states(int *key_down, int *key_up)
{
	*key_down = KEY_PRESSED;
	*key_up = KEY_RELEASED;
}

int	key_press_use(int key, t_game *game)
{
	t_keycode_states	*ks;

	ks = &(game->keycode_states);
	if (key == KEY_ESC)
		exit_success(game);
	else if (key == KEY_W)
		switch_states(&(ks->key_w), &(ks->key_s));
	else if (key == KEY_A)
		switch_states(&(ks->key_a), &(ks->key_d));
	else if (key == KEY_S)
		switch_states(&(ks->key_s), &(ks->key_w));
	else if (key == KEY_D)
		switch_states(&(ks->key_d), &(ks->key_a));
	else if (key == KEY_AUX_LFAR)
		switch_states(&(ks->key_left), &(ks->key_right));
	else if (key == KEY_AUX_RTAR)
		switch_states(&(ks->key_right), &(ks->key_left));
	return (EXIT_SUCCESS);
}

int	key_release_use(int key, t_game *game)
{
	t_keycode_states	*ks;

	ks = &(game->keycode_states);
	if (key == KEY_W)
		ks->key_w = KEY_RELEASED;
	else if (key == KEY_A)
		ks->key_a = KEY_RELEASED;
	else if (key == KEY_S)
		ks->key_s = KEY_RELEASED;
	else if (key == KEY_D)
		ks->key_d = KEY_RELEASED;
	else if (key == KEY_AUX_LFAR)
		ks->key_left = KEY_RELEASED;
	else if (key == KEY_AUX_RTAR)
		ks->key_right = KEY_RELEASED;
	return (EXIT_SUCCESS);
}
