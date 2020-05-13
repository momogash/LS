#include "ft_ls2.h"

//strdel with free to avoid segfaults
void delete(char **str)
{
  int j;

  j = 0;
  while (str[j])
    ft_strdel(&str[j++]);
  free(str);
}