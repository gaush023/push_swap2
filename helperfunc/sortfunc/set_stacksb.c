/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacksb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:08 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/17 20:25:39 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"
#include <stdio.h>

void	print_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	printf("stack_a: ");
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = *stack_b;
	printf("stack_b: ");
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

static int	find_stack_pos(t_list **stack_a, int **flag, int flag_n)
{
	int		pos;
	int		stack_size;
	int		n;
	int		tmp_lenght;
	int		tmp_value;
	t_list	*tmp;

	tmp = *stack_a;
	pos = 0;
	if (flag[flag_n + 1] == NULL)
		return (0);
	while (tmp)
	{
		if (tmp->value >= flag[flag_n][0] && tmp->value < flag[flag_n + 1][0])
			break ;
		tmp = tmp->next;
		pos++;
	}
	stack_size = ft_lstsize(stack_a);
	n = pos;
	while (stack_size - pos != n && tmp)
	{
		tmp = tmp->next;
		n++;
	}
	n = 0;
	tmp_lenght = 0;
	tmp_value = 0;
	while (tmp)
	{
		if (tmp->value >= flag[flag_n][0] && tmp->value < flag[flag_n + 1][0])
			tmp_value = n;
		tmp = tmp->next;
		n++;
		tmp_lenght++;
	}
	if (tmp_value == 0)
		return (pos);
	else
		tmp_value = tmp_lenght - tmp_value;
	if (n > pos)
		return (pos);
	else
		return (tmp_value * -1);
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
		// if (stop_pos > ft_lstsize(stack_a) / 2)
		// {
		// 	print_stacks(stack_a, stack_b);
		// 	printf("stack_pos: %d\n", stop_pos);
		// 	printf("lstsize: %d\n", ft_lstsize(stack_a));
		// 	printf("=====================\n");
		// 	return ;
		// }
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
				ft_rb(stack_b);
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
				ft_rb(stack_b);
			i++;
		}
		if (i == stop_pos && flag[flag_n + 1] != NULL)
		{
			flag_n++;
			i = 0;
		}
	}
}
