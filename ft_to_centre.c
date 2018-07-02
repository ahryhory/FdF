/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_centre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:23:29 by ahryhory          #+#    #+#             */
/*   Updated: 2017/12/23 15:40:11 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_cord	**ft_transform(t_cord **cord, int c_x, int c_y)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cord[i])
	{
		j = 0;
		while (cord[i][j].end)
		{
			cord[i][j].x -= c_x;
			cord[i][j].y -= c_y;
			cord[i][j].x += 500;
			cord[i][j].y += 500;
			j++;
		}
		i++;
	}
	return (cord);
}

t_cord			**ft_to_centre(t_cord **cord)
{
	size_t	i;
	size_t	j;
	int		c_x;
	int		c_y;

	i = 0;
	j = 0;
	while (cord[i])
		i++;
	while (cord[i / 2][j].end)
		j++;
	c_x = cord[i / 2][j / 2].x;
	c_y = cord[i / 2][j / 2].y;
	cord = ft_transform(cord, c_x, c_y);
	return (cord);
}
