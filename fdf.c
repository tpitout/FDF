/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:57:06 by nhendric          #+#    #+#             */
/*   Updated: 2018/09/04 12:50:36 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int			press(int key)
{
	if (key == 53)
		exit(1);
	return (0);
}

int			main(int ac, char **av)
{
	t_data	*in;

	if (av[1] == 0 || ac != 2)
	{
		ft_putstr(BOLDRED "ERROR: INVALID INPUT/FILE");
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
	map_read(in);
	fill(in);
	mlx_key_hook(in->inst.win, press, 0);
	mlx_loop(in->inst.mlx);
	return (0);
}
