/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stacka.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/08 19:24:04 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

int	add_stacka_typea(t_list **stack_a, t_list **stack_b, int median)
{
	int	bottom_b_value;
	int	bottom_a_value;
	int	back_pos;

	bottom_b_value = (mv_last(*stack_b))->value;
	back_pos = (*stack_b)->value;
	while ((*stack_a)->value < (*stack_b)->value)
		ft_rb(stack_b);
	bottom_b_value = mv_last(*stack_b)->value;
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
		&& (*stack_a)->value > (*stack_b)->value)
	{
		if ((*stack_a)->value > (*stack_a)->next->value
			&& (*stack_a)->next->value > (*stack_b)->value)
			ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
	bottom_a_value = (mv_last(*stack_a))->value;
	while (ft_lstsize(stack_a) > 3 && bottom_a_value < bottom_b_value
		&& bottom_a_value > (*stack_b)->value)
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
		bottom_a_value = (mv_last(*stack_a))->value;
	}
	bottom_b_value = (mv_last(*stack_b))->value;
	while (ft_lstsize(stack_a) > 3
		&& (*stack_a)->next->value > (*stack_b)->value
		&& bottom_b_value > (*stack_a)->next->value)
	{
		ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
		bottom_b_value = (mv_last(*stack_b))->value;
	}
	while (ft_lstsize(stack_a) > 3 && !is_sorted(stack_a)
		&& (*stack_b)->value != back_pos)
	{
		if (front_size(stack_b) <= back_size(stack_b) * 0.7
			&& ft_lstsize(stack_a) < ft_lstsize(stack_b))
			return (quit_thesort_typea(stack_a, stack_b, median));
		if ((*stack_a)->value > median && (*stack_a)->value < (*stack_b)->value)
			add_stacka_typea(stack_a, stack_b, median);
		ft_rrr(stack_a, stack_b);
		bottom_b_value = (mv_last(*stack_b))->value;
		while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
			&& (*stack_a)->value > (*stack_b)->value)
			ft_pb(stack_a, stack_b);
	}
	return (0);
}

int	add_stacka_typeb(t_list **stack_a, t_list **stack_b, int back_pos,
		int median)
{
	int	bottom_b_value;
	int	bottom_a_value;

	bottom_b_value = (mv_last(*stack_b))->value;
	while ((*stack_a)->value > bottom_b_value)
	{
		ft_rrb(stack_b);
		bottom_b_value = (mv_last(*stack_b))->value;
	}
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
		&& (*stack_a)->value > (*stack_b)->value)
		ft_pb(stack_a, stack_b);
	bottom_a_value = (mv_last(*stack_a))->value;
	while (ft_lstsize(stack_a) > 3 && bottom_a_value > (*stack_b)->value
		&& bottom_b_value > bottom_a_value)
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
		bottom_a_value = (mv_last(*stack_a))->value;
	}
	bottom_b_value = (mv_last(*stack_b))->value;
	while (ft_lstsize(stack_a) > 3
		&& (*stack_a)->next->value > (*stack_b)->value
		&& bottom_b_value > (*stack_a)->next->value)
	{
		ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
		bottom_b_value = (mv_last(*stack_b))->value;
	}
	while (ft_lstsize(stack_a) > 3 && !is_sorted(stack_a)
		&& (*stack_b)->value != back_pos)
	{
		if (front_size(stack_b) >= back_size(stack_b) * 0.7
			&& ft_lstsize(stack_a) < ft_lstsize(stack_b))
			return (quit_thesort_typeb(stack_a, stack_b, median));
		if (median > (*stack_a)->value && (*stack_a)->value > (*stack_b)->value)
			add_stacka_typeb(stack_a, stack_b, (*stack_b)->value, median);
		ft_rr(stack_a, stack_b);
		bottom_b_value = (mv_last(*stack_b))->value;
		while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
			&& (*stack_a)->value > (*stack_b)->value)
			ft_pb(stack_a, stack_b);
	}
	return (0);
}
