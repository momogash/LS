#include "ft_ls2.h"
//receives from readflag
void  ft_sortit(char **str)
{
  char  *hold;
  int   i;
  int   j;
  char  *temp;

  i = 0;

  //str = a./ft_ls
  while(str[i] != NULL)
  {
    j = i + 1;
    while(str[j] != NULL)
    {
      //if str[j] is less than str[i] in ascii then we execute below code
      if (ft_strcmp(str[i], str[j]) > 0) 
      {
        temp = ft_strdup(str[i]);
        hold = str[i];
        str[i] = ft_strdup(str[j]);
        ft_strdel(&hold);
        hold = str[j];
        str[j] = temp;
        ft_strdel(&hold);
      }
      j++;
    }
    i++;
  }
}