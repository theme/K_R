#include <stdio.h>

#define TABWIDTH 4

int main(int argc, char * argv[])
{
    char c;
    int i;
    int bn; /* blank num */

    while ((c=getchar()) != EOF)
    {
        if (c==' ')
        {
            ++bn;
            if (bn>= TABWIDTH)
            {
                putchar('\t');
                bn -= TABWIDTH;
            }
        }else{
            for (;bn>0 ;--bn )
                putchar(' ');
            putchar(c);
        }
    }

    return 0;
}
