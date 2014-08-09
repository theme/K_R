#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    char a[] = "hello1 is a long string.";
    char b[] = "hello2 is short.";
    int sa = sizeof a;
    int sb = sizeof b;
    void printArray( char *a, int len);

    printArray( a, sa );
    printArray( b, sb );

    strcpy(a,b);
    printf("a:%s b:%s\n", a,b);

    printArray( a, sa );
    printArray( b, sb );
    return 0;
}

void printArray( char *a, int len){
    register int i = 0 ;
    register char c;
    while (len--)
    {
        c = a[i++];
        printf("_");
        if ( isalnum(c) )
        {
            printf("%c", tolower(c));
        }else
        {
            printf("\\%d", c);
        }
    }
    putchar('\n');
}

