/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:36:01 by tpitout           #+#    #+#             */
/*   Updated: 2018/09/05 10:39:53 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int			i_store(t_data *in)
{
	int		i;
	int		j;

	i = 0;
	while (i < in->map_h)
	{
		in->dots[i] = (t_dot *)malloc(sizeof(t_dot ) * in->map_w);
		j = 0;
		while (j < in->map_w)
		{
			in->dots[i][j].z =
				ft_atoi(in->data_proc->data[i][j]);
			free(in->data_proc->data[i][j]);
			j++;
		}
		free(in->data_proc->data[i]);
		i++;
	}
	return (0);
}

int			line_w(t_data *in)
{
	int		i;
	int		j;
	int		cnt;

	i = 0;
	j = 0;
	cnt = 0;
	if (!(in->data_proc->data = (char ***)malloc(sizeof(char **) *
					in->map_h + 1)))
		return (-1);
	while (i < in->map_h)
	{
		in->data_proc->data[i] = ft_strsplit(in->data_proc->cap[i], ' ');
		free(in->data_proc->cap[i]);
		i++;
	}
	free(in->data_proc->cap);
	i = 0;
	while (in->data_proc->data[i][j++])
		cnt++;
	in->map_w = cnt;
	i_store(in);
	return (0);
}

int			map_read(t_data *in)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(in->map_name, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		i++;
	close(fd);
	fd = open(in->map_name, O_RDONLY);
	in->map_h = i;
	in->st = (t_spa *)malloc(sizeof(t_spa));
	in->dots = (t_dot **)malloc(sizeof(t_dot *) * in->map_h);
	in->data_proc = (t_proc *)malloc(sizeof(t_proc));
	if (!(in->data_proc->cap = (char **)malloc(sizeof(char *) * i + 1)))
		return (-1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
		in->data_proc->cap[i++] = line;
	close(fd);
	line_w(in);
	return (0);
}
