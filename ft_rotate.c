/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:03:02 by ahryhory          #+#    #+#             */
/*   Updated: 2018/01/15 12:26:37 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <pthread.h>

static t_cord	**ft_rotate_x(t_cord **cord, double sin, double cos)
{
	size_t	i;
	size_t	j;
	double	y;
	double	z;

	i = 0;
	while (cord[i])
	{
		j = 0;
		while (cord[i][j].end)
		{
			y = cord[i][j].y;
			z = cord[i][j].z;
			cord[i][j].y = y * cos - z * sin;
			cord[i][j].z = z * cos + y * sin;
			j++;
		}
		i++;
	}
	return (cord);
}

static t_cord	**ft_rotate_y(t_cord **cord, double sin, double cos)
{
	size_t	i;
	size_t	j;
	double	x;
	double	z;

	i = 0;
	while (cord[i])
	{
		j = 0;
		while (cord[i][j].end)
		{
			x = cord[i][j].x;
			z = cord[i][j].z;
			cord[i][j].x = x * cos - z * sin;
			cord[i][j].z = z * cos + x * sin;
			j++;
		}
		i++;
	}
	return (cord);
}

static t_cord	**ft_rotate_z(t_cord **cord, double sin, double cos)
{
	size_t	i;
	size_t	j;
	double	x;
	double	y;

	i = 0;
	while (cord[i])
	{
		j = 0;
		while (cord[i][j].end)
		{
			x = cord[i][j].x;
			y = cord[i][j].y;
			cord[i][j].x = x * cos - y * sin;
			cord[i][j].y = y * cos + x * sin;
			j++;
		}
		i++;
	}
	return (cord);
}

t_cord			**ft_rotate(t_cord **cord, double x, double y, double z)
{
	double	angle[3];

	angle[0] = x * (M_PI / 180.0);
	angle[1] = y * (M_PI / 180.0);
	angle[2] = z * (M_PI / 180.0);
	cord = ft_to_locale(cord);
	cord = ft_rotate_x(cord, sin(angle[0]), cos(angle[0]));
	cord = ft_rotate_y(cord, sin(angle[1]), cos(angle[1]));
	cord = ft_rotate_z(cord, sin(angle[2]), cos(angle[2]));
	cord = ft_to_centre(cord);
	return (cord);
}
