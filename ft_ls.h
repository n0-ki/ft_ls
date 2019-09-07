/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:03:52 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/07 12:41:26 by nolakim          ###   ########.fr       */
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
	int				flgcnt;
}					t_data;

t_file				*storestuff(char **av, t_data *ls, int x);
void				storecnt(t_data *ls, char **av, int x, int ac);
t_file				*storechildren(t_file *file, char *av, t_flags *flags);
void				storeflags(t_data *ls, char *av);
void	    		ls_sort(t_file **file, t_flags *f);
t_file				*initfile(void);
t_flags				*initflags(void);
void				getps(t_file **h);

#endif