/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:39:11 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/05 15:37:41 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunc.h"

static t_list	*set_min_heads(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		flag;

	min = NULL;
	flag = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!flag || head->value < min->value))
			{
				min = head;
				flag = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	ft_set_head_node(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = set_min_heads(stack);
	while (head)
	{
		head->index = index++;
		head = set_min_heads(stack);
	}
}
