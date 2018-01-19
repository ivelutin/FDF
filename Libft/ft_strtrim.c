/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:09:01 by ivelutin          #+#    #+#             */
/*   Updated: 2017/01/15 19:09:02 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(const char *s)
{
	char	*st;
	char	*end;

	if (!s)
		return (NULL);
	st = (char *)s;
	end = ft_strchr(s, 0) - 1;
	while (ft_skip(*st))
		++st;
	while (ft_skip(*end) && end > st)
		--end;
	return (ft_strsub(st, 0, 1 + end - st));
}
