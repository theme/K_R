/* unix api */
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* c std lib */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
    int fd;
    char* name;

    if (argc != 2)
    {
        printf("usage: file FILENAME\n");
        exit(1);
    }else {
        name = argv[1];
    }

    if( 0 > ( fd = open(name, O_RDONLY, 0) ) )
        exit(1);

    {// read and print file
        char buf[5];
        int n;
        while ( 0 < (n = read( fd, buf, 5)))
        {
            write( 1, buf, n );
        }
    }

    close(fd);
    return 0;
}
