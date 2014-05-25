/* fold long lines */
#include <stdio.h>

#define MAXCOLUMN 80
#define TABWIDTH 4
#define MAXWORD 1000

int countbn( char c);   /* count c equal to ? blanks */

int main(int argc, char * argv[])
{
    char c;
    int bn = 0, ba;     /* blank: len, new blank char len */

    char word[MAXWORD]; /* current word */
    int wn = 0;     /* current word len*/

    int col = 0;        /* current column number */

    while ((c=getchar()) != EOF)
    {
        ba = countbn(c);

        if (ba > 0){
            bn += ba;
            if ( (col+bn) > MAXCOLUMN ){
                //putchar('\n');
                //bn = 0;
                //col = 0
            }
        }else {     /* a non-blank char */
            if ( wn < MAXWORD )
                word[wn++] = c;
            else
                //putnewline()
        }
    }

    /* the last word */
    if ( wn > 0)
    {
        if ( col>0)
        {
            //put blanks
            //put word
        }else
        {
            //put word
        }
    }

    return 0;
}

int countbn( char c){
    int bn = 0;
    switch(c){
        case ' ':
            bn += 1;    break;
        case '\n':
            bn += 1;    break;
        case '\t':
            bn += TABWIDTH; break;
        default:
            ;
    }
    return bn;
}
