/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stack_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:08 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/05 20:43:30 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

static int	find_stack_pos_helper(t_list **stack_a, int **flag, int flag_n)
{
	t_list	*tmp;
	int		back_pos;

	tmp = *stack_a;
	back_pos = 0;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp != NULL && tmp->value >= flag[flag_n][0]
		&& tmp->value < flag[flag_n + 1][0])
	{
		tmp = tmp->prev;
		back_pos++;
	}
	return (back_pos);
}

int	find_stack_pos(t_list **stack_a, int **flag, int flag_n)
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
	back_pos = find_stack_pos_helper(stack_a, flag, flag_n);
	if (back_pos == 0)
		return (pos);
	else if (back_pos > pos)
		return (pos);
	else
		return (back_pos * -1);
}
