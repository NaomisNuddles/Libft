/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naomi <naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:19:31 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/22 20:26:52 by naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *src, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_calloc(1, ft_strlen(src) + 1);
	if (!str)
		return (0);
	while (src && f && src[i])
	{
		str[i] = f(i, src[i]);
		i++;
	}
	return (str);
}
