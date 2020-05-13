#include "ft_ls2.h"
 // i dont know what these do

char *turn(char **str)
{
	int		i;
	char	*temp;
	struct stat status;
	

	i = 1;
	temp = NULL;
	while (str[i])
	{
		if (stat(str[i], &status) == 0)
		{
			temp = ft_strdup(str[i]);
			break;
		}
		i++;
	}
	if (temp == NULL)
		temp = ft_strdup(".");
	return (temp);
}

void	arrange(char **str)
{
	int	i;

	i = 0;
	if(str[0] == NULL)
	{
		str[i] = turn(str);
		str[i + 1] = NULL; 
	}
}

