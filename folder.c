#include "ft_ls2.h"

void  folder_open_error(char **newstr, char *str)
{
  int i;

  i = 0;
  if  (errno == 2)
  {
    ft_putstr("No such file or directory: ");
    ft_putstr(str);
    ft_putchar('\n');
    exit(0);
  }
  if (errno == 13)
  {
    ft_putstr("Permission denied: ");
    ft_putstr(str);
    ft_putchar('\n');
    exit(0);
  }
  if (errno == 20)
  {
    newstr[0] = ft_strdup(str);
    newstr[1] = NULL;
  } 
}

char  **folder(char **newstr, flags *flag, char **str)
{
  DIR   *folder;

  newstr = (char **)malloc(sizeof(char *) * read_bytes(str[0] + 1));

  if (!(folder = opendir(*str))) //if unable to open the specified directory name and return pointer to that folder
      folder_open_error(newstr, *str);

  //!!!! FT PROTECTOR TO BE DONE

  if(folder) //there is an opened dir?
  {
    closedir(folder);
    open_read_folder(newstr, flag, str);
  }
  open_read_folder_flag(newstr, flag, str);
  return (newstr);
}