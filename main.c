/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:51:00 by ahryhory          #+#    #+#             */
/*   Updated: 2017/12/24 14:59:04 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_control(int k, t_mlx *q_mlx)
{
	t_cord	**cord;

	cord = q_mlx->s_cord;
	if (k == 53)
	{
		ft_cordclr(cord);
		exit(0);
	}
	if ((k >= 123 && k <= 126) || k == 0 || k == 2 || k == 13 || k == 1)
		ft_redraw(q_mlx, k, 1, 0.1);
	return (0);
}

static int		ft_exit_x(t_mlx *p)
{
	ft_cordclr(p->s_cord);
	exit(0);
	return (0);
}

static t_mlx	ft_crt_mlx(char *path)
{
	t_mlx	mlx;

	mlx.angls[0] = 45;
	mlx.angls[1] = -45;
	mlx.angls[2] = -33;
	mlx.cord = ft_get_coordinate(path);
	mlx.s_cord = ft_cordcpy(mlx.cord);
	mlx.scale = ft_get_scale(mlx.cord);
	mlx.cord = ft_scale(mlx.cord, mlx.scale);
	mlx.cord = ft_rotate(mlx.cord, mlx.angls[0], mlx.angls[1], mlx.angls[2]);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1000, 1000, "FdF");
	return (mlx);
}

int				main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		ft_err(1);
	mlx = ft_crt_mlx(av[1]);
	ft_draw(&mlx, mlx.cord);
	mlx_hook(mlx.win, 2, 5, ft_control, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, ft_exit_x, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
