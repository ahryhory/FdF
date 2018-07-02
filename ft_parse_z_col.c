/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_z_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 12:52:07 by ahryhory          #+#    #+#             */
/*   Updated: 2017/12/24 13:49:24 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_strtol(char *str)
{
	int		res;
	int		i;
	int		step;
	char	c;

	step = 0;
	res = 0;
	while (str[step])
		step++;
	step -= 3;
	i = 2;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			res += (10 + str[i] - 'A') * pow(16, step--);
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += (10 + str[i] - 'a') * pow(16, step--);
		else
		{
			c = str[i];
			res += ft_atoi(&c) * pow(16, step--);
		}
		i++;
	}
	return (res);
}

void			ft_parse_z_col(char *str, t_cord *elem, size_t i)
{
	char	**arr;
	int		res;

	elem[i].z = ft_atoi(str);
	if (ft_strchr(str, ','))
	{
		arr = ft_strsplit(str, ',');
		if (arr == NULL)
			ft_err(4);
		res = ft_strtol(arr[1]);
		ft_clr(&arr);
		elem[i].color = res;
	}
	else
		elem[i].color = 0xFFFFFF;
}
