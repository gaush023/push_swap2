/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_sort_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:49:44 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/21 21:37:34 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

// void	print_stacks(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*tmp;

// 	tmp = *stack_a;
// 	printf("stack_a: ");
// 	while (tmp)
// 	{
// 		printf("%d ", tmp->value);
// 		tmp = tmp->next;
// 	}
// 	printf("\n");
// 	tmp = *stack_b;
// 	printf("stack_b: ");
// 	while (tmp)
// 	{
// 		printf("%d ", tmp->value);
// 		tmp = tmp->next;
// 	}
// 	printf("\n");
// }

static void	find_two_max(t_list **stacks, int *flag)
{
	int		max;
	int		second_max;
	t_list	*tmp;

	tmp = *stacks;
	if (ft_lstsize(stacks) == 4)
	{
		flag[0] = find_max_node(*stacks);
		return ;
	}
	max = find_max_node(*stacks);
	if (tmp->value != max)
		second_max = tmp->value;
	else
		second_max = tmp->next->value;
	while (tmp)
	{
		if (tmp->value > second_max && tmp->value != max)
			second_max = tmp->value;
		tmp = tmp->next;
	}
	flag[0] = max;
	flag[1] = second_max;
	flag[2] = 0;
}

void	magic_sort_5(t_list **stack_a, t_list **stack_b)
{
	int	*flag;

	flag = (int *)malloc(sizeof(int) * 3);
	find_two_max(stack_a, flag);
	while (ft_lstsize(stack_a) != 3)
	{
		if ((*stack_a)->value == flag[0] || (*stack_a)->value == flag[1])
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	// print_stacks(stack_a, stack_b);
	if (!is_sorted(stack_a))
		magic_sort_3(stack_a);
	// print_stacks(stack_a, stack_b);
	if ((*stack_b)->value < (*stack_b)->next->value && (*stack_b)->next != NULL)
		ft_sb(stack_b);
	ft_pa(stack_a, stack_b);
	if (*stack_b)
		ft_pa(stack_a, stack_b);
	while ((*stack_a)->value != find_min_node(*stack_a))
		ft_ra(stack_a);
	// print_stacks(stack_a, stack_b);
	free(flag);
}
