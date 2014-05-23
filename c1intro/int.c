#include <stdio.h>

int main(int argc, char * argv[])
{
    unsigned long l=1;
    unsigned int i;
    for ( i=1; i>0 ; i++)
    {
        l++;
    }
    printf("i %u\n",i );
    printf("i-1 %u\n",i-1 );
    printf("l %lu\n",l );

    return 0;
}
