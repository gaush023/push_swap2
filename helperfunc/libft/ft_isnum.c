/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:40:06 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/03 04:10:51 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnum(const char *str)
{
	size_t	n;

	n = 0;
	if (str[n] == '-' || str[n] == '+')
		n++;
	if (str[n] == '\0')
		return (0);
	while (str[n] != '\0')
	{
		if (!(str[n] >= '0' && str[n] <= '9'))
			return (0);
		n++;
	}
	return (1);
}

// #include <stdio.h>

// int	main(int argc, char *argv[1])
// {
// 	int	n;

// 	n = ft_isnum(argv[1]);
// 	printf("%d", n);
// }
