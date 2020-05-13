#include "libft/libft.h"
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    /*DIR Pointer:pointer of type DIR to point or hold the directory stream returned by opendir.
    *Entry: is a dirent struct pointer which will be used to myfile members of dirent struct.
    */
    DIR *folder;
    struct dirent *myfile; 
    struct stat filestat;

    if(argc < 2)
    {
        ft_putstr("too few arguments");
        ft_putstr("\n");
    }

    else
    {
           folder = opendir(argv[1]); //open current directory
            if(folder == NULL) //NUll is returned by opendir if unable to open directory
            {
                ft_putstr("Error opening folder");
                ft_putstr("\n");
                return(1);
            }
    /* we will now read the contents of the directory stream, pointed to by folder
    until Null is reached, meaning untill there isnt anything more to read.
    
    All the entries read, their information/ properties will be pointed to by entry pointer of type dirent.
    Entry pointer will be used to myfile members of type struct dirent so as to get information about the entry.
    Such as d_name which is a memeber of dirent struct which returns the name of the entries(file names)*/
            while((myfile = readdir(folder)) != NULL) 
            {
                
                //ft_putstr("Directory is open");
                if(myfile->d_name[0] != '.') //does it say not print out parent folders and sub? ..
                {
                    stat(myfile->d_name, &filestat);
                    if(S_ISDIR(filestat.st_mode))
                    {
                        // ft_putstr("DIR ");
                        ft_putstr(myfile->d_name);
                        //ft_putstr(filestat.st_size);
                        ft_putstr("\n");
                    }              
                    else
                    {
                        ft_putstr(myfile->d_name);
                        ft_putstr("\n");
                    }
                    // ft_putstr("\n");
                }     

            }
            closedir(folder);
                /* code */
            }
    


    return 0;

}