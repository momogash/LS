#include "ft_ls2.h"

/*
This is a signed integer type used to represent block counts.
blkcnt_t data type Used for file block counts
part of sys/types.h - data types sys/types.h - data types

This is the amount of disk space that the file occupies, measured in units of 512-byte blocks.
*/
void  display_file_count(blkcnt_t size)
{
  ft_putstr("total ");
  ft_putnbr(size);
  ft_putendl(" ");
}

//listing the contents 

void  access_rights(struct stat status)
{
  char *str;

  if (!(str = malloc(sizeof(str) * 10))) // if not able to dynamically allocate space for str
    return ;

//if owner has read permissions return 'r'else return '_' assign to str[0]
  str[0] = (S_IRUSR & status.st_mode) ? 'r' : '-'; //read USR
  str[1] = (S_IWUSR & status.st_mode) ? 'w' : '-'; //write
  str[2] = (S_IXUSR & status.st_mode) ? 'x' : '-'; //execute
  str[3] = (S_IRGRP & status.st_mode) ? 'r' : '-'; //read group
  str[4] = (S_IWGRP & status.st_mode) ? 'w' : '-'; //write 
  str[5] = (S_IXGRP & status.st_mode) ? 'x' : '-'; //execute
  str[6] = (S_IROTH & status.st_mode) ? 'r' : '-'; //read others
  str[7] = (S_IWOTH & status.st_mode) ? 'w' : '-'; //write
  str[8] = (S_IXOTH & status.st_mode) ? 'x' : '-'; //read others
  str[9] = '\0';
  ft_putstr(str);
  ft_strdel(&str);
}
// get information of file -l
void  file_info(char **newstr, char *str) //arguments are the pointer to opened folder(ft_ls) and pointer to the flag (l,a,r,t)
{
  struct stat status; //declare a variable of type stat to access members of stat stucture
  int   i;
  char  *temp;

  i = 0;

  //displaying the total size of folder display_file_count
  display_file_count(file_content_count(newstr)); //takes in a pointer to the opened/read folder from skip_first_param

  while (newstr[i] != NULL)
  {
    /*
    1) find the filepaht ./ store in temp
    2)lstat is a system call that is used to determine information about a file based on its filename.
    3)mode_t st_mode
      the file’s type and it’s permissions are encoded together in one field in the stat structure, the st_mode field
      Specifies the mode of the file. This includes file type information (see Testing File Type) and the file permission bits (see Permission Bits).
    4)stat.S_ISBLK(mode)
      Return non-zero if the mode is from a block special device file.
    */
    lstat((temp = filepath(newstr[i], str)), &status);
    if (S_ISBLK(status.st_mode))
      ft_putchar('b');
    else if (S_ISCHR(status.st_mode))
      ft_putchar('c'); //stat.S_ISCHR(mode)Return non-zero if the mode is from a character special device file.
      else if (S_ISDIR(status.st_mode))
        ft_putchar('d');
      else if (S_ISREG(status.st_mode))
        ft_putchar('_'); //stat.S_ISREG(mode)Return non-zero if the mode is from a regular file.
      else if (S_ISLNK(status.st_mode))
        ft_putchar('l');
      else 
        ft_putchar('?');
      access_rights(status);
      usr_details(newstr[i], str);
      ft_putendl(newstr[i++]);
      ft_strdel(&temp); 
  }
}