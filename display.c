/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:06:47 by tpitout           #+#    #+#             */
/*   Updated: 2018/09/10 15:09:53 by tpitout          ###   ########.fr       */
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

void		zoom(int i, int j, t_data *z)
{
	int		x;

	x = 0;
	if (z->p > 0)
	{
		z->dots[i][j].x *= z->p;
		z->dots[i][j].y *= z->p;
	}
	else if (z->p < 0)
	{
		x = z->p;
		x = (x * -1) + 1;
		z->dots[i][j].x /= x;
		z->dots[i][j].y /= x;
	}
	else if (z->p == 0)
	{	
		z->dots[i][j].x /= 1;
		z->dots[i][j].y /= 1;
	}
	
}
	

int			fill(t_data *z)
{
	int			i;
	int			j;

	i = 0;
	while (i < z->map_h)
	{
		j = 0;
		while (j < z->map_w)	
		{
			z->dots[i][j].x = (((j * (15)) + (1) *
			  (-1 * z->dots[i][j].z)) + (100 + z->x));
			z->dots[i][j].y = (((i * (15)) + (2.5)  *
			 	(-1 * z->dots[i][j].z)) + (100 - z->y));
			zoom(i, j, z);
			j++;
		}
		i++;
	}
	grid(z);
	return (0);
}
