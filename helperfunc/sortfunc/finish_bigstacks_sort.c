/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_bigstacks_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:08 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/05 20:31:44 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

static int	find_max_pos(t_list **stacks)
{
	t_list	*tmp;
	int		stacks_size;
	int		target;
	int		n;

	target = find_max_node(*stacks);
	tmp = *stacks;
	stacks_size = ft_lstsize(stacks);
	n = 0;
	while (tmp->value != target)
	{
		tmp = tmp->next;
		n++;
	}
	if (n < stacks_size / 2)
		return (1);
	else
		return (-1);
}

void	finish_bigstacks_sort_helper(t_list **stack_a, t_list **stack_b)
{
	int	max_pos;

	while (*stack_b)
	{
		max_pos = find_max_pos(stack_b);
		if (max_pos > 0)
		{
			while ((*stack_b)->value != find_max_node(*stack_b))
				ft_rb(stack_b);
		}
		else
		{
			while ((*stack_b)->value != find_max_node(*stack_b))
				ft_rrb(stack_b);
		}
		ft_pa(stack_a, stack_b);
	}
}

void static	loop_helper(t_list **stack_b, int max_pos)
{
	if (max_pos > 0)
	{
		while ((*stack_b)->value != find_max_node(*stack_b))
			ft_rb(stack_b);
	}
	else
	{
		while ((*stack_b)->value != find_max_node(*stack_b))
			ft_rrb(stack_b);
	}
}

void	finish_bigstacks_sort(t_list **stack_a, t_list **stack_b, int **flag)
{
	int	max_pos;
	int	flag_n;

	flag_n = 0;
	while (flag[flag_n] != NULL && flag[flag_n + 1] != NULL)
		flag_n++;
	while (*stack_b)
	{
		while (flag[flag_n][0] < mv_last(*stack_b)->value
			&& flag[flag_n][0] < (*stack_b)->value)
		{
			max_pos = find_max_pos(stack_b);
			loop_helper(stack_b, max_pos);
			ft_pa(stack_a, stack_b);
		}
		if (flag_n == 0)
			return (finish_bigstacks_sort_helper(stack_a, stack_b));
		flag_n--;
	}
}
