/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 22:20:19 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/10 22:57:21 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		custom_perror(char *name)
{
	ft_putstr("ls: ");
	perror(name);
}

void		print_lnk(char *path, char *file)
{
	int		len;
	char	*value;
	char	buff[1024];
	char	*str;
	int		i;

	str = full_path(path, file);
	i = -1;
	len = readlink(str, buff, 1024);
	if (!(value = (char*)malloc(sizeof(char) * len)))
		return ;
	readlink(str, value, len);
	ft_putstr(" -> ");
	write(1, value, len);
	free(value);
	free(str);
}

void		ft_strcolor_av(char *file, struct stat st, int flag)
{
	if ((st.st_mode & S_IXUSR) || (st.st_mode & S_IXGRP) ||
			(st.st_mode & S_IXOTH))
	{
		write(1, "\x1b[31m", 5);
		if (S_ISLNK(st.st_mode))
			write(1, "\x1b[35m", 5);
	}
	if (S_ISDIR(st.st_mode))
	{
		write(1, "\x1b[36m", 5);
		if ((st.st_mode & S_IRUSR) && (st.st_mode & S_IWUSR) &&
				(st.st_mode & S_IXUSR) && (st.st_mode & S_IRGRP) &&
				(st.st_mode & S_IWGRP) && (st.st_mode & S_IXGRP) &&
				(st.st_mode & S_IROTH) && (st.st_mode & S_IWOTH) &&
				(st.st_mode & S_IXOTH))
		{
			write(1, "\x1b[43m", 5);
			write(1, "\x1b[30m", 5);
		}
	}
	ft_putstr(file);
	write(1, "\x1b[0m", 5);
	if (S_ISLNK(st.st_mode) && flag & L_FLAG)
		print_lnk("", file);
	ft_putchar('\n');
}

void		ft_strcolor(t_dir *dir, t_ls *ls)
{
	if ((dir->st.st_mode & S_IXUSR) || (dir->st.st_mode & S_IXGRP) ||
			(dir->st.st_mode & S_IXOTH))
	{
		write(1, "\x1b[31m", 5);
		if (S_ISLNK(dir->st.st_mode))
			write(1, "\x1b[35m", 5);
	}
	if (S_ISDIR(dir->st.st_mode))
	{
		write(1, "\x1b[36m", 5);
		if ((dir->st.st_mode & S_IRUSR) && (dir->st.st_mode & S_IWUSR) &&
				(dir->st.st_mode & S_IXUSR) && (dir->st.st_mode & S_IRGRP) &&
				(dir->st.st_mode & S_IWGRP) && (dir->st.st_mode & S_IXGRP) &&
				(dir->st.st_mode & S_IROTH) && (dir->st.st_mode & S_IWOTH) &&
				(dir->st.st_mode & S_IXOTH))
		{
			write(1, "\x1b[43m", 5);
			write(1, "\x1b[30m", 5);
		}
	}
	ft_putstr(dir->file);
	write(1, "\x1b[0m", 5);
	if (S_ISLNK(dir->st.st_mode) && ls->flag & L_FLAG)
		print_lnk(ls->path, dir->file);
	ft_putchar('\n');
}
