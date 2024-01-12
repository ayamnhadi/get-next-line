#include"get_next_line.h"
#include <fcntl.h>
#include<stdio.h>
#include "utils/utils.h"
int main()
{char *name = "read_error.txt";
                int fd = open(name, O_RDONLY);
                /* 1 */ test_gnl(fd, "aaaaaaaaaa\n");
                /* 2 */ test_gnl(fd, "bbbbbbbbbb\n");
                // set the next read call to return -1
        
                if (BUFFER_SIZE > 100) {
                        char *temp;
                        do {
                                temp = get_next_line(fd);
                                free(temp);
                        } while (temp != NULL);
                }
                /* 3 */ test_gnl(fd, NULL);
                close(fd);
                fd = open(name, O_RDONLY);
                /* 4 */ test_gnl(fd, "aaaaaaaaaa\n");
                /* 5 */ test_gnl(fd, "bbbbbbbbbb\n");
                /* 6 */ test_gnl(fd, "cccccccccc\n");
                /* 7 */ test_gnl(fd, "dddddddddd\n");
                /* 8 */ test_gnl(fd, NULL);
                
   
}