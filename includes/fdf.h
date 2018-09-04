/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:56:34 by nhendric          #+#    #+#             */
/*   Updated: 2018/08/16 18:40:35 by nhendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_H 1440
# define WIN_W 2560

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct	s_spa
{
	int			zoom;
	int			hor_sh;
	int			ver_sh;
	int			hor_sp;
	int			ver_sp;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
}				t_spa;

typedef struct	s_dot
{
	double		x;
	double		y;
	double		z;
}				t_dot;

typedef	struct	s_proc
{
	int			***data_int;
	int			**cap_int;
	char		***data;
	char		**cap;
}				t_proc;

typedef	struct	s_win
{
	void		*mlx;
	void		*win;
}				t_win;

typedef	struct	s_data
{
	char		*map_name;
	int			map_h;
	int			map_w;
	t_dot		**dots;
	t_spa		*st;
	t_win		inst;
	t_proc		*data_proc;
}				t_data;

int				map_read(t_data *input);
int				line_w(t_data *input);
int				i_store(t_data *input);
int				fill(t_data *input);
void			grid(t_data *in);
void			draw(t_dot s, t_dot e, t_data *input);
float			abs_val(float val);

#endif
