#include <stdio.h>

int main(int argc, char * argv[])
{
    typedef struct node{
        char c;
        int i;
        long l;
        char c2;
    } Node;

    Node na;

    printf("sizeof(char)=%lu\n",sizeof(char) );
    printf("sizeof(int)=%lu\n",sizeof(int) );
    printf("sizeof(long)=%lu\n",sizeof(long) );
    printf("sizeof(Node)=%lu\n",sizeof(Node) );

    return 0;
}
