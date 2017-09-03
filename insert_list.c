/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 22:38:19 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/03 20:57:34 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		insert_name(t_dir *dir, t_ls *ls)
{
	t_dir	*cp;
	t_dir	*tmp;

	cp = ls->dir;
	tmp = NULL;
	while (cp)
	{
		if (ft_strcmp(dir->file, cp->file) > 0)
		{
			if (!cp->next)
				return ((void)put_end(&cp, &dir));
			else
				next_node(&tmp, &cp);
		}
		else
		{
			if (!tmp)
				put_begining(&dir, &ls->dir, &cp);
			else
				put_between(&tmp, &dir, &cp);
			return ;
		}
	}
}

void		insert_rname(t_dir *dir, t_ls *ls)
{
	t_dir	*cp;
	t_dir	*tmp;

	cp = ls->dir;
	tmp = NULL;
	while (cp)
	{
		if (ft_strcmp(cp->file, dir->file) > 0)
		{
			if (!cp->next)
				return ((void)put_end(&cp, &dir));
			else
				next_node(&tmp, &cp);
		}
		else
		{
			if (tmp)
				put_between(&tmp, &dir, &cp);
			else
				put_begining(&dir, &ls->dir, &cp);
			return ;
		}
	}
}

void		insert_rtime(t_dir *dir, t_ls *ls)
{
	t_dir	*cp;
	t_dir	*tmp;

	cp = ls->dir;
	tmp = NULL;
	while (cp)
	{
		if (timecmp(dir, cp) == 1)
		{
			if (!cp->next)
				return ((void)put_end(&cp, &dir));
			next_node(&tmp, &cp);
		}
		if (timecmp(dir, cp) == 2)
		{
			if (!tmp)
				put_begining(&dir, &ls->dir, &cp);
			else
				put_between(&tmp, &dir, &cp);
			return ;
		}
	}
}

void		insert_time(t_dir *dir, t_ls *ls)
{
	t_dir	*cp;
	t_dir	*tmp;

	cp = ls->dir;
	tmp = NULL;
	while (cp)
	{
		if (timecmp(dir, cp) == 2)
		{
			if (!cp->next)
				return ((void)put_end(&cp, &dir));
			next_node(&tmp, &cp);
		}
		if (timecmp(dir, cp) == 1)
		{
			if (!tmp)
				put_begining(&dir, &ls->dir, &cp);
			else
				put_between(&tmp, &dir, &cp);
			return ;
		}
	}
}
