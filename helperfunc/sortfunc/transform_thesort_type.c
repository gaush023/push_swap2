/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_thesort_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/06 17:04:45 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

static int	find_median_type_s(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		target;
	int		n;

	tmp = *stack;
	target = 0;
	n = 0;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			break ;
		tmp = tmp->next;
	}
	tmp2 = tmp;
	while (tmp2 && tmp2->next)
	{
		tmp2 = tmp2->next;
		target++;
	}
	while (n < target)
	{
		tmp = tmp->next;
		n++;
	}
	return (tmp->value);
}

int	quit_thesort_typea(t_list **stack_a, t_list **stack_b, int median)
{
	int	max_b;
	int	bottom_b_value;

	max_b = find_max_node(*stack_b);
	bottom_b_value = (mv_last(*stack_b))->value;
	median = find_median_type_s(stack_b);
	while ((*stack_b)->value != max_b)
	{
		if (bottom_b_value > (*stack_a)->value
			&& (*stack_a)->value > (*stack_b)->value)
			add_stacka_typeb(stack_a, stack_b, (*stack_b)->value, median);
		ft_rr(stack_a, stack_b);
		bottom_b_value = (mv_last(*stack_b))->value;
		while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
			&& (*stack_a)->value > (*stack_b)->value)
			ft_pb(stack_a, stack_b);
	}
	return (1);
}

int	quit_thesort_typeb(t_list **stack_a, t_list **stack_b, int median)
{
	int	max_b;
	int	bottom_b_value;

	max_b = find_max_node(*stack_b);
	bottom_b_value = mv_last(*stack_b)->value;
	median = find_median_type_s(stack_b);
	while ((*stack_b)->value != max_b)
	{
		if ((*stack_a)->value > median && (*stack_a)->value < (*stack_b)->value)
			add_stacka_typea(stack_a, stack_b, median);
		ft_rrr(stack_a, stack_b);
		bottom_b_value = (mv_last(*stack_b))->value;
		while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
			&& (*stack_a)->value > (*stack_b)->value)
			ft_pb(stack_a, stack_b);
	}
	return (1);
}
