/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:40:12 by obamzuro          #+#    #+#             */
/*   Updated: 2018/05/02 22:45:40 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	reset_params(void)
{
	int		i;

	i = 0;
	while (i < 256)
	{
		g_params[i] = 0;
		++i;
	}
}

static void	check_params(char param)
{
	int		i;

	i = 0;
	while (i < AM_PARAMS)
	{
		if (param == PARAMS[i])
			return ;
		++i;
	}
	ft_printf("%s: illegal option -- %c\nusage: %s [-%s] [file ...]\n",
			g_nameapp, param, g_nameapp, PARAMS);
	exit(EXIT_FAILURE);
}

int			fill_params(int argc, char **argv)
{
	int		i;
	char	*temp;

	i = 1;
	reset_params();
	while (i < argc)
	{
		if (argv[i][0] != '-' || (argv[i][0] == '-' &&
				argv[i][1] == '-' && argv[i][2] == 0))
			return (i);
		temp = argv[i] + 1;
		while (*temp)
		{
			check_params(*temp);
			g_params[*temp++] = 1;
		}
		++i;
	}
	return (i);
}