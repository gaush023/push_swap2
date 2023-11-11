/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:30:42 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/24 23:07:47 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunc.h"

static int	ft_check_duplication(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	check_maximamu(long tmp, char **args, int i)
{
	int j;

	j = 0;
	while (args[i][j])
			j++;
	if(tmp < 0 || args[i][0] == '+')
	{
		if (j > 11)
			return (1);
	}
	else
	{
		if (j > 10)
			return (1);
	}		
	if (tmp > INT_MAX || tmp < INT_MIN)
		return (1);
	return (0);
}

static int	ft_help_check_argc(long tmp, char **args, int i)
{
	if (!ft_isnum(args[i]))
		return (-1);
	if (ft_check_duplication(tmp, args, i))
		return (-1);
	if (check_maximamu(tmp, args, i))
		return (-1);
	return (0);
}

int	ft_check_argc(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (argc < 2)
		return (-1);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (ft_help_check_argc(tmp, args, i) == -1)
			return (-1);
		i++;
	}
	if (argc == 2)
		free_split(args);
	return (0);
}

//  int main(int argc, char **argv)
//  {
// 	 printf("%d\n", ft_check_argc(argc, argv));
//  }