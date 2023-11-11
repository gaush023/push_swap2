/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigstacks_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:08 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/11 18:58:49 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

t_list	*sort_copylist(t_list **stacks)
{

}

void	bigstacks_sort(t_list **stack_a, t_list **stack_b)
{
	int flag;
	stack_b = NULL;

	t_list *tmp;
	tmp = sort_copylist(copy_list(stack_a));

	flag = find_stop_pos(stack_a);
	printf("flag: %d\n", flag);
}