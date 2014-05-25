/* write a program to remove trailing blanks and tabs, also blank lines */

#include <stdio.h>
#define MAXBLANK 1000

int main()
{
    int len = 0;        /* current blanks length */
    char blanks[MAXBLANK];      /* current blank sequence */
    //long bn = 0;        /* current blanks num */
    char c;
    int full = 1;       /* is full blank line */
    int i;

    while ( (c = getchar())!= EOF){
        if( c != '\n'){
            if ( c == '\t' || c == ' ' )
            {
                if (len < MAXBLANK-1)
                    blanks[len++] = c;
                else
                    len++;
            }else{
                full = 0;   //not a full blank line
                for(i = 0; i < len; ++i){   // print saved blanks
                    putchar(blanks[i]);
                }
                len = 0;
                putchar(c);
            }
        }else{
            if ( full != 1)
                putchar('\n');
            len = 0;
            full = 1;
        }
    }
    return 0;
}

