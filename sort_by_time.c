#include "ft_ls2.h"

char  **sort_by_time(char **newstr, char *str)
{
  int     i;
  int     j;

  i = 0;

  while(newstr[i])
  {
    j = i + 1;
    while(newstr[j])
    {
      struct_sort(str, newstr, i, j);
      j++;
    }
    i++;
  }
  return (newstr); 
}