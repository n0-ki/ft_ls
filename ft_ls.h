/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolakim <nolakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:03:52 by nolakim           #+#    #+#             */
/*   Updated: 2019/09/02 08:23:12 by nolakim          ###   ########.fr       */
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
# include <stdbool.h>

# define FILE ls->file

typedef struct	s_flags
{
	bool		l;
	//cr: capital R.
	bool		cr;
	bool		a;
	bool		r;
	bool		t;
}				t_flags;

typedef struct s_file
{
    char		*name;
	//file inside of dir, will be set to null if no file inside of a dir. 
	struct s_file *child;
	//linked list inside linked list for recusive purposes
	struct s_file *next;
}				t_file;

typedef struct	s_data
{
	int			dcnt;
	char		*wflags;
	t_flags		*flags;
	t_file		*file;
}				t_data;
t_file		*storestuff(char **av, t_data *ls, int x);
t_file		*storechildren(t_file *file, char *av, t_flags *flags);
void	    ls_sort(t_file **file, t_flags *f);
t_file		*initfile(void);

#endif