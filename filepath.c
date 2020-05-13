#include "ft_ls2.h"

char  *filepath(char *newstr, char *str)
{
  
  char *path;
  char *filename;

  
  path = NULL;
  filename = NULL;

  filename = ft_strjoin(str, "/"); //"./" OR LS/
  path = ft_strjoin(filename, newstr); //"./ft_ls" OR LS/ft_ls
  ft_strdel(&filename);
  return(path);
}