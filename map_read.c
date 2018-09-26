/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:36:01 by tpitout           #+#    #+#             */
/*   Updated: 2018/09/26 11:10:11 by tpitout          ###   ########.fr       */
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

void		error(void)
{
	ft_putstr(RED "ERROR: INVALID FILE\n");
	exit(1);
}

int			map_read(t_data *in)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	if ((fd = open(in->map_name, O_RDONLY)) == -1)
		error();
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

void		printinfo(t_data *x)
{
	char	b[22];
	char	m[46];
	char	l[46];
	char	r[29];

	ft_strcpy(b, "WELCOME TO TREDX's FDF");
	ft_strcpy(m, "TO ZOOM PRESS [1/2] TO MOVE VIEW USE [W/A/S/D]");
	ft_strcpy(r, "PRESS [R] TO RESET TO DEFAULT");
	ft_strcpy(l, "______________________________________________");
	mlx_string_put(x->inst.mlx, x->inst.win, 20, 15, GRN, b);
	mlx_string_put(x->inst.mlx, x->inst.win, 20, 35, GRN, m);
	mlx_string_put(x->inst.mlx, x->inst.win, 20, 55, GRN, r);
	mlx_string_put(x->inst.mlx, x->inst.win, 20, 75, GRN, l);
}
