/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:03:57 by ahryhory          #+#    #+#             */
/*   Updated: 2017/12/24 14:07:30 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_get_data(t_cord **elm, char **arr, size_t fst_line, int row)
{
	size_t		i;
	t_cord		*elem;

	elem = *elm;
	i = 0;
	while (i < fst_line)
	{
		elem[i].x = i;
		elem[i].y = row;
		ft_parse_z_col(arr[i], elem, i);
		elem[i].end = 1;
		i++;
	}
	elem[i].end = 0;
}

static t_cord	*ft_get_elem(char *line, int row, size_t *first_line)
{
	t_cord	*elem;
	size_t	size;
	char	**arr;

	if ((arr = ft_strsplit(line, ' ')) == NULL)
		ft_err(4);
	size = 0;
	while (arr[size])
		size++;
	if (row == 0)
		*first_line = size;
	if (size < *first_line)
		ft_err(2);
	elem = (t_cord *)malloc(sizeof(t_cord) * (*first_line + 1));
	if (elem == NULL)
		ft_err(4);
	ft_get_data(&elem, arr, *first_line, row);
	ft_clr(&arr);
	return (elem);
}

static size_t	ft_line_count(int fd)
{
	size_t	line_count;
	int		err;
	char	*line;

	line_count = 0;
	while ((err = ft_get_next_line(fd, &line)) == 1)
	{
		line_count++;
		ft_strdel(&line);
	}
	if (err < 0)
		ft_err(3);
	return (line_count);
}

static void		ft_read_line(t_cord **cord, int fd)
{
	size_t		i;
	int			err;
	char		*line;
	size_t		first_line;

	i = 0;
	while ((err = ft_get_next_line(fd, &line)) == 1)
	{
		cord[i] = ft_get_elem(line, i, &first_line);
		ft_strdel(&line);
		i++;
	}
	if (err < 0)
		ft_err(3);
	cord[i] = NULL;
}

t_cord			**ft_get_coordinate(char *path)
{
	size_t		line_count;
	t_cord		**cord;
	int			fd;

	if ((fd = open(path, O_RDONLY)) < 0)
		ft_err(3);
	line_count = ft_line_count(fd);
	cord = (t_cord **)malloc(sizeof(t_cord *) * (line_count + 1));
	if (cord == NULL)
		ft_err(4);
	if (close(fd) < 0)
		ft_err(3);
	if ((fd = open(path, O_RDONLY)) < 0)
		ft_err(3);
	ft_read_line(cord, fd);
	if (close(fd) < 0)
		ft_err(3);
	return (cord);
}
