/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:38:37 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/24 22:50:47 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../../push_swap.h"
# include "../helperfunc.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *s);
long			ft_atoi(const char *str);
int			ft_isnum(const char *str);
const char	*ft_strchr(const char *str, int c);
void		*ft_memcpy(void *restrict dest, const void *restrict src, size_t n);
char		**ft_split(char const *str, char c);
int			ft_strcmp(const char *str1, const char *str2);
void		ft_putendl_fd(char *s, int fd);

#endif