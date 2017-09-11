/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 07:54:31 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/11 19:52:34 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		write_space(int len)
{
	char	buff[len];
	int		i;

	i = -1;
	while (++i < len)
		buff[i] = ' ';
	write(1, buff, i);
}

void		update_int_tab(int *j, struct stat st)
{
	struct passwd	*pw;
	struct group	*gr;

	if ((pw = getpwuid(st.st_uid)))
	{
		if (j[3] < (int)ft_strlen(pw->pw_name))
			j[3] = (int)ft_strlen(pw->pw_name);
	}
	else
		j[3] = st.st_uid;
	if ((gr = getgrgid(st.st_gid)))
	{
		if (j[4] < (int)ft_strlen(gr->gr_name))
			j[4] = (int)ft_strlen(gr->gr_name);
	}
	else
		j[4] = st.st_gid;
	if (j[0] < (int)st.st_nlink)
		j[0] = (int)st.st_nlink;
	if (j[1] < (int)st.st_size)
		j[1] = (int)st.st_size;
	if (j[2] < day_len(ctime(&st.st_mtime)))
		j[2] = day_len(ctime(&st.st_mtime));
}

char		file_type(struct stat st)
{
	if (S_ISREG(st.st_mode))
		return ('-');
	if (S_ISDIR(st.st_mode))
		return ('d');
	if (S_ISLNK(st.st_mode))
		return ('l');
	if (S_ISFIFO(st.st_mode))
		return ('m');
	if (S_ISSOCK(st.st_mode))
		return ('s');
	if (S_ISCHR(st.st_mode))
		return ('c');
	return ('-');
}

void		print_rights(struct stat st)
{
	char	buff[12];

	buff[11] = ' ';
	buff[10] = ' ';
	buff[0] = file_type(st);
	buff[1] = (st.st_mode & S_IRUSR) ? 'r' : '-';
	buff[2] = (st.st_mode & S_IWUSR) ? 'w' : '-';
	buff[3] = (st.st_mode & S_IXUSR) ? 'x' : '-';
	buff[4] = (st.st_mode & S_IRGRP) ? 'r' : '-';
	buff[5] = (st.st_mode & S_IWGRP) ? 'w' : '-';
	buff[6] = (st.st_mode & S_IXGRP) ? 'x' : '-';
	buff[7] = (st.st_mode & S_IROTH) ? 'r' : '-';
	buff[8] = (st.st_mode & S_IWOTH) ? 'w' : '-';
	buff[9] = (st.st_mode & S_IXOTH) ? 'x' : '-';
	if (st.st_mode & S_ISVTX)
		buff[9] = (buff[9] == '-' ? 'T' : 't');
	if (st.st_mode & S_ISUID)
		buff[3] = (buff[3] == '-' ? 'S' : 's');
	if (st.st_mode & S_ISGID)
		buff[6] = (buff[6] == '-' ? 'S' : 's');
	write(1, buff, 12);
}

void		pwname(char *pw_name, int sp)
{
	int		i;

	i = (int)ft_strlen(pw_name);
	ft_putstr(pw_name);
	if (sp - i > 0)
		write_space(sp - i);
}
