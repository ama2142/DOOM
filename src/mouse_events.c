/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:24:16 by jmalik            #+#    #+#             */
/*   Updated: 2021/01/27 10:36:50 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		close_window(void *game)
{
	(void)game;
	exit(0);
}

void	mouse_move(SDL_MouseMotionEvent *e, t_game *game)
{
	game->dummy = e->x;
}

void	mouse_weel(Sint32 y, t_game *game)
{
	if (y < 0)
		game->dummy = 1;
}

void	mouse_press(SDL_MouseButtonEvent *e, t_game *game)
{
	game->dummy = e->x;
}
