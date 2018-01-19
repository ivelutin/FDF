/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 01:33:32 by ivelutin          #+#    #+#             */
/*   Updated: 2017/05/03 23:05:41 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void			ladilla(t_alpha *vz, int y, int x)
{
	vz->p.x0 = vz->cor[y][x].x + vz->key.movex;
	vz->p.y0 = vz->cor[y][x].y + vz->key.movey;
	vz->p.x1 = vz->cor[y + 1][x].x + vz->key.movex;
	vz->p.y1 = vz->cor[y + 1][x].y + vz->key.movey;
}

void					line(t_alpha *vz, int z)
{
	vz->p.dx = fabs(vz->p.x1 - vz->p.x0);
	vz->p.sx = vz->p.x0 < vz->p.x1 ? 1 : -1;
	vz->p.dy = fabs(vz->p.y1 - vz->p.y0);
	vz->p.sy = vz->p.y0 < vz->p.y1 ? 1 : -1;
	vz->p.err = (vz->p.dx > vz->p.dy ? vz->p.dx : -vz->p.dy) / 2;
	vz->p.e2 = 0;
	while (1)
	{
		color(vz, vz->p.x0, vz->p.y0, z);
		if (vz->p.x0 == vz->p.x1 && vz->p.y0 == vz->p.y1)
			break ;
		vz->p.e2 = vz->p.err;
		if (vz->p.e2 > -vz->p.dx)
		{
			vz->p.err -= vz->p.dy;
			vz->p.x0 += vz->p.sx;
		}
		if (vz->p.e2 < vz->p.dy)
		{
			vz->p.err += vz->p.dx;
			vz->p.y0 += vz->p.sy;
		}
	}
}

void					draw(t_alpha *vz)
{
	int x;

	vz->p.y = 0;
	while (vz->p.y < vz->map.hi)
	{
		x = 0;
		while (x < vz->map.wid)
		{
			if (x + 1 != vz->map.wid)
			{
				vz->p.x0 = vz->cor[vz->p.y][x].x + vz->key.movex;
				vz->p.y0 = vz->cor[vz->p.y][x].y + vz->key.movey;
				vz->p.x1 = vz->cor[vz->p.y][x + 1].x + vz->key.movex;
				vz->p.y1 = vz->cor[vz->p.y][x + 1].y + vz->key.movey;
				line(vz, vz->cor[vz->p.y][x].oz);
			}
			if (vz->p.y + 1 != vz->map.hi)
			{
				ladilla(vz, vz->p.y, x);
				line(vz, vz->cor[vz->p.y][x].oz);
			}
			x++;
		}
		vz->p.y++;
	}
}

static	void			anguuulo(t_cor *vz)
{
	float	tmpx;
	float	tmpy;
	float	tmpyy;

	tmpx = vz->x;
	tmpy = vz->y;
	tmpyy = vz->y;
	vz->x = (vz->x * cos(15 * (BETA))) + (vz->y * sin(15 * (BETA)));
	vz->y = (tmpx * -sin(15 * (BETA))) + (vz->y * cos(15 * (BETA)));
	vz->y = (tmpy * cos(atan(-sqrt(2)))) + (vz->z * sin(atan(-sqrt(2))));
	vz->z = (tmpyy * -sin(atan(-sqrt(2)))) + (vz->z * cos(atan(-sqrt(2))));
}

void					just_movin(t_alpha *vz, int i, int j)
{
	if (vz->map.wid > vz->map.hi)
		vz->mlx.scale = ceil(((float)WIN_HEIGHT / 2) /
			((float)vz->map.hi - 1));
	else
		vz->mlx.scale = ceil(((float)WIN_WIDTH / 2) / ((float)vz->map.wid - 1));
	vz->mlx.mox = (WIN_WIDTH - ((vz->map.wid - 1) * vz->mlx.scale)) / 2;
	vz->mlx.moy = (WIN_HEIGHT - ((vz->map.hi - 1) * vz->mlx.scale)) / 2;
	j = 0;
	while (j < vz->map.hi)
	{
		i = 0;
		while (i < vz->map.wid)
		{
			vz->cor[j][i].x *= vz->mlx.scale;
			vz->cor[j][i].y *= vz->mlx.scale;
			vz->cor[j][i].z *= vz->mlx.scale;
			vz->cor[j][i].x -= vz->mlx.mox;
			vz->cor[j][i].y -= vz->mlx.moy;
			anguuulo(&vz->cor[j][i]);
			vz->cor[j][i].y += (WIN_WIDTH / 2);
			vz->cor[j][i].x += (WIN_HEIGHT / 2);
			i++;
		}
		j++;
	}
}
