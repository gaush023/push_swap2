/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:43:50 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/03 20:09:21 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunc.h"

int	back_size(t_list **stack_b)
{
	t_list	*tmp;
	int		back_size;

	tmp = *stack_b;
	back_size = 0;
	while (tmp && tmp->next)
	{
		if (tmp->value < tmp->next->value)
			break ;
		tmp = tmp->next;
	}
	if (tmp->next)
		tmp = tmp->next;
	else
		return (0);
	while (tmp && tmp->next)
	{
		if (tmp->value < tmp->next->value)
			break ;
		tmp = tmp->next;
		back_size++;
	}
	return (back_size);
}
