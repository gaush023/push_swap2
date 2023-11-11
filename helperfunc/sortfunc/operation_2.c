/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:51:12 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/08 18:36:39 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

void	ft_ra(t_list **stack_a)
{
	t_list	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = mv_last(*stack_a);
	(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = mv_last(*stack_b);
	(*stack_b)->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	tmp = *stack_a;
	*stack_a = mv_last(*stack_a);
	(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	tmp = *stack_b;
	*stack_b = mv_last(*stack_b);
	(*stack_b)->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	write(1, "rr\n", 3);
}
