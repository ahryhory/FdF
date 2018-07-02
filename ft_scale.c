/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:43:20 by ahryhory          #+#    #+#             */
/*   Updated: 2017/12/23 12:20:10 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cord	**ft_scale(t_cord **cord, double n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cord[i])
	{
		j = 0;
		while (cord[i][j].end)
		{
			cord[i][j].x *= n;
			cord[i][j].y *= n;
			cord[i][j].z *= n;
			j++;
		}
		i++;
	}
	cord = ft_to_centre(cord);
	return (cord);
}
