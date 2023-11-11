/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:51:12 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/22 20:31:13 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

void	ft_rra(t_list **stack_a)
{
	t_list	*top;
	int		i;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	i = 0;
	top = *stack_a;
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		i++;
	}
	(*stack_a)->next = top;
	while (i > 1)
	{
		top = top->next;
		i--;
	}
	top->next = NULL;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*top;
	int		i;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	i = 0;
	top = *stack_b;
	while ((*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		i++;
	}
	(*stack_b)->next = top;
	while (i > 1)
	{
		top = top->next;
		i--;
	}
	top->next = NULL;
	write(1, "rrb\n", 4);
}

void	ft_rrr_sub(t_list **stack_b)
{
	t_list	*top;
	int		i;

	i = 0;
	top = *stack_b;
	while ((*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		i++;
	}
	(*stack_b)->next = top;
	while (i > 1)
	{
		top = top->next;
		i--;
	}
	top->next = NULL;
	write(1, "rrr\n", 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*top;
	int		i;

	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	i = 0;
	top = *stack_a;
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		i++;
	}
	(*stack_a)->next = top;
	while (i > 1)
	{
		top = top->next;
		i--;
	}
	top->next = NULL;
	ft_rrr_sub(stack_b);
}
