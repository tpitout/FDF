/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:59:21 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 17:59:23 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		tmp = str[len - 1];
		str[len - 1] = str[i];
		str[i] = tmp;
		i++;
		len--;
	}
	return (str);
}
