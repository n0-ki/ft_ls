/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:03:52 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/16 11:26:48 by nolakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H


# include "libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <sys/ioctl.h>
# include <stdio.h>

# define FILE 		ls->file
# define SEC		stat.st_mtimespec.tv_sec
# define NSEC		stat.st_mtimespec.tv_nsec
# define SECSHORT	f->r == 1 ? ft_longcmp(b->SEC, a->SEC) : ft_longcmp(a->SEC, b->SEC)
# define NANOSHORT	f->r == 1 ? ft_longcmp(b->NSEC, a->NSEC) : ft_longcmp(a->NSEC, b->NSEC)

enum				{ERRNO, USAGE, MALL_ERR};

typedef struct		s_flags
{
	int				l;
	int				cr;
	int				a;
	int				r;
	int				t;
}					t_flags;

typedef struct 		s_file
{
    char			*name;
	char			*path;
	struct s_file 	*child;
	struct stat		stat;
	struct s_file 	*next;
}					t_file;

typedef struct		s_data
{
	char			*wflags;
	t_flags			*flags;
	t_file			*file;
	int				dcnt;
	int				flg;
}					t_data;

t_file				*initfile(void);
t_flags				*initflags(void);
t_file				*storestuff(char **av, t_data *ls, int x);
void				storecnt(t_data *ls, char **av, int x, int ac);
t_file				*storechildren(t_file *file, char *dirname, t_flags *flags);
void				storeflags(t_data *ls, char *av);
void				getps(t_file *h, t_data *ls);
void	    		ls_sort(t_file **file, t_flags *f);
void				lsl(t_file  *h);
void				printperms(struct stat *filestats);
int					blockcount(t_file *file);
void				printspecial(struct stat stat);
t_file				*recursivestore(t_file *f, t_data *ls);
char				*ls_get_path(char *dir, char *file);
int					ls_error(char *s, int error);
void				ls_free_files(t_file *t_file, t_data *ls);
int					is_ls_hidden(char *s);
#endif