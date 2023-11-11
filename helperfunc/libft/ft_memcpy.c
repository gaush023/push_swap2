/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:36:26 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/02 00:15:58 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	size_t			z;
	unsigned char	*uc_dest;
	unsigned char	*uc_src;

	if (src == NULL && dest == NULL)
		return (NULL);
	z = 0;
	uc_dest = (unsigned char *)dest;
	uc_src = (unsigned char *)src;
	while (z < n)
	{
		uc_dest[z] = uc_src[z];
		z++;
	}
	return (dest);
}
