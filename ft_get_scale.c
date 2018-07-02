/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:09:17 by ahryhory          #+#    #+#             */
/*   Updated: 2017/12/24 15:16:41 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_scale(t_cord **cord)
{
	size_t	rows;
	size_t	columns;
	double	res;

	rows = 0;
	columns = 0;
	while (cord[rows])
		rows++;
	while (cord[rows / 2][columns].end)
		columns++;
	res = 1000 / rows + 1000 / columns;
	return (res / 4);
}
