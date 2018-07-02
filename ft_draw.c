/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 15:24:08 by ahryhory          #+#    #+#             */
/*   Updated: 2017/12/24 14:53:46 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_line(t_cord crd1, t_cord crd2, void *mx, void *wn)
{
	int			delta_x;
	int			delta_y;
	int			error2;
	int			error;

	delta_x = ABS(crd2.x - crd1.x);
	delta_y = ABS(crd2.y - crd1.y);
	error = ABS(crd2.x - crd1.x) - ABS(crd2.y - crd1.y);
	mlx_pixel_put(mx, wn, crd2.x, crd2.y, crd2.color);
	while (crd1.x != crd2.x || crd1.y != crd2.y)
	{
		mlx_pixel_put(mx, wn, crd1.x, crd1.y, crd1.color);
		error2 = error * 2;
		if (error2 > -delta_y)
		{
			error -= delta_y;
			crd1.x += crd1.x < crd2.x ? 1 : -1;
		}
		if (error2 < delta_x)
		{
			error += delta_x;
			crd1.y += crd1.y < crd2.y ? 1 : -1;
		}
	}
}

static void		ft_print_controlinfo(t_mlx *p)
{
	int			colr;

	colr = 0xFFFFFF;
	mlx_string_put(p->mlx, p->win, 3, 3, colr, "x:    arrows up and down");
	mlx_string_put(p->mlx, p->win, 3, 20, colr, "y:    arrows left and right");
	mlx_string_put(p->mlx, p->win, 3, 35, colr, "z:    keys   A and D");
	mlx_string_put(p->mlx, p->win, 3, 50, colr, "zoom: keys   W and S");
}

void			ft_draw(t_mlx *p, t_cord **cord)
{
	size_t		i;
	size_t		j;

	ft_print_controlinfo(p);
	i = 0;
	while (cord[i])
	{
		j = 0;
		while (cord[i][j].end)
		{
			if (cord[i][j + 1].end)
				ft_line(cord[i][j], cord[i][j + 1], p->mlx, p->win);
			if (cord[i + 1])
				ft_line(cord[i][j], cord[i + 1][j], p->mlx, p->win);
			j++;
		}
		i++;
	}
	ft_cordclr(cord);
}
