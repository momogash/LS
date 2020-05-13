#include "ft_ls2.h"

int read_bytes(char *str)
{
  int     i;
  DIR     *folder;
  struct dirent *files;

  i = 0;
  folder = opendir(str); //directory name to be opened will be specified in this string
  if (!folder)
    return(1);
  while ((files = readdir(folder))!= NULL)
    i++;
  if(folder)
    closedir(folder);
  return  (i); //number of bytes read in the current folder
}