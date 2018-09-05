/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:58:20 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 17:58:22 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnset(char *str, int c, int n)
{
	int		i;

	if (!str || !c || !n)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
