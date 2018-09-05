/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:53:46 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 17:53:47 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	i = 0;
	while (dst[i] && i < n)
		i++;
	len_dst = i;
	if ((n + i) == 0)
		return (i + len_src);
	while (src[i - len_dst] && i < n - 1)
	{
		dst[i] = src[i - len_dst];
		i++;
	}
	if (len_dst < n)
		dst[i] = '\0';
	return (len_dst + len_src);
}
