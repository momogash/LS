#include "ft_ls2.h"



blkcnt_t file_content_count(char **newstr)
{
  blkcnt_t size;
  int i;
  struct stat stats; //decalared a variable to access members of stat structure

  size = 0;
  i = 0;
  while(newstr[i])
  {
    if (newstr[i][0] != '.')
    {
      stat(newstr[i], &stats); //pasing folder and pointer of stat
      size += stats.st_blocks; // getting the sze of the folder using st_blocks and signed variable size of type blkcnt
    }
    i++;
  }
  return (size);

}