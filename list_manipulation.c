/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 19:52:03 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/03 20:56:36 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		put_begining(t_dir **dir, t_dir **ls, t_dir **cp)
{
	(*dir)->next = (*cp);
	(*ls) = (*dir);
}

void		put_end(t_dir **cp, t_dir **dir)
{
	(*cp)->next = (*dir);
}

void		put_between(t_dir **tmp, t_dir **dir, t_dir **cp)
{
	(*tmp)->next = (*dir);
	(*dir)->next = (*cp);
}

void		next_node(t_dir **tmp, t_dir **cp)
{
	(*tmp) = (*cp);
	(*cp) = (*cp)->next;
}
