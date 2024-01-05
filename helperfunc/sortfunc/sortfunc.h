/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfunc.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:52:02 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/22 20:30:37 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTFUNC_H
# define SORTFUNC_H

# include "../../push_swap.h"
# include "../helperfunc.h"
# include "../libft/libft.h"

int		find_max_node(t_list *stacks);
int		find_min_node(t_list *stacks);
int		find_median(t_list **stack_b);
void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	execute_sort(t_list **stack_a, t_list **stack_b);
void	bigstacks_sort(t_list **stack_a, t_list **stack_b);
void	magic_sort_3(t_list **stack_a);
void	magic_sort_5(t_list **stack_a, t_list **stack_b);
void	finish_bigstacks_sort(t_list **stack_a, t_list **stack_b, int **flag);
void	set_stacksb(t_list **stack_a, t_list **stack_b, int **flag,
			int stop_pos);
int		allocate_array_memory(int **array, int size);
int		allocate_flag_memory(int ***flag);
void	delete_memory(int **flag, int *array);
int		find_stack_pos(t_list **stack_a, int **flag, int flag_n);

#endif