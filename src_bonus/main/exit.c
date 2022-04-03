/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:28:06 by jcarrete          #+#    #+#             */
/*   Updated: 2021/05/03 11:53:12 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mlx_free(t_game *game)
{
	if (game->mlx_data.win != NULL)
		mlx_destroy_window(game->mlx_data.mlx, game->mlx_data.win);
	game->mlx_data.win = NULL;
	if (game->mlx_data.image.img != NULL)
		mlx_destroy_image(game->mlx_data.mlx, game->mlx_data.image.img);
	if (game->mlx_data.mlx != NULL && LINUX == TRUE)
		mlx_destroy_display(game->mlx_data.mlx);
}

void	free_game(t_game *game)
{
	int	i;

	ft_memfree(game->scene_data.sprites.sprites, NULL);
	ft_memfree(game->player_data.z_buffer, NULL);
	mlx_free(game);
	i = 0;
	while (i < game->scene_data.map_data.height)
	{
		game->scene_data.map_data.map[i] = \
			ft_memfree(game->scene_data.map_data.map[i], NULL);
		i++;
	}
	free(game->scene_data.map_data.map);
	game->scene_data.map_data.map = NULL;
	ft_bzero(game, sizeof(t_game));
	game = ft_memfree(game, NULL);
}

static void	failure_puttype(char *format, int *i, va_list *ap)
{
	char	*s1;

	if (format[*i] == 's')
	{
		s1 = va_arg(*ap, char *);
		if (s1 == NULL)
			ft_dprintf(STDERR_FILENO, "(null)");
		else
			ft_dprintf(STDERR_FILENO, s1);
		(*i)++;
	}
	else if (format[*i] == 'c')
	{
		ft_putchar_fd((char)va_arg(*ap, int), STDERR_FILENO);
		(*i)++;
	}
	else if (format[*i] == 'i')
	{
		s1 = ft_itoa((int)(va_arg(*ap, int)));
		ft_dprintf(STDERR_FILENO, s1);
		(*i)++;
	}
}

int	exit_success(t_game *game)
{
	game->game_state = S_EXIT;
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	exit_failure(t_game *game, char *format, ...)
{
	va_list	ap;
	int		i;

	if (game != NULL)
		free_game(game);
	va_start(ap, format);
	ft_dprintf(STDERR_FILENO, "ERROR:\n");
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			failure_puttype(format, &i, &ap);
		}
		else
			ft_putchar_fd(format[i++], STDERR_FILENO);
	}
	va_end(ap);
	exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
