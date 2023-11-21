/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:43:50 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/21 19:29:37 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunc.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_list	*mv_last(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*tmp;

	if (*stack)
	{
		tmp = mv_last(*stack);
		tmp->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

int	ft_lstsize(t_list **stack)
{
	int		i;
	t_list	*tmp;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	front_size(t_list **stack_b)
{
	t_list	*tmp;
	int		n;

	tmp = *stack_b;
	n = 0;
	while (tmp && tmp->next)
	{
		if (tmp->value < tmp->next->value)
			break ;
		tmp = tmp->next;
		n++;
	}
	return (n);
}
