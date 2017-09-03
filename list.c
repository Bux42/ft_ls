/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 06:02:11 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/03 21:25:05 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dir		*create(t_ls *ls, char *name)
{
	t_dir		*dir;
	struct stat	st;
	char		*tmp;

	dir = NULL;
	if (!(dir = (t_dir*)malloc(sizeof(t_dir))))
		return (NULL);
	dir->file = ft_strdup(name);
	dir->next = NULL;
	tmp = full_path(ls->path, name);
	if ((lstat(tmp, &st)) > -1)
		dir->st = st;
	else
	{
		custom_perror(tmp);
		return (NULL);
	}
	ls->total += st.st_blocks;
	free(tmp);
	return (dir);
}

void		add_dir(t_ls *ls, char *name)
{
	t_dir	*dir;

	if (ls->dir == NULL)
	{
		if (!(ls->dir = create(ls, name)))
			return ;
	}
	else
	{
		if (!(dir = create(ls, name)))
			return ;
		if (ls->flag & T_FLAG)
			ls->flag & R_LOW ? insert_rtime(dir, ls) : insert_time(dir, ls);
		else
			ls->flag & R_LOW ? insert_rname(dir, ls) : insert_name(dir, ls);
	}
}

void		fill_list(t_ls *ls)
{
	DIR				*od;
	struct dirent	*fl;

	if (ls->flag & L_FLAG)
		ls->total = 0;
	if ((od = opendir(ls->path)))
	{
		while ((fl = readdir(od)))
		{
			if (fl->d_name[0] == '.')
			{
				if (ls->flag & A_FLAG)
					add_dir(ls, fl->d_name);
			}
			else
				add_dir(ls, fl->d_name);
		}
		closedir(od);
	}
	else
		custom_perror(ls->path);
	if (ls->dir && ls->flag & L_FLAG)
		total(ls->total);
}
