/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redraw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 13:56:12 by ahryhory          #+#    #+#             */
/*   Updated: 2017/12/24 14:00:09 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_cord	**ft_rescale(t_cord **cord, t_mlx *p, int key, double sc)
{
	if (key == 13)
		cord = ft_scale(cord, p->scale += sc);
	if (key == 1)
		cord = ft_scale(cord, p->scale -= sc);
	cord = ft_rotate(cord, p->angls[0], p->angls[1], p->angls[2]);
	return (cord);
}

int				ft_redraw(t_mlx *p, int key, double rt, double sc)
{
	t_cord	**cord;

	cord = ft_cordcpy(p->s_cord);
	mlx_clear_window(p->mlx, p->win);
	if ((key >= 123 && key <= 126) || key == 0 || key == 2)
	{
		cord = ft_scale(cord, p->scale);
		if (key == 124)
			cord = ft_rotate(cord, p->angls[0], p->angls[1] -= rt, p->angls[2]);
		if (key == 123)
			cord = ft_rotate(cord, p->angls[0], p->angls[1] += rt, p->angls[2]);
		if (key == 125)
			cord = ft_rotate(cord, p->angls[0] -= rt, p->angls[1], p->angls[2]);
		if (key == 126)
			cord = ft_rotate(cord, p->angls[0] += rt, p->angls[1], p->angls[2]);
		if (key == 0)
			cord = ft_rotate(cord, p->angls[0], p->angls[1], p->angls[2] -= rt);
		if (key == 2)
			cord = ft_rotate(cord, p->angls[0], p->angls[1], p->angls[2] += rt);
	}
	else if (key == 13 || key == 1)
		cord = ft_rescale(cord, p, key, sc);
	ft_draw(p, cord);
	return (0);
}
