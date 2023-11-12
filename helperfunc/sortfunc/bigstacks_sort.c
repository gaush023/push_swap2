/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigstacks_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:08 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/12 20:57:38 by sagemura         ###   ########.fr       */
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
		if (i % stop_pos == 0)
		{
			flag[0] = array[i];
			flag_n++;
		}
		i++;
	}
}

void	bigstacks_sort(t_list **stack_a, t_list **stack_b)
{
	int	**flag;
	int	flag_n;
	int	*array;
	int	size;
	int	stop_pos;

	array = (int *)malloc(sizeof(int) * ft_lstsize(stack_a) + 1);
	if (!array)
		return (free(array));
	size = transform_int(stack_a, array);
	stop_pos = ft_lstsize(stack_a) / 5;
	flag = (int *)malloc(sizeof(int *) * stop_pos + 1);
	if (!flag)
		return (free(flag));
	size = transform_int(stack_a, array);
	find_stop_pos(array, flag, size, stop_pos);
	flag_n = 0;
	while (flag[flag_n])
	{
		printf("%d\n", flag[flag_n][0]);
		flag_n++;
	}
	while (*stack_a)
	{
		if (flag[flag_n][0] > (*stack_a)->value)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		if (flag[flag_n][0] == (*stack_a)->value)
		{
			ft_pb(stack_a, stack_b);
			flag_n++;
		}
		(*stack_a) = (*stack_a)->next;
	}
}
