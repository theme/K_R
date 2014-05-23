#include <stdio.h>

enum ea;
enum ea { BELL='\a', LONG=0xFFFFFF };
enum eb { LONGB=0xFFFFFFFFFFFF } b;

int main(int argc, char * argv[])
{
    enum ea a=3 ;
    printf("%d\n",sizeof(a));
    printf("%d\n",sizeof(b));
    printf("%lx\n",LONG);
    return 0;
}
