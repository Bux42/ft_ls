/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_av.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 02:29:35 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/03 21:18:32 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		sort_av(char **av, int flag)
{
	int		i;

	i = -1;
	while (av[++i] && av[i + 1])
	{
		if (flag & T_FLAG)
		{
			if (must_swap(av[i], av[i + 1]))
				swap_av(&av, &i);
		}
		else
		{
			if (ft_strcmp(av[i], av[i + 1]) > 0)
				swap_av(&av, &i);
		}
	}
	if (flag & R_LOW)
		reverse_av(&av);
}

void		swap_av(char ***av, int *i)
{
	char		*tmp;
	int			j;
	char		**ave;

	j = *i;
	ave = *av;
	tmp = ave[j];
	ave[j] = ave[j + 1];
	ave[j + 1] = tmp;
	*i = -1;
	*av = ave;
}

void		reverse_av(char ***avc)
{
	int		i;
	int		j;
	char	*tmp;
	char	**av;

	av = *avc;
	i = 0;
	j = 0;
	if (av[1])
	{
		while (av[i + 1])
			i++;
		while (j < i)
		{
			tmp = av[j];
			av[j] = av[i - j];
			av[i - j] = tmp;
			j++;
			if (j > i / 2)
				break ;
		}
	}
	*avc = av;
}

int			must_swap(char *file1, char *file2)
{
	struct stat	st1;
	struct stat	st2;

	if ((lstat(file1, &st1)) == -1)
		custom_perror(file1);
	if ((lstat(file2, &st2)) > -1)
	{
		if (st2.st_mtime > st1.st_mtime)
			return (1);
		if (st2.st_mtime == st1.st_mtime)
		{
			if (st2.st_mtimespec.tv_nsec == st1.st_mtimespec.tv_nsec)
			{
				if ((ft_strcmp(file1, file2)) > 0)
					return (1);
				return (0);
			}
			else if (st2.st_mtimespec.tv_nsec > st1.st_mtimespec.tv_nsec)
				return (1);
		}
	}
	else
		custom_perror(file2);
	return (0);
}
