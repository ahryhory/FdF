/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_locale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:48:28 by ahryhory          #+#    #+#             */
/*   Updated: 2017/12/23 15:44:51 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cord		**ft_to_locale(t_cord **cord)
{
	size_t	rows;
	size_t	columns;
	int		r;
	int		c;

	rows = 0;
	columns = 0;
	while (cord[rows])
		rows++;
	while (cord[rows / 2][columns].end)
		columns++;
	r = cord[rows / 2][columns / 2].y;
	c = cord[rows / 2][columns / 2].x;
	rows = 0;
	while (cord[rows])
	{
		columns = 0;
		while (cord[rows][columns].end)
		{
			cord[rows][columns].x -= c;
			cord[rows][columns++].y -= r;
		}
		rows++;
	}
	return (cord);
}
