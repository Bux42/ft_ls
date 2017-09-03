/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 03:58:01 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/03 21:15:56 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		reset_int_tab(int *j)
{
	j[0] = 0;
	j[1] = 0;
	j[2] = 0;
	j[3] = 0;
	j[4] = 0;
}

int			*count_spaces_av(char **av)
{
	int				*j;
	int				i;
	struct stat		st;

	i = -1;
	if (!(j = (int*)malloc(sizeof(int) * 5)))
		return (NULL);
	while (av[++i])
		if ((lstat(av[i], &st)) > -1)
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
	ft_putstr(dir);
	ft_putstr(":\n");
}

void		print_av_dir(char **av, int flag)
{
	struct stat	st;
	t_ls		*ls;
	int			i;

	i = -1;
	ls = malloc(sizeof(t_ls));
	while (av[++i])
	{
		if ((lstat(av[i], &st)) > -1)
		{
			if (S_ISDIR(st.st_mode))
			{
				if (av[1])
					print_dir_name(av[i]);
				ls->dir = NULL;
				ls->flag = flag;
				ls->path = av_path(av[i]);
				fill_list(ls);
				print_list(ls);
			}
		}
	}
}
