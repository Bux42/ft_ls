/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 05:20:03 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/03 19:23:01 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			main(int ac, char **av)
{
	t_ls	ls;
	int		ret;

	if (ac && (ret = get_flags(av, &ls)) != -1)
	{
		ls.dir = (t_dir*)malloc(sizeof(t_dir));
		ls.dir = NULL;
		ls.path = ft_strdup("./");
		if (ret == 0)
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
