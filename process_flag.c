#include "ft_ls2.h"

flags *process_flag(void)
{
	flags *flag;

	flag = (flags *)malloc(sizeof(flags));

	flag->a = '0';
	flag->l = '0';
	flag->t = '0';
	flag->R = '0';
	flag->r = '0';
	flag->err = '0';
	flag->active = '0';
	return (flag);
}

//allocates memory for variable flag dynamically
//takes not parameters, 
// sets all the flag options to '0''
//returns flag of type flags
