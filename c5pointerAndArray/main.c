#include <stdio.h>
#include <stdlib.h>
#include "hello.h"

char c;

int main(int argc, char * argv[])
{
    extern int times;
    int a[][2][2] = {1,2,3,4,5,6,7,8,9};

    sayhello(" msg in main");
    printf("%d\n", times);
    printf("extern char %c=%d\n", c, c);
    printf("s con" "cat\n");

    {
        int i;
        for ( i=0; i<10; i++ )
        {
            printf("%d", a[i/4][(i%4)/2][i%2] );
        }
        printf("\n");
    }

    {
        int *pi = 0;
        printf("%p\n", pi);
    }

    {
        int p[13]={1,3,5,2,3,3,53,8,6};
        int (*daytab)[13] = &p;
        void *daytab2 = &p;
        int *dp = (int *) p;

        int i;
        for ( i=0; i<13 ; ++i)
        {
            printf("%d ", (*daytab)[i]);
        }
        printf("\n");
        printf("p=%p\n", p);
        printf("daytab=%p\n", daytab);
        printf("daytab2=%p\n", daytab2);
        printf("dp=%p\n", dp);
        printf("sizeof(int[13])=%lu\n", sizeof (int[13]));
        printf("sizeof(int[2][13])=%lu\n", sizeof (int[2][13]));
        printf("sizeof(\"hello\")=%lu\n", sizeof ("hello"));
    }

    {
        int *da;
        da = malloc( 10 * sizeof(int) );
        printf("da=%p\n", da);
        printf("sizeof da: malloc(10*sizeof(int)) = %lu\n", sizeof(da) );
        free(da);
    }

    printf("%p\n", main);

    return 0;
}

