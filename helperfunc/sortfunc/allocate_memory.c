/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:30:10 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/05 18:41:46 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

int	allocate_array_memory(int **array, int size)
{
	*array = (int *)malloc(sizeof(int) * size);
	if (!*array)
		return (-1);
	return (0);
}

int	allocate_flag_memory(int ***flag)
{
	int	i;

	*flag = (int **)malloc(sizeof(int *) * 11);
	if (!*flag)
		return (-1);
	i = 0;
	while (i < 11)
	{
		(*flag)[i] = (int *)malloc(sizeof(int));
		if (!(*flag)[i])
		{
			while (i-- > 0)
				free((*flag)[i]);
			free(*flag);
			return (-1);
		}
		i++;
	}
	return (0);
}
