/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigstacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 03:51:11 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/11 12:38:19 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

// static int	is_reverse_sorted(t_list **stack)
// {
// 	t_list	*head;

// 	head = *stack;
// 	while (head && head->next)
// 	{
// 		if (head->value < head->next->value)
// 			return (0);
// 		head = head->next;
// 	}
// 	return (1);
// }

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

static void	situation_one(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b)
	{
		ft_pb(stack_a, stack_b);
		return ;
	}
	while (ft_lstsize(stack_a) > 3
		&& (*stack_a)->next->value > (*stack_b)->value)
	{
		if ((*stack_a)->value < (*stack_b)->value)
			ft_ra(stack_a);
		else
			ft_pb(stack_a, stack_b);
		return ;
	}
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value)
	{
		ft_pb(stack_a, stack_b);
	}
}

static void	do_the_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		bottom_a_value;
	int		bottom_b_value;

	tmp_a = *stack_a;
	bottom_a_value = (mv_last(tmp_a))->value;
	if (*stack_b)
	{
		tmp_b = *stack_b;
		bottom_b_value = (mv_last(tmp_b))->value;
	}
	// if ((*stack_a)->value < (*stack_a)->next->value
	// 	&& ft_lstsize(stack_a) < ft_lstsize(stack_b))
	// 	ft_sa(stack_a);
	if (!*stack_b || (*stack_a)->value > (*stack_b)->value)
		situation_one(stack_a, stack_b);
	else if ((*stack_a)->value < bottom_b_value)
		situation_two(stack_a, stack_b, bottom_b_value);
	else
		situation_three(stack_a, stack_b, bottom_a_value, bottom_b_value);
}

void	sort_bigstacks(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(stack_a) > 3 && !is_sorted(stack_a))
	{
		do_the_sort(stack_a, stack_b);
		// print_stacks(stack_a, stack_b);
		// if (!is_reverse_sorted(stack_b))
		// 	return (print_stacks(stack_a, stack_b));
	}
	if (!is_sorted(stack_a))
		magic_sort_3(stack_a);
	finish_the_sort(stack_a, stack_b);
	// printf("\n======\nfinish the sort\n======\n");
	// printf("\n======\nfinish\n======\n");
	//
}
