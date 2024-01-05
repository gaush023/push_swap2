/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacksb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:08 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/05 21:00:06 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

int	set_stacks_typea(t_list **stack_a, t_list **stack_b, int **flag, int flag_n)
{
	ft_pb(stack_a, stack_b);
	if ((*stack_b)->value > flag[flag_n][1])
		ft_rb(stack_b);
	return (1);
}

int	set_stacks_typeb(t_list **stack_a, t_list **stack_b, int **flag, int flag_n)
{
	int	stack_pos;

	stack_pos = find_stack_pos(stack_a, flag, flag_n);
	while (stack_pos != 0)
	{
		ft_ra(stack_a);
		stack_pos--;
	}
	ft_pb(stack_a, stack_b);
	if ((*stack_b)->value > flag[flag_n][1])
		ft_rr(stack_a, stack_b);
	return (1);
}

int	set_stacks_typec(t_list **stack_a, t_list **stack_b, int **flag, int flag_n)
{
	int	stack_pos;

	stack_pos = find_stack_pos(stack_a, flag, flag_n);
	while (stack_pos != 0)
	{
		ft_rra(stack_a);
		stack_pos++;
	}
	ft_pb(stack_a, stack_b);
	if ((*stack_b)->value > flag[flag_n][1])
		ft_rr(stack_a, stack_b);
	return (1);
}

void	set_stacksb(t_list **stack_a, t_list **stack_b, int **flag,
		int stop_pos)
{
	int	stack_pos;
	int	flag_n;
	int	i;

	flag_n = 0;
	i = 0;
	while (*stack_a)
	{
		stack_pos = find_stack_pos(stack_a, flag, flag_n);
		if (stack_pos == 0)
			i = i + set_stacks_typea(stack_a, stack_b, flag, flag_n);
		else if (stack_pos > 0)
			i = i + set_stacks_typeb(stack_a, stack_b, flag, flag_n);
		else
			i = i + set_stacks_typec(stack_a, stack_b, flag, flag_n);
		if (i == stop_pos && flag[flag_n + 1] != NULL)
		{
			flag_n++;
			i = 0;
		}
	}
}
