/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:24:16 by jmalik            #+#    #+#             */
/*   Updated: 2021/01/24 09:55:43 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_press4(SDL_Keycode key, t_game *game)
{
	if (key == SDLK_f)
	{
		game->dummy = 22;
		return (0);
	}
	return (1);
}

void	tools_keys(SDL_Keycode key, t_game *game)
{
	if (key == SDLK_l)
	{
		if (game->light == 3)
			game->light = 0;
		else if (game->light == 0)
			game->light = 1;
		else if (game->light == 1)
			game->light = 2;
		else if (game->light == 2)
			game->light = 3;
	}
	if (key == SDLK_LCTRL)
	{
		if (game->shift_r)
			game->shift_r = 0;
		else
			game->shift_r = 1;
	}
	if (key == SDLK_LSHIFT)
	{
		if (game->shift_l)
			game->shift_l = 0;
		else
			game->shift_l = 1;
	}
}

int		key_press3(SDL_Keycode key, t_game *game)
{
	return (key_press4(key, game));
}

int		key_press2(SDL_Keycode key, t_game *game)
{
	if (key == SDLK_m)
	{
		if (game->draw_map)
			game->draw_map = 0;
		else
			game->draw_map = 1;
	}
	if (key == SDLK_k)
		game->dummy = 7;
	tools_keys(key, game);
	return (key_press3(key, game));
}

int		key_press(SDL_Keycode key, t_game *game)
{
	return (key_press2(key, game));
}
