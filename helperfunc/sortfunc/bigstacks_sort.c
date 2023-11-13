/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigstacks_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:08 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/13 20:02:00 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"
#include <stdio.h>

void	print_stacks(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	printf("stack: ");
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

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
		if (i % stop_pos == 0)
		{
			printf("i: %d\n", i);
			flag[flag_n][0] = array[i - 1];
			flag[flag_n][1] = flag[flag_n][0] - stop_pos / 2;
			printf("array: %d\n", array[i]);
			printf("flag: %d\n", flag[flag_n][0]);
			flag_n++;
		}
		if (min_idx != i)
			ft_swap(&array[min_idx], &array[i]);
		i++;
	}
	flag[flag_n] = NULL;
}

void	bigstacks_sort(t_list **stack_a, t_list **stack_b)
{
	int	**flag;
	int	flag_n;
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
	stop_pos = ft_lstsize(stack_a) / 5;
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
	size = transform_int(stack_a, array);
	find_stop_pos(array, flag, size, stop_pos);
	i = 0;
	flag_n = 1;
	printf("stop_pos: %d\n", stop_pos);
	printf("flag: %d\n", flag[flag_n][0]);
	print_stacks(stack_a);
	while (*stack_a)
	{
		if (flag[flag_n][0] >= (*stack_a)->value)
		{
			printf("stack_a:%d\n", (*stack_a)->value);
			ft_pb(stack_a, stack_b);
			if ((*stack_b)->value > flag[flag_n][1])
				ft_rb(stack_b);
			printf("flag: %d\n", flag[flag_n][0]);
			printf("flag2: %d\n", flag[flag_n][1]);
			i++;
		}
		else
		{
			if (flag[flag_n] && flag[flag_n][0] == i)
			{
				printf("stack_a:%d\n", (*stack_a)->value);
				printf("flag: %d\n", flag[flag_n][0]);
				if (flag[flag_n + 1] != NULL)
					flag_n++;
				else
				{
					while (*stack_a)
					{
						if ((*stack_b)->value > flag[flag_n][0] + stop_pos / 2)
							ft_rb(stack_b);
						printf("flag: %d\n", flag[flag_n][0] + stop_pos / 2);
						ft_pb(stack_a, stack_b);
					}
					break ;
				}
				printf("flag: %d\n", flag[flag_n][0]);
				print_stacks(stack_a);
				print_stacks(stack_b);
			}
			else
				ft_ra(stack_a);
		}
	}
	print_stacks(stack_b);
	i = 0;
	while (flag[flag_n][0] < mv_last(*stack_b)->value)
	{
		ft_rrb(stack_b);
		if ((*stack_b)->value == find_max_node(*stack_b))
		{
			ft_pa(stack_a, stack_b);
			i++;
		}
	}
	while (i != 20)
	{
		printf("stack_b:%d\n", (*stack_b)->value);
		while ((*stack_b)->value != find_max_node(*stack_b))
			ft_rb(stack_b);
		printf("find_max_node: %d\n", find_max_node(*stack_b));
		print_stacks(stack_a);
		print_stacks(stack_b);
		ft_pa(stack_a, stack_b);
		i++;
	}
	printf("flag: %d\n", flag[flag_n][0]);
	print_stacks(stack_b);
	print_stacks(stack_a);
	i = 0;
	while (i <= 10)
	{
		free(flag[i]);
		i++;
	}
	free(flag);
	free(array);
}
