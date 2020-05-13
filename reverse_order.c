#include "ft_ls2.h"

char  **copy_reversed(char **temp, char **newstr)
{
  int   i;

  i = 0;
  while (temp[i])
  {
    //delete the first character in str[i] then duplicate temp[i] to it. repeat while temp[i] is not null.
    ft_strdel(&newstr[i]);
    newstr[i] = ft_strdup(temp[i]);
    i++;
  }
  return (newstr);
}

int   array_size(char **newstr)
{
  int   i;

  i = 0;

  while (newstr[i] != NULL)
    i++;
  return (i);
}

/*array[i++] means *( array + (i++) ). --> Increments the Index.
array[i++] does not modify array, evaluates to 1 and changes i to 2.*/

char  **reverse_order(char **newstr)
{
  int   i;
  int   j;
  char  **temp;

  i = 0;
  j = array_size(newstr) - 1;
  temp = (char **)malloc(sizeof(char *) * (j+2));
//start duplicating from the back of str[j]. j is the total length of str untill we reach index 0.
  while (j >= 0)
    temp[i++] = ft_strdup(newstr[j--]); 
  temp[i] = NULL;

  newstr = copy_reversed(temp, newstr);
  delete(temp);
  return (newstr);
}