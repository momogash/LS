#include "ft_ls2.h"

int nbr_count(int i)
{
  int k;

  k = 0;
  while (i /= 10) //divide i with 10 and assigns the result i
    k++;
  return (k);
}

void space(int i, int j)
{
  int k;

  k = 0;
  while(k <(j-i))
  {
    ft_putchar(' ');
    k++;
  }
}

void group(struct stat status)
{
  struct group  *member;
//st_gid Group id of the owner
//getgrgid return a pointer to a group structure
  //if we getgrgid returns null and not a pointer to group struct
    //put the number of the group id of owner
    //else put the name of the group
  if (!(member = getgrgid(status.st_gid)))
    ft_putnbr(status.st_gid);
  else
  {
    ft_putstr(member->gr_name);
  }
  //st_size Size in bytes of a plain file
  space(nbr_count(status.st_size), 6);
  ft_putnbr(status.st_size);
  ft_putchar(' '); 
}

void  date_format(struct stat status)
{
  char **date;
  //use status to access members of the stat struct and get the mtimespec.tv_sec which is the Time of last modification in seconds.
  //ctime this function returns a string that contains the date and time which is in human readable form.
  //take the time format in string returned by ctime and split by sapce
  date = ft_strsplit(ctime(&status.st_mtimespec.tv_sec), ' ');
  ft_putstr(date[1]);
  ft_putstr(" ");
  //if not date[2][1] return space or 0
  !date[2][1] ? ft_putchar(' ') : 0;
  ft_putstr(date[2]);
  ft_putstr(" ");
  date[3][5] = '\0';
  date[4][4] = '\0';
  ft_putstr(date[3]);
  delete(date);
}

int usr_details(char *newstr, char *str)
{
  struct stat   status;
  struct passwd *owner;
  char      *temp;

  temp = NULL;
  if ((ft_strcmp(newstr, str)) == 0)
    lstat(temp = filepath(newstr, "."), &status); //int lstat(const char *filename, struct stat *buf);
  else
    lstat((temp = filepath(newstr, str)), &status);
    //st_nlink = this count keeps track of how many directories have entries for this file
    //where does the 4 come from????
  space(nbr_count(status.st_nlink), 4);
  ft_putnbr(status.st_nlink);
  ft_putchar(' ');
//st_uid contains The user ID of the file’s owner.
//getpwuid functions return a pointer to a passwd structure, takes in userid
  owner = getpwuid(status.st_uid);
  //owner will now be used to access members of the passwd struct
  ft_putstr(owner->pw_name); //pw_name is User's login name
  ft_putchar(' ');
  group(status);
  date_format(status);
  ft_putchar(' ');
  ft_strdel(&temp);
  return (0); 
}