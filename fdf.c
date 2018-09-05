/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:46:00 by tpitout           #+#    #+#             */
/*   Updated: 2018/09/05 12:13:51 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int			press(int key, t_data *in)
{

	if (key == KEY_ESC)
		exit(1);
	if (key == KEY_A)
	{
		in->pull += 1;
		fill(in);
	}
	return (0);
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
	in->pull = 0;
	map_read(in);
	mlx_new_image(in->inst.mlx, WIN_W, WIN_H );
	fill(in);
	mlx_key_hook(in->inst.win, press, in);
	mlx_loop(in->inst.mlx);
	return (0);
}
