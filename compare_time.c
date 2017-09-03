/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 14:36:38 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/01 10:12:14 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		print_year(char *tme, int i)
{
	while (tme[++i])
	{
		if (i == 10)
		{
			ft_putchar(' ');
			i += 9;
		}
		ft_putchar(tme[i]);
	}
}

void		print_month(char *tme, int i)
{
	int		dot;

	dot = 0;
	while (tme[++i])
	{
		if (tme[i] == ':')
			dot++;
		if (tme[i] == ':' && dot == 2)
			break ;
		ft_putchar(tme[i]);
	}
}

int			timecmp(t_dir *file1, t_dir *file2)
{
	if (file1->st.st_mtime > file2->st.st_mtime)
		return (1);
	if (file1->st.st_mtime < file2->st.st_mtime)
		return (2);
	if (file1->st.st_mtime == file2->st.st_mtime)
	{
		if (file1->st.st_mtimespec.tv_nsec > file2->st.st_mtimespec.tv_nsec)
			return (1);
		if (file1->st.st_mtimespec.tv_nsec < file2->st.st_mtimespec.tv_nsec)
			return (2);
		if (file1->st.st_mtimespec.tv_nsec == file2->st.st_mtimespec.tv_nsec)
		{
			if (ft_strcmp(file1->file, file2->file) > 0)
				return (2);
			if (ft_strcmp(file1->file, file2->file) < 0)
				return (1);
		}
	}
	return (0);
}
