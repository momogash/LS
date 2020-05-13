#include "ft_ls2.h"

int   choose_flag(char *argv[], flags *flag)  
{
    int i;

    i = 0;

    while(argv[i] != NULL)
    {
      if (argv[i][0] == '-')
      {
        if (ft_strchr(argv[i], 'a'))
          flag->a = '1';
        if (ft_strchr(argv[i], 'l'))
          flag->l = '1';
        if (ft_strchr(argv[i], 't'))
          flag->t = '1';
        if (ft_strchr(argv[i], 'R'))
          flag->R = '1';
        if (ft_strchr(argv[i], 'r'))
          flag->r = '1';
        chosen_flag(flag, argv[i]);
      }
      i++;   
    }
    return (1); 
}