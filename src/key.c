/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 22:03:48 by ivelutin          #+#    #+#             */
/*   Updated: 2017/08/10 02:00:13 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keys.h"

int						my_key_(int keycode, t_alpha *vz)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == KEY_UPARROW)
		vz->key.movey -= 1;
	if (keycode == KEY_DOWNARROW)
		vz->key.movey += 1;
	if (keycode == KEY_RIGHTARROW)
		vz->key.movex += 1;
	if (keycode == KEY_LEFTARROW)
		vz->key.movex -= 1;
	mlx_clear_window(vz->mlx.mlx, vz->mlx.win);
	draw(vz);
	return (0);
}

void					color(t_alpha *vz, double x0, double y0, int z)
{
	if (z <= 2)
		mlx_pixel_put(vz->mlx.mlx, vz->mlx.win, x0, y0, vz->color.o1);
	else if (z == 3)
		mlx_pixel_put(vz->mlx.mlx, vz->mlx.win, x0, y0, vz->color.o3);
	else if (z == 4)
		mlx_pixel_put(vz->mlx.mlx, vz->mlx.win, x0, y0, vz->color.o4);
	else if (z == 5)
		mlx_pixel_put(vz->mlx.mlx, vz->mlx.win, x0, y0, vz->color.o5);
	else if (z == 6)
		mlx_pixel_put(vz->mlx.mlx, vz->mlx.win, x0, y0, vz->color.o6);
	else if (z == 7)
		mlx_pixel_put(vz->mlx.mlx, vz->mlx.win, x0, y0, vz->color.o7);
	else if (z == 8)
		mlx_pixel_put(vz->mlx.mlx, vz->mlx.win, x0, y0, vz->color.o8);
	else if (z == 9)
		mlx_pixel_put(vz->mlx.mlx, vz->mlx.win, x0, y0, vz->color.o9);
	else
		mlx_pixel_put(vz->mlx.mlx, vz->mlx.win, x0, y0, vz->color.o10);
}

void					gg_colors(t_alpha *vz, char *aone, char *atwo)
{
	int color1;
	int color2;

	color1 = ft_atoi(aone);
	color2 = ft_atoi(atwo);
	vz->color.o1 = color1;
	vz->color.o2 = color1;
	vz->color.o3 = color1;
	vz->color.o4 = color1;
	vz->color.o5 = color1;
	vz->color.o6 = color2;
	vz->color.o7 = color2;
	vz->color.o8 = color2;
	vz->color.o9 = color2;
	vz->color.o10 = color2;
}

void					default_colors(t_alpha *vz)
{
	vz->color.o1 = 0X00FFFFFF;
	vz->color.o2 = 0X00FFFFFF;
	vz->color.o3 = 0X00FF0000;
	vz->color.o4 = 0X00FFFF00;
	vz->color.o5 = 0X00FF00FF;
	vz->color.o6 = 0X00FF0FF0;
	vz->color.o7 = 0X0000FF00;
	vz->color.o8 = 0X0000FFFF;
	vz->color.o9 = 0X00FF000F;
	vz->color.o10 = 0X00FFFF00;
}
