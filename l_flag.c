/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 07:54:31 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/04 16:13:16 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		update_int_tab(int *j, struct stat st)
{
	struct passwd	*pw;
	struct group	*gr;

	if ((pw = getpwuid(st.st_uid)))
		if (j[3] < (int)ft_strlen(pw->pw_name))
			j[3] = (int)ft_strlen(pw->pw_name);
	if ((gr = getgrgid(st.st_gid)))
		if (j[4] < (int)ft_strlen(gr->gr_name))
			j[4] = (int)ft_strlen(gr->gr_name);
	if (j[0] < (int)st.st_nlink)
		j[0] = (int)st.st_nlink;
	if (j[1] < (int)st.st_size)
		j[1] = (int)st.st_size;
	if (j[2] < day_len(ctime(&st.st_mtime)))
		j[2] = day_len(ctime(&st.st_mtime));
}

void		print_rights(struct stat st)
{
	ft_putstr((S_ISDIR(st.st_mode)) ? "d" : "");
	ft_putstr((S_ISREG(st.st_mode)) ? "-" : "");
	ft_putstr((S_ISLNK(st.st_mode)) ? "l" : "");
	ft_putstr((S_ISFIFO(st.st_mode)) ? "m" : "");
	ft_putstr((S_ISCHR(st.st_mode)) ? "c" : "");
	ft_putstr((S_ISBLK(st.st_mode)) ? "b" : "");
	ft_putstr((S_ISSOCK(st.st_mode)) ? "s" : "");
	ft_putstr((st.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((st.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((st.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((st.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((st.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((st.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((st.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((st.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((st.st_mode & S_IXOTH) ? "x" : "-");
	ft_putstr("  ");
}

void		pwname(char *pw_name, int sp)
{
	int		i;

	i = (int)ft_strlen(pw_name);
	ft_putstr(pw_name);
	while (i++ < sp)
		ft_putchar(' ');
}
