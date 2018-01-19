/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:47:13 by ivelutin          #+#    #+#             */
/*   Updated: 2017/01/18 16:47:14 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nextword(const char *s, char c, size_t *ele)
{
	size_t	i;

	i = 0;
	while (s[*ele] == c)
		*ele += 1;
	i = *ele;
	while (s[*ele])
	{
		if (s[*ele] == c)
			break ;
		*ele += 1;
	}
	return (ft_strsub(s, i, *ele - i));
}
