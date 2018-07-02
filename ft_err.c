/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:17:29 by ahryhory          #+#    #+#             */
/*   Updated: 2017/12/24 15:36:24 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_err(int key)
{
	if (key == 1)
	{
		ft_putendl_fd("usage: ./fdf source_file", 2);
		exit(0);
	}
	if (key == 2)
	{
		ft_putendl_fd("Found wrong line length.", 2);
		exit(0);
	}
	if (key == 3)
	{
		perror("Error");
		exit(0);
	}
	if (key == 4)
	{
		ft_putendl_fd("Problem with memory allocation", 2);
		exit(0);
	}
}
