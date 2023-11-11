/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:39:11 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/22 20:29:19 by sagemura         ###   ########.fr       */
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


// t_list *create_node(int value)
// {
// 	t_list *new_node = (t_list *)malloc(sizeof(t_list));
// 	if (!new_node)
// 		return NULL;
// 	new_node->value = value;
// 	new_node->index = -1; //
// 	new_node->next = NULL;
// 	return new_node;
// }

// void add_node(t_list **head, t_list *new_node)
// {
// 	if (!head || !new_node)
// 		return;
// 	new_node->next = *head;
// 	*head = new_node;
// }

// int main(void)
// {
// 	t_list *stack = NULL;

// 	add_node(&stack, create_node(3));
// 	add_node(&stack, create_node(1));
// 	add_node(&stack, create_node(2));

// 	ft_set_head_node(&stack);

// 	t_list *current = stack;
// 	while (current)
// 	{
// 		printf("Value: %d, Index: %d\n", current->value, current->index);
// 		current = current->next;
// 	}

// 	while (stack)
// 	{
// 		t_list *tmp = stack;
// 		stack = stack->next;
// 		free(tmp);
// 	}

// 	return 0;
// }