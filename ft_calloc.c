/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:14 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/04 18:49:32 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t bit, size_t n)
{
	void	*res;

	res = malloc(bit * n);
	if (bit > ((size_t)1 << 63) - 1 || n > ((size_t)1 << 63) - 1)
		return (0);
	if (!res)
		return (0);
	if (bit == 0 || n == 0)
		return (res);
	ft_bzero(res, bit * n);
	return (res);
}
