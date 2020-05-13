#include "ft_ls2.h"

void  swap_str(char **newstr, int a, int b)
{
  char *temp;

  temp = ft_strdup(newstr[a]);
  ft_strdel(&newstr[a]);
  newstr[a] = ft_strdup(newstr[b]);
  ft_strdel(&newstr[b]);
  newstr[b] = ft_strdup(temp);
}

void  struct_sort(char *str, char **newstr, int i, int j)
{
  //declare variables to of type stuct stat to use to access member structures of stat
  struct stat a;
  struct stat b;
 

  char   *temp;

  stat((temp = filepath(newstr[i], str)), &a); 
  //accessing the stat struct
  ft_strdel(&temp);
  stat((temp = filepath(newstr[j], str)), &b);
  ft_strdel(&temp);
  // sort by last time modified in seconds: st_mtime; time of last modification by whole seconds instead of nsec(nano seconds)

  // if the time of modification in seconds returned from stat(filepath, a) of a is less than that of b then swap str[i] with str[j]
  if (a.st_mtimespec.tv_sec < b.st_mtimespec.tv_sec)
  {
    swap_str(newstr, i, j);/* code */
  }

  // if the time of modification in seconds returned from stat(filepath, a) of a is equal to stat(filepath, b) of b
  if (a.st_mtimespec.tv_sec == b.st_mtimespec.tv_sec)
  {
    //&& if time modified from a is less in nano seconds then swap
    if (a.st_mtimespec.tv_nsec < b.st_mtimespec.tv_nsec)
      swap_str(newstr, i, j);
      //if equal in nano seconds then str compare str[i] && str[j] are less than zero meaning not the same then swap
    if (a.st_mtimespec.tv_nsec == b.st_mtimespec.tv_nsec)
    {
      if (ft_strcmp(newstr[i], newstr[j]) < 0)
      {
        swap_str(newstr, i, j);
      }
    }

  }
  
}