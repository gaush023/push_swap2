/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:03:03 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/03 20:10:42 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERFUNC_H
# define HELPERFUNC_H

# include "../list.h"
# include "../push_swap.h"
# include "libft/libft.h"
# include <limits.h>

int		ft_check_argc(int argc, char **argv);
int		ft_print_actions(int n);
int		ft_print_error(void);
void	ft_set_head_node(t_list **stack);
t_list	*ft_lstnew(int value);
void	ft_lstadd_back(t_list **stack, t_list *new);
int		is_sorted(t_list **stack);
t_list	*mv_last(t_list *head);
void	free_stack(t_list **stack);
void	free_split(char **args);
int		ft_lstsize(t_list **stack);
int		front_size(t_list **stack_b);
int		back_size(t_list **stack_b);

#endif
