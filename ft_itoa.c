/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naomi <naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:19:31 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/25 02:18:56 by naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int val)
{
	size_t	i;
	int		n;
	char	*str;

	i = 1;
	n = val;
	while (n && i++ < 11)
		n /= 10;
	if (val == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (val <= 0)
		i++;
	str = ft_calloc(1, i + 1);
	if (!str)
		return (0);
	ft_memset(str, 48, 1);
	if (val < 0)
		val *= -1;
	while (val && i-- > 0)
	{
		ft_memset(str, 45, 1);
		str[i] = val % 10 + 48;
		val /= 10;
	}
	return (str);
}
