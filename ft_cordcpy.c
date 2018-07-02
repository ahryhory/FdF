/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cordcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 11:46:42 by ahryhory          #+#    #+#             */
/*   Updated: 2017/12/23 17:30:57 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_cord	**ft_cpy(t_cord **new_cord, t_cord **cord)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cord[i])
	{
		j = 0;
		while (cord[i][j].end)
		{
			new_cord[i][j].x = cord[i][j].x;
			new_cord[i][j].y = cord[i][j].y;
			new_cord[i][j].z = cord[i][j].z;
			new_cord[i][j].color = cord[i][j].color;
			new_cord[i][j].end = 1;
			j++;
		}
		new_cord[i][j].end = 0;
		i++;
	}
	new_cord[i] = NULL;
	return (new_cord);
}

t_cord			**ft_cordcpy(t_cord **cord)
{
	t_cord	**new_cord;
	size_t	i;
	size_t	j;

	i = 0;
	while (cord[i])
		i++;
	new_cord = (t_cord **)malloc(sizeof(t_cord *) * (i + 1));
	i = 0;
	while (cord[i])
	{
		j = 0;
		while (cord[i][j].end)
			j++;
		new_cord[i] = (t_cord *)malloc(sizeof(t_cord) * (j + 1));
		i++;
	}
	new_cord = ft_cpy(new_cord, cord);
	return (new_cord);
}
