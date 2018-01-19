/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:37:59 by ivelutin          #+#    #+#             */
/*   Updated: 2017/01/12 16:38:06 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*mstr;

	if (s == NULL || f == NULL)
		return (NULL);
	mstr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mstr == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		mstr[i] = f(s[i]);
	mstr[i] = '\0';
	return (mstr);
}
