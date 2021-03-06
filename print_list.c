/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 07:17:01 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/10 19:39:06 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*full_path_rec(char *path, char *file)
{
	char	*ret;
	int		len;

	len = ft_strlen(path) + ft_strlen(file) + 2;
	if (!(ret = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	ft_strcpy(ret, path);
	ft_strcat(ret, file);
	ft_strcat(ret, "/");
	return (ret);
}

void		print_list(t_ls *ls)
{
	int		*j;
	t_dir	*start;

	start = ls->dir;
	if (ls->flag & L_FLAG)
		if ((j = count_spaces(ls)) == NULL)
			return ;
	while (ls->dir)
	{
		if (ls->flag & L_FLAG)
			l_flag(ls->dir->st, j);
		ft_strcolor(ls->dir, ls);
		ls->dir = ls->dir->next;
		ls->flag = ls->flag | DIR_NAME;
	}
	if (ls->flag & L_FLAG)
		free(j);
	ls->dir = start;
	print_list_dir(ls, start);
	free(ls->path);
}

void		print_list_dir(t_ls *ls, t_dir *start)
{
	t_ls	ls2;
	t_dir	*tmp;

	if (!(ls->flag & R_UP))
		free_list(start);
	while (start && ls->flag & R_UP)
	{
		if (S_ISDIR(start->st.st_mode))
		{
			if (valid_dir(start->file))
			{
				ls2.dir = NULL;
				ls2.flag = ls->flag;
				ls2.path = full_path_rec(ls->path, start->file);
				if (ls->flag & DIR_NAME)
					print_dir_name(ls2.path);
				fill_list(&ls2);
				print_list(&ls2);
			}
		}
		tmp = start;
		start = start->next;
		free(tmp->file);
		free(tmp);
	}
}
