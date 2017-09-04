/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 05:20:37 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/04 14:11:57 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H

# include "libft/libft.h"

# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>

# define L_FLAG 1
# define T_FLAG 2
# define A_FLAG 4
# define R_UP 8
# define R_LOW 16

typedef struct		s_dir
{
	char			*file;
	struct stat		st;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_ls
{
	int				flag;
	int				files;
	int				folders;
	int				i;
	int				j;
	int				total;
	char			*path;
	t_dir			*dir;
}					t_ls;

void				print_list(t_ls *ls);
void				print_list_dir(t_ls *ls, t_dir *start);
void				free_list(t_dir *list);
int					valid_dir(char *path);
int					*count_spaces(t_ls *ls);
void				update_int_tab(int *j, struct stat st);
int					day_len(char *time);
void				l_flag(struct stat st, int *j);
void				pwname(char *pw_name, int sp);
void				print_rights(struct stat st);
void				print_space(int i, int j);
void				print_time(struct stat st);
void				print_year(char *tme, int i);
void				print_month(char *tme, int i);

int					get_flags(char **av, t_ls *ls);
int					check_flag(int i, int flag);
void				shift_av(char **av, int *i);

void				fill_list(t_ls *ls);
void				insert_name(t_dir *dir, t_ls *ls);
void				insert_rname(t_dir *dir, t_ls *ls);
void				insert_time(t_dir *dir, t_ls *ls);
void				insert_rtime(t_dir *dir, t_ls *ls);
t_dir				*create(t_ls *ls, char *name);
void				add_dir(t_ls *ls, char *name);
int					timecmp(t_dir *file1, t_dir *file2);

void				put_begining(t_dir **dir, t_dir **ls, t_dir **cp);
void				put_end(t_dir **cp, t_dir **dir);
void				put_between(t_dir **tmp, t_dir **dir, t_dir **cp);
void				next_node(t_dir **tmp, t_dir **cp);

void				ft_strcolor(t_dir *dir, t_ls *ls);
void				print_lnk(char *path, char *file);
void				total(int i);

char				*full_path(char *path, char *file);
void				custom_perror(char *name);

void				sort_av(char **av, int flag);
void				print_av(char **av, int flag);
void				print_av_dir(char **av, int flag);
void				print_dir_name(char *dir);
void				ft_strcolor_av(char *file, struct stat st, int flag);
void				swap_av(char ***av, int *i);
int					must_swap(char *str1, char *str2);
void				reverse_av(char ***av);
void				reset_int_tab(int *j);
char				*av_path(char *file);

#endif
