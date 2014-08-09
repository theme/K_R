#include <stdio.h>

int main(int argc, char * argv[])
{
    long a[5] = {1,2,3,4,5};
    long *p,*b;

    b = &a[0];
    p = &a[1];

    printf("sizeof(long)=%lu\n", sizeof(long) );
    printf("&a[1]=%p\n",p );
    printf("&a[0]=%p\n",b );
    printf("&a[1] - &a[0]=%ld\n", &a[1] - &a[0]);

    return 0;
}
