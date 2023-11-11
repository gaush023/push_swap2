/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:50:14 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/03 20:06:04 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

int	find_max_node(t_list *stacks)
{
	int	max;

	max = stacks->value;
	stacks = stacks->next;
	while (stacks)
	{
		if (max < stacks->value)
			max = stacks->value;
		stacks = stacks->next;
	}
	return (max);
}

int	find_min_node(t_list *stacks)
{
	int	min;

	min = stacks->value;
	stacks = stacks->next;
	while (stacks)
	{
		if (min > stacks->value)
			min = stacks->value;
		stacks = stacks->next;
	}
	return (min);
}

int	find_median(t_list **stack_b)
{
	t_list	*tmp;
	int		target;
	int		n;

	tmp = *stack_b;
	n = 0;
	target = ft_lstsize(stack_b) / 2;
	while (n < target)
	{
		tmp = tmp->next;
		n++;
	}
	return (tmp->value);
}
