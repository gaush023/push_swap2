/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three_type_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/08 19:25:03 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"
#include <stdio.h>

// static void	print_stacks(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*tmp_a;
// 	t_list	*tmp_b;

// 	tmp_a = *stack_a;
// 	tmp_b = *stack_b;
// 	printf("stack_a: ");
// 	while (tmp_a)
// 	{
// 		printf("%d ", tmp_a->value);
// 		tmp_a = tmp_a->next;
// 	}
// 	printf("\n");
// 	printf("stack_b: ");
// 	while (tmp_b)
// 	{
// 		printf("%d ", tmp_b->value);
// 		tmp_b = tmp_b->next;
// 	}
// 	printf("\n");
// }

static int	find_stop_pos(int ini_nbr, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	while ((tmp)->value > ini_nbr)
		tmp = tmp->next;
	return ((tmp)->value);
}

void	situation_three_type_b(t_list **stack_a, t_list **stack_b,
		int bottom_a_value, int bottom_b_value)
{
	int	stop_pos;
	int	ini_pos_b;
	int	median;
	int	flag;

	// print_stacks(stack_a, stack_b);
	stop_pos = find_stop_pos((*stack_a)->value, stack_b);
	ini_pos_b = (*stack_b)->value;
	median = find_median(stack_b);
	flag = 0;
	while ((*stack_b)->value != stop_pos)
		ft_rrb(stack_b);
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
		&& bottom_b_value > (*stack_a)->value)
	{
		if ((*stack_a)->value > (*stack_a)->next->value
			&& (*stack_a)->next->value > (*stack_b)->value)
			ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
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
	}
	while (ft_lstsize(stack_a) > 3 && !is_sorted(stack_a)
		&& (*stack_b)->value != ini_pos_b)
	{
		if (median > (*stack_a)->value && (*stack_a)->value > (*stack_b)->value)
			flag = add_stacka_typeb(stack_a, stack_b, (*stack_b)->value,
					median);
		if (flag == 1)
			return ;
		ft_rr(stack_a, stack_b);
		bottom_b_value = (*stack_b)->value;
		while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
			&& (*stack_a)->value > (*stack_b)->value)
			ft_pb(stack_a, stack_b);
	}
	// printf("ini_pos: %d\n", ini_pos_b);
	// print_stacks(stack_a, stack_b);
}
