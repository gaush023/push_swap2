/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigstacks_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:08 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/17 18:51:28 by sagemura         ###   ########.fr       */
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

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	find_stop_pos(int *array, int **flag, int size, int stop_pos)
{
	int	i;
	int	j;
	int	min_idx;
	int	flag_n;

	i = 0;
	flag_n = 0;
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

void	bigstacks_sort(t_list **stack_a, t_list **stack_b)
{
	int	**flag;
	int	*array;
	int	size;
	int	stop_pos;
	int	i;

	array = (int *)malloc(sizeof(int) * ft_lstsize(stack_a) + 1);
	if (!array)
	{
		free(array);
		return ;
	}
	size = transform_int(stack_a, array);
	if (ft_lstsize(stack_a) > 20)
		stop_pos = ft_lstsize(stack_a) / 5;
	else
		stop_pos = ft_lstsize(stack_a) / 2;
	flag = (int **)malloc(sizeof(int *) * 11);
	if (!flag)
	{
		free(array);
		return ;
	}
	i = 0;
	while (i <= 11)
	{
		flag[i] = (int *)malloc(sizeof(int));
		if (!flag[i])
		{
			while (i-- > 0)
				free(flag[i]);
			free(flag);
			return ;
		}
		i++;
	}
	find_stop_pos(array, flag, size, stop_pos);
	set_stacksb(stack_a, stack_b, flag, stop_pos);
	finish_bigstacks_sort(stack_a, stack_b, flag);
	i = 0;
	while (i <= 10)
	{
		free(flag[i]);
		i++;
	}
	free(flag);
	free(array);
}
