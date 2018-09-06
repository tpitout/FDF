/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:56:34 by nhendric          #+#    #+#             */
/*   Updated: 2018/09/06 14:19:31 by tpitout          ###   ########.fr       */
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

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_M 46
# define KEY_TAB 48
# define KEY_ESC 53
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

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
	int			r;
	int			y;
	int			x;
	int			neg;
	int			pull;
	int			push;
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
