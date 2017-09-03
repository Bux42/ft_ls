/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 05:28:01 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/01 08:13:23 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			check_flag(int i, int flag)
{
	if (i == 'a')
		return (flag | A_FLAG);
	if (i == 'l')
		return (flag | L_FLAG);
	if (i == 'r')
		return (flag | R_LOW);
	if (i == 'R')
		return (flag | R_UP);
	if (i == 't')
		return (flag | T_FLAG);
	if (i == '1')
		return (flag);
	ft_putstr("ls: illegal option --");
	ft_putchar(i);
	ft_putchar('\n');
	ft_putendl("usage: ls [-latrR] [file ...]");
	return (-1);
}

void		shift_av(char **av, int *i)
{
	int		cp;

	cp = *i;
	if (av[cp + 1])
	{
		while (av[cp + 1])
		{
			av[cp] = ft_strdup(av[cp + 1]);
			cp++;
		}
	}
	else
		av[cp] = NULL;
	av[cp] = NULL;
}

int			get_flags(char **av, t_ls *ls)
{
	ls->i = 0;
	ls->files = 0;
	ls->j = 0;
	while (av[++ls->i])
	{
		if (av[ls->i][0] != '-')
			ls->files++;
		if (av[ls->i][0] == '-' && av[ls->i][1] == '-')
		{
			shift_av(av, &ls->i);
			ls->files++;
		}
		else if (av[ls->i][0] == '-' && ls->files == 0)
		{
			ls->j = 0;
			while (av[ls->i][++ls->j])
				if ((ls->flag = check_flag(av[ls->i][ls->j], ls->flag)) == -1)
					return (-1);
			shift_av(av, &ls->i);
			ls->i--;
		}
	}
	ls->i = 0;
	shift_av(av, &ls->i);
	return (ls->files);
}
