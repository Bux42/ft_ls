/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 03:58:01 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/11 17:08:54 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			*count_spaces_av(char **av)
{
	int				*j;
	int				i;
	struct stat		st;

	i = -1;
	if (!(j = (int*)malloc(sizeof(int) * 5)))
		return (NULL);
	j[0] = 0;
	j[1] = 0;
	j[2] = 0;
	j[3] = 0;
	j[4] = 0;
	while (av[++i])
		if ((lstat(av[i], &st)) > -1)
			if (!S_ISDIR(st.st_mode))
				update_int_tab(j, st);
	return (j);
}

void		print_av(char **av, int flag)
{
	int			i;
	struct stat	st;
	int			*j;

	i = -1;
	if (flag & L_FLAG)
		j = count_spaces_av(av);
	while (av[++i])
	{
		if ((lstat(av[i], &st)) > -1)
		{
			if ((!S_ISDIR(st.st_mode)))
			{
				if (flag & L_FLAG)
					l_flag(st, j);
				flag = flag | DIR_NAME;
				ft_strcolor_av(av[i], st, flag);
			}
		}
		else
			custom_perror(av[i]);
	}
	if (flag & L_FLAG)
		free(j);
	print_av_dir(av, flag);
}

void		print_dir_name(char *dir)
{
	ft_putchar('\n');
	write(1, dir, ft_strlen(dir) - 1);
	ft_putstr(":\n");
}

void		print_av_dir(char **av, int flag)
{
	struct stat	st;
	t_ls		*ls;
	int			i;

	i = -1;
	if (!(ls = (t_ls*)malloc(sizeof(t_ls))))
		return ;
	while (av[++i])
	{
		if ((lstat(av[i], &st)) > -1)
		{
			if (S_ISDIR(st.st_mode))
			{
				ls->dir = NULL;
				ls->flag = flag;
				ls->path = av_path(av[i]);
				flag & DIR_NAME ? print_dir_name(ls->path) : 0;
				fill_list(ls);
				print_list(ls);
			}
		}
	}
	free(ls);
}
