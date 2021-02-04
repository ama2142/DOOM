/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_fon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:24:16 by jmalik            #+#    #+#             */
/*   Updated: 2021/01/22 11:17:59 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_roof(t_game *game, int y, int x, int max_y)
{
	y = y - 1;
	while (++y <= max_y)
		game->data[(H_H + y) * S_W + x] = game->level.map.roof;
}

void		draw_floor(t_game *game, int y, int x, int max_y)
{
	y = y - 1;
	while (++y <= max_y)
		game->data[(H_H + y) * S_W + x] = game->level.map.floor;
}
