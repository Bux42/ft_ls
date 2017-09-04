/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 07:28:03 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/04 16:15:29 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		print_time(struct stat st)
{
	char	*tme;
	int		i;
	int		year;

	i = 0;
	year = 0;
	if (st.st_mtime - time(NULL) < -15721200)
		year = 1;
	tme = ctime(&st.st_mtime);
	tme[ft_strlen(tme) - 1] = '\0';
	while (tme[i + 1] != ' ')
		i++;
	if (year)
		print_year(tme, i);
	else
		print_month(tme, i);
	ft_putchar(' ');
}

void		l_flag(struct stat st, int *j)
{
	struct passwd	*pw;
	struct group	*gr;
	int				i;

	print_rights(st);
	print_space(st.st_nlink, j[0]);
	ft_putnbr(st.st_nlink);
	ft_putchar(' ');
	if ((pw = getpwuid(st.st_uid)))
		pwname(pw->pw_name, j[3]);
	else
		ft_putnbr(st.st_uid);
	gr = getgrgid(st.st_gid);
	i = ft_strlen(gr->gr_name);
	ft_putstr("  ");
	ft_putstr(gr->gr_name);
	while (i++ < j[4])
		ft_putchar(' ');
	ft_putstr("  ");
	print_space(st.st_size, j[1]);
	ft_putnbr(st.st_size);
	print_time(st);
}

void		print_space(int i, int j)
{
	int		diff1;
	int		diff2;

	diff1 = 0;
	diff2 = 0;
	while (i > 9)
	{
		diff1++;
		i /= 10;
	}
	while (j > 9)
	{
		diff2++;
		j /= 10;
	}
	while (diff1 < diff2)
	{
		diff1++;
		ft_putchar(' ');
	}
}

int			day_len(char *time)
{
	int		i;

	i = 0;
	time[ft_strlen(time) - 1] = '\0';
	while (time[i])
	{
		if (time[i] > 47 && time[i] < 58)
		{
			if (time[i + 1] == ' ')
				return (1);
			else
				return (2);
		}
		i++;
	}
	return (1);
}

int			*count_spaces(t_ls *ls)
{
	t_dir			*tmp;
	int				*j;

	tmp = ls->dir;
	if (!(j = (int*)malloc(sizeof(int) * 5)))
		return (NULL);
	j[0] = 0;
	j[1] = 0;
	j[2] = 0;
	j[3] = 0;
	j[4] = 0;
	while (tmp)
	{
		update_int_tab(j, tmp->st);
		tmp = tmp->next;
	}
	return (j);
}
