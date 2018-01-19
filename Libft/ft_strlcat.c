/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:07:09 by ivelutin          #+#    #+#             */
/*   Updated: 2017/01/16 19:07:11 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int d_size;
	int s_size;

	d_size = ft_strlen(dst);
	s_size = ft_strlen(src);
	i = -1;
	if (d_size > (int)size)
		return (size + s_size);
	while (src[++i] && i < (int)size - d_size - 1)
		dst[i + d_size] = src[i];
	dst[i + d_size] = '\0';
	return (s_size + d_size);
}
