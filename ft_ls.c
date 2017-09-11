/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 05:20:03 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/11 17:47:12 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		free_list(t_dir *list)
{
	if (list)
	{
		free_list(list->next);
		free(list->file);
		free(list);
	}
}

int			main(int ac, char **av)
{
	t_ls	ls;
	int		ret;

	if (ac && (ret = get_flags(av, &ls)) != -1)
	{
		ls.dir = NULL;
		ls.path = ft_strdup("./");
		if (ret == 0 || !av[0])
		{
			fill_list(&ls);
			print_list(&ls);
		}
		else
		{
			sort_av(av, ls.flag);
			print_av(av, ls.flag);
		}
	}
	return (0);
}
