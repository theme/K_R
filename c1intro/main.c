#include <stdio.h>

int main(int argc, char * argv[])
{
    char c;
    printf("EOF=%d\n",EOF );
    int i;
    do{
        c = getchar();
        i = c != EOF;
        printf("in%d\n",i );
    }while(i);
    printf("out %d\n",i );
    return 0;
}
