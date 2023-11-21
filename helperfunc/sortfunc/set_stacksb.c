/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacksb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:08 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/21 20:00:50 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"
#include <stdio.h>

static int	find_stack_pos(t_list **stack_a, int **flag, int flag_n)
{
	int		pos;
	int		back_pos;
	t_list	*tmp;

	tmp = *stack_a;
	pos = 0;
	back_pos = 0;
	if (flag[flag_n + 1] == NULL)
		return (0);
	while (tmp)
	{
		if (tmp->value >= flag[flag_n][0] && tmp->value < flag[flag_n + 1][0])
			break ;
		tmp = tmp->next;
		pos++;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp != NULL && tmp->value >= flag[flag_n][0]
		&& tmp->value < flag[flag_n + 1][0])
	{
		tmp = tmp->prev;
		back_pos++;
	}
	if (back_pos == 0)
		return (pos);
	else if (back_pos > pos)
		return (pos);
	else
		return (back_pos * -1);
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
		{
			ft_pb(stack_a, stack_b);
			if ((*stack_b)->value > flag[flag_n][1])
				ft_rb(stack_b);
			i++;
		}
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
			i++;
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
			i++;
		}
		if (i == stop_pos && flag[flag_n + 1] != NULL)
		{
			flag_n++;
			i = 0;
		}
	}
}
