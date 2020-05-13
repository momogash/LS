#include "ft_ls2.h"

void  skip_first_param(char **str, flags *flag)
{
  int   i;
  int   j;
  char  **newstr;

  i = 0;
  j = 0;
  newstr = NULL;
  while (str[j] && flag->err == '0'&& j < (256 * 256))
  { //y 256*256
    if (array_length(str) > 1)
    {
      ft_putstr(str[j]);
      ft_putendl(":");
    }/* code */
    newstr = folder(newstr, flag, &str[j]);
    i = 0;
		if(flag->l == '1')
			file_info(newstr, str[j]);
    while (newstr[i] != NULL && flag->l == '0')
      ft_putendl(newstr[i++]);
    j++;
  }
  delete(newstr);
}