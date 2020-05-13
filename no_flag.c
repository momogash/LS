#include "ft_ls2.h"

void  no_flag(char **str, flags *flag)
{
  int   i;
  char  **temp;

  i = 0;
  temp = NULL;
  temp = folder(temp, flag, str);
  while (temp[i] != NULL)
    ft_putendl(temp[i++]);
  delete(temp);
}