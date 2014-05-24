#include <stdio.h>

int main(int argc, char * argv[])
{
    char c, a=EOF;

    while ( (c = getchar()) != EOF )
    {
        if ( c == ' ' && a != ' ')
                putchar(c);
        else if ( c == ' ' && a == ' ')
            ;
        else
            putchar(c);

        a = c;
    }
    return 0;
}
