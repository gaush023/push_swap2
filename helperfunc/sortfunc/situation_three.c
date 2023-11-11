/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:40:09 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/11 09:34:05 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

int	find_insertion_pos(int i_p, t_list **stack_b)
{
	int		n;
	t_list	*tmp;

	tmp = *stack_b;
	n = 0;
	while (tmp)
	{
		if (tmp->value < i_p)
			return (n);
		tmp = tmp->next;
		n++;
	}
	return (n);
}

void	situation_three(t_list **stack_a, t_list **stack_b, int bottom_a_value,
		int bottom_b_value)
{
	int	rra_flag;

	if (bottom_a_value > (*stack_b)->value)
	{
		while (ft_lstsize(stack_a) > 3 && bottom_a_value > (*stack_b)->value)
		{
			ft_rra(stack_a);
			ft_pb(stack_a, stack_b);
			bottom_a_value = (mv_last(*stack_a))->value;
		}
		return ;
	}
	if (ft_lstsize(stack_a) > 3 && bottom_a_value < bottom_b_value)
	{
		rra_flag = (*stack_b)->value;
		while (bottom_a_value < bottom_b_value)
		{
			ft_rra(stack_a);
			bottom_a_value = mv_last(*stack_a)->value;
		}
		if (ft_lstsize(stack_a) > 3)
			ft_pb(stack_a, stack_b);
		while (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
			&& bottom_b_value > (*stack_a)->value)
			ft_pb(stack_a, stack_b);
		while (rra_flag != (*stack_b)->value)
			ft_rr(stack_a, stack_b);
		return ;
	}
	if (ft_lstsize(stack_a) > ft_lstsize(stack_b)
		&& ((find_max_node(*stack_a) > find_max_node(*stack_b))
			&& (find_min_node(*stack_a) < find_min_node(*stack_b))))
	{
		while (1)
		{
			ft_ra(stack_a);
			if ((*stack_a)->value > (*stack_b)->value
				|| bottom_b_value > (*stack_a)->value)
			break ;
		}
		return ;
	}
	if (find_insertion_pos((*stack_a)->value, stack_b) < ft_lstsize(stack_b)
		/ 2)
		situation_three_type_a(stack_a, stack_b, bottom_b_value);
	else
		situation_three_type_b(stack_a, stack_b, bottom_a_value,
				bottom_b_value);
}
