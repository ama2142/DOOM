/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_sdl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 15:42:21 by jthuy             #+#    #+#             */
/*   Updated: 2021/01/15 13:40:10 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	sld_events2(t_game *game, SDL_Event e, int *repaint)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		mouse_press(&(e.button), game);
		*repaint = 1;
	}
	else if (e.type == SDL_MOUSEMOTION)
	{
		mouse_move(&(e.motion), game);
		if (game->status)
			*repaint = 1;
	}
	else if (e.type == SDL_MOUSEWHEEL)
	{
		mouse_weel(e.wheel.y, game);
		*repaint = 1;
	}
}

void	sld_events(t_game *game, SDL_Event e, int *quit, int *repaint)
{
	if (e.type == SDL_QUIT)
	{
		*quit = 1;
		game->status = 0;
	}
	else if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_ESCAPE)
			*quit = 1;
		else
			key_press(e.key.keysym.sym, game);
	}
	else
		sld_events2(game, e, repaint);
}

void	redraw(t_game *game)
{
	int	i;

	i = -1;
	while (++i < S_W * S_H)
		game->z_buffer[i] = 100;
	draw_game(game);
	SDL_UpdateWindowSurface(game->win);
	SDL_FlushEvent(SDL_KEYDOWN);
}

int		game_update(t_game *game, SDL_Point *flags)
{
	SDL_Event	e;

	check_keyboard(game, 0.3, &(flags->x));
	redraw(game);
	if (SDL_PollEvent(&e) != 0 || flags->y)
		sld_events(game, e, &(flags->x), &(flags->y));
	if (flags->x)
		return (OK);
	if (game->delay != 10)
	{
		SDL_Delay(game->delay);
		game->delay = 10;
		if (!check_start(game))
		{
			game->status = 0;
			return (ERROR);
		}
	}
	return (OK);
}

void	sdl_cycle(t_game *game)
{
	SDL_Point	flags;
	Uint32		cur;
	Uint32		last;
	int			res;

	flags.x = 0;
	if (!check_start(game))
	{
		game->status = 0;
		return ;
	}
	last = SDL_GetTicks();
	while (!flags.x)
	{
		flags.y = 0;
		cur = SDL_GetTicks();
		if (cur - last > 30)
		{
			if (!(res = game_update(game, &flags)))
				return ;
			last = cur;
		}
	}
	if (game->status != 0 && game->status != 4)
		game->status = 3;
}
