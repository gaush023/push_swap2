/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_the_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:50:14 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/11 12:21:30 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

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

int	find_pos(t_list **stack_a, int min)
{
	t_list	*tmp;
	int		pos;

	tmp = *stack_a;
	pos = 0;
	while (tmp && tmp->next)
	{
		if (tmp->value == min)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (0);
}

void	finish_the_sort(t_list **stack_a, t_list **stack_b)
{
	int	bottom_a_value;
	int	median_a;
	int	back_pos;

	bottom_a_value = mv_last(*stack_a)->value;
	median_a = find_median(stack_a);
	// print_stacks(stack_a, stack_b);
	// printf("median_a: %d\n", median_a);
	if ((*stack_b)->value < (*stack_a)->value)
	{
		// print_stacks(stack_a, stack_b);
		while (*stack_b && (*stack_b)->value < (*stack_a)->value)
			ft_pa(stack_a, stack_b);
	}
	else if ((*stack_b)->value > bottom_a_value)
	{
		// print_stacks(stack_a, stack_b);
		back_pos = (*stack_a)->value;
		while (*stack_b && (*stack_b)->value > bottom_a_value)
			ft_pa(stack_a, stack_b);
		while ((*stack_a)->value != back_pos)
			ft_ra(stack_a);
	}
	else if (*stack_b && median_a > (*stack_b)->value)
	{
		// print_stacks(stack_a, stack_b);
		back_pos = (*stack_a)->value;
		while ((*stack_b)->value > (*stack_a)->value)
			ft_ra(stack_a);
		bottom_a_value = mv_last(*stack_a)->value;
		while (*stack_b && (*stack_b)->value < (*stack_a)->value
			&& bottom_a_value < (*stack_b)->value)
			ft_pa(stack_a, stack_b);
		if (ft_lstsize(stack_a) > find_pos(stack_a, find_min_node(*stack_a)))
		{
			while (back_pos != (*stack_a)->value)
				ft_rra(stack_a);
		}
		else
		{
			while (back_pos != (*stack_a)->value)
				ft_ra(stack_a);
		}
	}
	else if (*stack_b && median_a < (*stack_b)->value)
	{
		// print_stacks(stack_a, stack_b);
		back_pos = (*stack_a)->value;
		while ((*stack_b)->value < bottom_a_value)
		{
			ft_rra(stack_a);
			bottom_a_value = mv_last(*stack_a)->value;
		}
		bottom_a_value = mv_last(*stack_a)->value;
		while (*stack_b && (*stack_b)->value < (*stack_a)->value
			&& bottom_a_value < (*stack_b)->value)
			ft_pa(stack_a, stack_b);
		if (ft_lstsize(stack_a) > find_pos(stack_a, find_min_node(*stack_a)))
		{
			while (back_pos != (*stack_a)->value)
				ft_ra(stack_a);
		}
		else
		{
			while (back_pos != (*stack_a)->value)
				ft_rra(stack_a);
		}
	}
	if (*stack_b)
		finish_the_sort(stack_a, stack_b);
	else
		return ;
}
