#include <stdio.h>

#define TABWIDTH 4

int main(int argc, char * argv[])
{
    char c;
    int i;

    while ((c=getchar()) != EOF)
    {
        if (c=='\t')
        {
            for (i=0; i< TABWIDTH ; ++i)
                putchar(' ');
        }else
            putchar(c);
    }

    return 0;
}
