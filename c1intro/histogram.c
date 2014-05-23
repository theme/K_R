#include <stdio.h>

int main(int argc, char * argv[])
{
    char c;
    while ( EOF != ( c = getchar() ))
    {
        putchar(c);
    }
    putchar('\n');

    return 0;
}
