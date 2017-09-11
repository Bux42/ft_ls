/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 14:36:38 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/10 23:28:32 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int			timecmpr(t_dir *file1, t_dir *file2)
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
