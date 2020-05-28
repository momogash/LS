#include "ft_ls2.h"

void  chosen_flag(flags *flag, char *str)
{
  if (flag->a == '1' || flag->l == '1'|| flag->t == '1'|| flag->R == '1'|| flag->r == '1')
    flag->active = '1';
  if (flag->active == '0')
  {
    flag->err = '1';
    ft_putstr("wrong flag, please use [-] [altRr]\n");
    ft_putstr(str);
    free(flag);
    exit(0);
  }
}