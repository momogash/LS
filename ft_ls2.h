#ifndef FT_LS_H
# define FT_LS_H


#include "libft/libft.h"
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <time.h>
#include <errno.h>


typedef struct		my_flags
{
	char			a;
	char			l;
	char			t;
	char			R;
	char			r;
	char			err;
	char			active;
}					flags; //could have created any array since they all of the same data type.

flags				*process_flag(void);
char				**read_flag_input(char **str, int count);
void				ft_sortit(char **str);
void				arrange(char **str);
void				chosen_flag(flags *flag, char *str);
void				skip_first_param(char **str, flags *flag);
int					choose_flag(char *argv[], flags *flag);
int					array_length(char **str);
void				file_info(char **newstr, char *str);

char				**folder(char **newstr, flags *flag, char **str);
int					read_bytes(char *str);
void				open_read_folder(char **newstr, flags *flag, char **str);
void				open_read_folder_flag(char **newstr, flags *flag, char **str);
char				**sort_by_time(char **newstr, char *str);
void				struct_sort(char *str, char **newstr, int i, int j); 
char				*filepath(char *folder, char *str);
int					usr_details(char *newstr, char *str);

char				**reverse_order(char **newstr);
void				delete(char **str);
blkcnt_t		file_content_count(char **newstr);
void				no_flag(char **str, flags *flag);

#endif