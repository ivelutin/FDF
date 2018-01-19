/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 01:02:34 by ivelutin          #+#    #+#             */
/*   Updated: 2017/05/01 21:39:13 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			st_zero(t_alpha *vz)
{
	vz->map.hi = 0;
	vz->map.wid = -1;
	vz->map.len = -1;
	vz->mlx.i = 0;
	vz->mlx.j = 0;
	vz->p.y = 0;
}

char			**ft_read(t_alpha *vz, char *str)
{
	char	*line;
	char	*full;
	char	**cords;

	vz->map.fd = open(str, O_RDONLY);
	if (vz->map.fd == -1)
		exit(0);
	full = ft_strnew(0);
	while (get_next_line(vz->map.fd, &line))
	{
		if (vz->map.hi == 0)
			vz->map.wid = ft_wordcount(line, ' ');
		else if (vz->map.wid != (int)ft_wordcount(line, ' ') &&
				write(1, "Bad File\n", 9))
			exit(0);
		vz->map.hi++;
		line = ft_strjoin(line, " ");
		full = ft_strjoin(full, line);
		free(line);
	}
	cords = ft_strsplit(full, ' ');
	if (close(vz->map.fd) == -1)
		exit(0);
	return (cords);
}

t_cor			**ft_cor(char **tmp, t_alpha *vz)
{
	t_cor	**cor;
	int		y;
	int		x;
	int		n;

	if (!(cor = (t_cor**)ft_memalloc(sizeof(t_cor*) * (vz->map.hi))))
		return (NULL);
	y = -1;
	n = 0;
	while (++y < vz->map.hi)
	{
		if (!(cor[y] = (t_cor*)ft_memalloc(sizeof(t_cor) * (vz->map.wid))))
			return (NULL);
		x = -1;
		while (++x < vz->map.wid)
		{
			cor[y][x].x = x;
			cor[y][x].y = y;
			cor[y][x].z = ft_atoi(tmp[n++]);
			cor[y][x].oz = cor[y][x].z;
		}
	}
	return (cor);
}

int				main(int argc, char **argv)
{
	t_alpha	*vz;
	char	**tmp;

	if (!(vz = (t_alpha*)ft_memalloc(sizeof(t_alpha))))
		return (0);
	if (argc > 1 && argc <= 4)
	{
		st_zero(vz);
		if (argc == 4)
			gg_colors(vz, argv[2], argv[3]);
		else
			default_colors(vz);
		tmp = ft_read(vz, argv[1]);
		vz->cor = ft_cor(tmp, vz);
		vz->mlx.mlx = mlx_init();
		vz->mlx.win = mlx_new_window(vz->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
		just_movin(vz, vz->mlx.i, vz->mlx.j);
		draw(vz);
		mlx_hook(vz->mlx.win, 2, 3, my_key_, vz);
		mlx_string_put(vz->mlx.mlx, vz->mlx.win, 0, 0, 0xFFFFFF, INSTRUCTION);
		mlx_loop(vz->mlx.mlx);
	}
	else
		write(1, "usage: ./fdf [file_name] {color1} {color2}\n", 44);
	return (0);
}
