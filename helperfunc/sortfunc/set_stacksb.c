/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacksb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:08 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/27 19:30:28 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

static void	set_stacksb_typea(t_list **stack_a, t_list **stack_b, int **flag,
		int flag_n)
{
	ft_pb(stack_a, stack_b);
	if ((*stack_b)->value > flag[flag_n][1])
		ft_rb(stack_b);
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
			set_stacksb_typea(stack_a, stack_a, flag, flag_n);
		else if (stack_pos > 0)
		{
			while (stack_pos != 0)
			{
				ft_ra(stack_a);
				stack_pos--;
			}
			ft_pb(stack_a, stack_b);
			if ((*stack_b)->value > flag[flag_n][1])
				ft_rr(stack_a, stack_b);
		}
		else
		{
			while (stack_pos != 0)
			{
				ft_rra(stack_a);
				stack_pos++;
			}
			ft_pb(stack_a, stack_b);
			if ((*stack_b)->value > flag[flag_n][1])
				ft_rr(stack_a, stack_b);
		}
		i++;
		if (i == stop_pos && flag[flag_n + 1] != NULL)
		{
			flag_n++;
			i = 0;
		}
	}
}
