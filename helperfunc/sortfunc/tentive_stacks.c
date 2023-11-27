/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tentive_stacks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:08 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/27 18:10:10 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"
#include <stdio.h>

int	transform_int(t_list **stacks, int *array)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stacks;
	while (tmp)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort_tentive_stacks(int *array, int size)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	j = i + 1;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (array[min_idx] > array[j])
				min_idx = j;
			j++;
		}
		if (min_idx != i)
			ft_swap(&array[min_idx], &array[i]);
		i++;
	}
}

void	find_stop_pos(int *array, int **flag, int size, int stop_pos)
{
	int	flag_n;
	int	i;

	flag_n = 0;
	sort_tentive_stacks(array, size);
	i = 0;
	while (i < size)
	{
		if (i % stop_pos == 0)
		{
			flag[flag_n][0] = array[i];
			flag[flag_n][1] = flag[flag_n][0] + stop_pos / 2;
			flag_n++;
		}
		i++;
	}
	flag[flag_n] = NULL;
}
