/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:16:38 by ivelutin          #+#    #+#             */
/*   Updated: 2017/05/01 21:47:53 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../Libft/libft.h"

# define INSTRUCTION	"move left (left key)/\n move up (up key)/\n move right (right key)/\n move down (down key)"
# define WIN_WIDTH		1700
# define WIN_HEIGHT		1280
# define BETA			M_PI / 180

typedef struct		s_p
{
	int				dx;
	int				dy;
	int				err;
	int				sx;
	int				sy;
	int				e2;
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	int				y;
}					t_p;
typedef struct		s_key
{
	int				esc;
	int				prvx;
	int				prvy;
	int				movex;
	int				movey;
	int				zoomx;
	int				zoomy;
}					t_key;

typedef struct		s_mlx
{
	void			*win;
	void			*mlx;
	int				i;
	int				j;
	int				mox;
	int				moy;
	int				scale;
}					t_mlx;

typedef struct		s_cor
{
	int				x;
	int				y;
	int				z;
	int				oz;
}					t_cor;

typedef struct		s_map
{
	int				len;
	int				ret;
	int				fd;
	int				wid;
	int				hi;
}					t_map;

typedef struct		s_color
{
	int				o1;
	int				o2;
	int				o3;
	int				o4;
	int				o5;
	int				o6;
	int				o7;
	int				o8;
	int				o9;
	int				o10;

}					t_color;

typedef struct		s_alpha
{
	t_map			map;
	t_cor			**cor;
	t_mlx			mlx;
	t_key			key;
	t_p				p;
	t_color			color;

}					t_alpha;

/*
**		check.c
*/
char			**ft_read(t_alpha *vz, char *str);
void			st_zero(t_alpha *vz);
t_cor			**ft_cor(char **tmp, t_alpha *vz);
int				main(int ac, char **argv);

/*
**		mlx.c
*/
void			draw(t_alpha *vz);
void			line(t_alpha *vz, int z);
void			just_movin(t_alpha *vz, int i, int j);

/*
**		key.c
*/
int				my_key_(int keycode, t_alpha *vz);
void			color(t_alpha *vz, double x0, double y0, int z);
void			default_colors(t_alpha *vz);
void			gg_colors(t_alpha *vz, char *color1, char *color2);

#endif
