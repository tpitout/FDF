/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 21:11:45 by nhendric          #+#    #+#             */
/*   Updated: 2018/09/04 12:51:03 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

float		abs_val(float val)
{
	if (val < 0)
		return (val *= -1);
	return (val);
}

void		draw(t_dot s, t_dot e, t_data *in)
{
	double		x_c;
	double		y_c;

	if (s.x != e.x)
	{
		x_c = s.x;
		if (s.x > e.x)
			x_c = e.x;
		while (x_c <= e.x || x_c <= s.x)
		{
			mlx_pixel_put(in->inst.mlx, in->inst.win, x_c, (((e.y - s.y) /
							(e.x - s.x)) * x_c + (s.y - ((e.y - s.y) /
									(e.x - s.x)) * s.x)), 0x00FFFFFF);
			x_c++;
		}
	}
	else
	{
		y_c = s.y;
		if (y_c > e.y)
			y_c = e.y;
		while (y_c <= s.y || y_c <= e.y)
			mlx_pixel_put(in->inst.mlx, in->inst.win, s.x, y_c++, 0x00FFFFFF);
	}
}

void		grid(t_data *in)
{
	int		i;
	int		j;

	i = 0;
	while (i < in->map_h)
	{
		j = 0;
		while (j < in->map_w)
		{
			if (j != 0)
				draw(in->dots[i][j - 1], in->dots[i][j], in);
			if (i != 0)
			{
				if (j < in->map_w)
					draw(in->dots[i - 1][j], in->dots[i][j], in);
			}
			j++;
		}
		i++;
	}
}

int			fill(t_data *in)
{
	int			i;
	int			j;

	i = 0;
	while (i < in->map_h)
	{
		j = 0;
		while (j < in->map_w)
		{
			in->dots[i][j].x = ((j * 30) + 2 * (-1 * in->dots[i][j].z)) + 50;
			in->dots[i][j].y = ((i * 30) + 1 * (-1 * in->dots[i][j].z)) + 50;
			j++;
		}
		i++;
	}
	grid(in);
	return (0);
}
