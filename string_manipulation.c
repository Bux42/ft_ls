/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:53:29 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/03 18:57:15 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		total(int i)
{
	ft_putstr("total ");
	ft_putnbr(i);
	ft_putchar('\n');
}

int			valid_dir(char *path)
{
	if (path[0] == '.')
	{
		if (path[1] == '\0')
			return (0);
		if (path[1] == '.')
			if (path[2] == '\0')
				return (0);
	}
	return (1);
}

char		*full_path(char *path, char *file)
{
	char	*ret;
	int		len;

	len = ft_strlen(path) + ft_strlen(file) + 1;
	if (!(ret = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	ft_strcpy(ret, path);
	ft_strcat(ret, file);
	return (ret);
}

char		*av_path(char *file)
{
	char	*path;
	int		i;
	int		j;
	int		slash;

	j = 0;
	slash = 0;
	i = ft_strlen(file);
	if (file[i - 1] != '/')
	{
		i++;
		slash++;
	}
	if (!(path = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	if (slash)
		path[i - 1] = '/';
	path[i] = '\0';
	while (j < i - slash)
	{
		path[j] = file[j];
		j++;
	}
	return (path);
}
