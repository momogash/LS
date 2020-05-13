#include "ft_ls2.h"

int array_length(char **str)
{
  int i;

  i = 0;
  while(str[i] != NULL)
  i++;
  return (i);

  // use stringleght
  //consider clustering with skip_first param.c
}