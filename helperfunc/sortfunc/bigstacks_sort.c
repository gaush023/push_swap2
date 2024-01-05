/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigstacks_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:08 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/05 18:59:31 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

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

void	sort_array(int *array, int size)
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

void	set_flags(int **flag, int *array, int size, int stop_pos)
{
	int	i;
	int	flag_n;

	i = 0;
	flag_n = 0;
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

	if (allocate_array_memory(&array, ft_lstsize(stack_a)) == -1)
		return ;
	size = transform_int(stack_a, array);
	if (ft_lstsize(stack_a) > 20)
		stop_pos = ft_lstsize(stack_a) / 5;
	else
		stop_pos = ft_lstsize(stack_a) / 2;
	if (allocate_flag_memory(&flag) == -1)
		return (free(array));
	sort_array(array, size);
	set_flags(flag, array, size, stop_pos);
	set_stacksb(stack_a, stack_b, flag, stop_pos);
	finish_bigstacks_sort(stack_a, stack_b, flag);
	delete_memory(flag, array);
}
