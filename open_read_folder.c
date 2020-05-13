#include "ft_ls2.h"

void  open_read_folder(char **newstr, flags *flag, char **str)
{
  //received a pointer to opened directory

  int     i;
  int     j;
  struct dirent *file;
  DIR     *dir;

  i = 0;
  j = 0;
  dir = opendir(*str);

  //while there is an opened directory(dir) continue to read as long as have not reached NULL.
  //returned a pointer of type struct direct (files)
  while ((file = readdir(dir)) != NULL)
  {
    //flag_a is not active and file name pointed to by file using memeber of struct dirent d_name in index 0 is not '.'
    if (flag->a == '0' && file->d_name[0] != '.')
    {
      newstr[i++] = ft_strdup(file->d_name);
    }
    //flag_a is active
    if (flag->a == '1')
    {
      newstr[i++] = ft_strdup(file->d_name);
      //copy onto new memory the file name pointed in in struct dirent using the member d_name to str, contiue to copy.
    }   
  }
  newstr[i] = NULL;
  closedir(dir);
}