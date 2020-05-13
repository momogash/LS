#include "ft_ls2.h"

void  open_read_folder_flag(char **newstr, flags *flag, char **str)
{
  ft_sortit(newstr);

  if (flag->t == '1')
    newstr = sort_by_time(newstr, *str);
  if (flag->r == '1')
    newstr = reverse_order(newstr);
}


