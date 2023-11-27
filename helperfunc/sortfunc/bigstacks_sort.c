/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigstacks_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:08 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/27 18:23:20 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

static int	free_allocated_flag(int **flag)
{
	free(flag);
	return (-1);
}

static int	allocate_flag(t_list **stack_a, int **flag, int stop_pos)
{
	int	i;

	if (ft_lstsize(stack_a) > 20)
		stop_pos = ft_lstsize(stack_a) / 5;
	else
		stop_pos = ft_lstsize(stack_a) / 2;
	flag = (int **)malloc(sizeof(int *) * 11);
	if (!flag)
		return (free_allocated_flag(flag));
	i = 0;
	while (i <= 11)
	{
		flag[i] = (int *)malloc(sizeof(int));
		if (!flag[i])
		{
			while (i-- > 0)
				free(flag[i]);
			free(flag);
			return (-1);
		}
		i++;
	}
	return (stop_pos);
}

void	bigstacks_sort(t_list **stack_a, t_list **stack_b)
{
	int	**flag;
	int	*array;
	int	size;
	int	stop_pos;
	int	i;

	flag = NULL;
	stop_pos = 0;
	array = (int *)malloc(sizeof(int) * ft_lstsize(stack_a) + 1);
	if (!array)
	{
		free(array);
		return ;
	}
	size = transform_int(stack_a, array);
	stop_pos = allocate_flag(stack_a, flag, stop_pos);
	find_stop_pos(array, flag, size, stop_pos);
	set_stacksb(stack_a, stack_b, flag, stop_pos);
	finish_bigstacks_sort(stack_a, stack_b, flag);
	i = 11;
	while (i-- > 0)
		free(flag[i]);
	free(flag);
	free(array);
}
