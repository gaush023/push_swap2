/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_sort_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:49:44 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/24 23:15:28 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"


static void	sort_min_type(t_list **stack_a)
{
	ft_sa(stack_a);
	ft_ra(stack_a);
}

void	magic_sort_3(t_list **stack_a)
{
	t_list	*node;
	int		max;
	int		min;

	node = *stack_a;
	max = find_max_node(*stack_a);
	min = find_min_node(*stack_a);
	if (min == node->value)
		sort_min_type(stack_a);
	else if (max == node->value)
	{
		ft_ra(stack_a);
		if (!is_sorted(stack_a))
			ft_sa(stack_a);
	}
	else
	{
		if (max == node->next->next->value)
			ft_sa(stack_a);
		else
			ft_rra(stack_a);
	}
}
