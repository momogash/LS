#include "ft_ls2.h"

int		main(int argc, char *argv[])
{

	char	**str;
	flags *flag;
	int		i;
	int		j;

	j = 0;

	str = NULL;
	flag = process_flag(); //now all the flags are set to '0'
	str = read_flag_input(argv, argc);
// //printf("the string printed %s\n",*str);
	ft_sortit(str); //!!!!!!
	arrange(str); //!!!!!!!

	if(argc >= 2)
	{
		choose_flag(argv, flag);
		skip_first_param(&str[j], flag);
	}
	i = 0;
	if (argc == 1)
	{
		no_flag(str, flag);  
	}
	delete(str);
	return (0);
}