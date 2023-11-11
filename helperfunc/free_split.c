/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 02:13:57 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/22 20:29:12 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunc.h"

void	free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	while (i >= 0 && args[i] != 0)
		free(args[i--]);
	free(args);
}
