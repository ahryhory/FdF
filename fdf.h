/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:47:49 by ahryhory          #+#    #+#             */
/*   Updated: 2017/12/24 15:20:20 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "includes/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# define ABS(a) (a < 0 ? -(a) : a)

typedef struct		s_cord
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				end;
}					t_cord;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	double			angls[3];
	double			scale;
	t_cord			**s_cord;
	t_cord			**cord;
}					t_mlx;

t_cord				**ft_get_coordinate(char *path);
t_cord				**ft_rotate(t_cord **cord, double x, double y, double z);
void				ft_draw(t_mlx *q_mlx, t_cord **cord);
t_cord				**ft_to_centre(t_cord **cord);
t_cord				**ft_to_locale(t_cord **lst);
t_cord				**ft_scale(t_cord **cord, double n);
int					ft_get_scale(t_cord **cord);
t_cord				**ft_cordcpy(t_cord **cord);
void				ft_err(int key);
void				ft_clr(char ***str);
void				ft_cordclr(t_cord **cord);
void				ft_parse_z_col(char *str, t_cord *elem, size_t i);
int					ft_redraw(t_mlx *p, int key, double rt, double sc);

#endif
