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
void	magic_sort_3(t_list **stack_a);
void	execute_sort(t_list **stack_a, t_list **stack_b);
void	sort_bigstacks(t_list **stack_a, t_list **stack_b);
void	situation_two(t_list **stack_a, t_list **stack_b, int bottom_b_value);
void	situation_three(t_list **stack_a, t_list **stack_b, int bottom_b_value,
			int bottom_a_value);
void	situation_three_type_a(t_list **stack_a, t_list **stack_b,
			int bottom_b_value);
void	situation_three_type_b(t_list **stack_a, t_list **stack_b,
			int bottom_a_value, int bottom_b_value);
int		add_stacka_typea(t_list **stack_a, t_list **stack_b, int median);
int		add_stacka_typeb(t_list **stack_a, t_list **stack_b, int back_pos,
			int median);
int		quit_thesort_typea(t_list **stack_a, t_list **stack_b, int median);
int		quit_thesort_typeb(t_list **stack_a, t_list **stack_b, int median);
void	finish_the_sort(t_list **stack_a, t_list **stack_b);

#endif