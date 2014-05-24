/* prints input one word per line */
#include <stdio.h>

int main(int argc, char * argv[])
{
    char c,a=EOF;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if ( a == ' ' || a == '\t' || a == '\n')
                ;
            else
                putchar('\n');
        }else
            putchar(c);
        a = c;
    }

    return 0;
}
