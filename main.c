#include"get_next_line.h"
#include <fcntl.h>
#include<stdio.h>
int main()
{
    int fd = open("read_error.txt",O_RDWR);
    char *line ;
    line = get_next_line(fd);
    printf("1: %s",line);
    free(line), line = NULL;
	line = get_next_line(fd);
    printf("2: %s",line);
    free(line), line = NULL;
	line = get_next_line(fd);
    printf("3: %s",line);
    free(line), line = NULL;
	line = get_next_line(fd);
    printf("4: %s",line);
    free(line), line = NULL;
	line = get_next_line(fd);
    printf("5: %s",line);
    free(line), line = NULL;
   
}