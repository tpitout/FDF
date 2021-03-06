/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:46:00 by tpitout           #+#    #+#             */
/*   Updated: 2018/09/26 11:07:07 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void		create(t_data *in)
{
	mlx_clear_window(in->inst.mlx, in->inst.win);
	mlx_new_image(in->inst.mlx, WIN_W, WIN_H);
	fill(in);
}

int			press(int key, t_data *in)
{
	if (key == KEY_ESC)
	{
		exit(1);
		return (0);
	}
	if (key == KEY_ONE)
		in->p += 1;
	if (key == KEY_TWO)
		in->p -= 1;
	if (key == KEY_W)
		in->y -= 30;
	if (key == KEY_S)
		in->y += 30;
	if (key == KEY_A)
		in->x += 30;
	if (key == KEY_D)
		in->x -= 30;
	if (key == KEY_R)
		reset(in);
	create(in);
	printinfo(in);
	return (0);
}

int			ft_exit(t_data *in)
{
	in->r = 0;
	in->y = 0;
	exit(0);
	return (0);
}

void		init(t_data *x)
{
	x->r = 0;
	x->y = 0;
	x->x = 0;
	x->neg = 0;
	x->p = 1;
	x->m = 1;
}

int			main(int ac, char **av)
{
	t_data	*in;

	if (av[1] == 0 || ac != 2)
	{
		ft_putstr(RED "ERROR: INVALID INPUT/FILE");
		exit(1);
	}
	if (!(in = (t_data *)malloc(sizeof(t_data))))
		return (-1);
	in->map_name = ft_strdup(av[1]);
	in->map_name = av[1];
	in->inst.mlx = mlx_init();
	if (!in->inst.mlx)
		return (0);
	if (!(in->inst.win = mlx_new_window(in->inst.mlx,
		WIN_W, WIN_H, in->map_name)))
		return (0);
	init(in);
	map_read(in);
	create(in);
	printinfo(in);
	mlx_key_hook(in->inst.win, press, in);
	mlx_hook(in->inst.win, 17, 0, ft_exit, in);
	mlx_loop(in->inst.mlx);
	return (0);
}
