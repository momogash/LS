#include "ft_ls2.h"

char   **read_flag_input(char **str, int count)
{
    int i;
    int j;
    char **temp;

    i = 1; 
    j = 0;
	//the flags will always be after the path or file name. so the array will be a two dimensional array. i @ 0/ i =0 will be the file name.

    temp = (char **)malloc(sizeof(char *) * count * (256 * 256));
    
    //256 is an equivelant of 1 octant = 8 bits
	//dynamically allocating memory in the heap for flap pointer of type flags
    while (str[i] != NULL)
    {
        if(str[i][0] != '-')
        {
            temp[j] = ft_strdup(str[i]);
            j++;
        }
		i++;
    }
    temp[j] = NULL;
	return (temp);
}
