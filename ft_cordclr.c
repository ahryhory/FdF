/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cordclr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 17:08:00 by ahryhory          #+#    #+#             */
/*   Updated: 2017/12/24 11:10:52 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_cordclr(t_cord **cord)
{
	size_t		i;

	i = 0;
	while (cord[i])
	{
		free(cord[i]);
		cord[i] = NULL;
		i++;
	}
	free(cord[i]);
	cord[i] = NULL;
	free(cord);
	cord = NULL;
}
