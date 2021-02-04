/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:24:16 by jmalik            #+#    #+#             */
/*   Updated: 2021/01/20 15:15:26 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	def_wallparams(t_player *player, t_drawer *drawer)
{
	double alpha;

	alpha = (player->sec.fov * (S_W / 2 - drawer->cursor[0])) / (double)S_W;
	drawer->wall_len = (S_W / (drawer->raylen[0] * cos(alpha)));
}

void	engine(t_game *game, t_isec *isec, int x)
{
	t_drawer	dr;
	t_player	*player;
	t_map		*map;
	int			side;

	isec->height = 1;
	player = &(game->player);
	map = &(game->level.map);
	dr.cursor[0] = x + H_W;
	def_raylen(map, player, &dr);
	def_walltile(map, &dr);
	def_walltile_u(&dr);
	def_wallparams(player, &dr);
	isec->dist = dr.raylen[0];
	isec->height = dr.wall_len / 2;
	if (dr.wall_part)
		side = player->obj.pos.y < dr.barrier_d[1] ? 0 : 2;
	else
		side = player->obj.pos.x < dr.barrier_d[0] ? 3 : 1;
	isec->number =
		game->level.map.elem[dr.barrier_d[1]][dr.barrier_d[0]].side[side];
	isec->colum = dr.tex_u;
	if (side < 2)
		isec->colum = 63 - dr.tex_u;
}
