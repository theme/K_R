/* fold long lines */

#include <stdio.h>

#define MAXCOLUMN 80
#define TABWIDTH 4  /* > 0 */

int countbn( char c);   /* count c equal to ? blanks */
void putline( char [], int);    /* print char array line of length */
int lastwordend( char [], int);
int lastwordbegin( char [], int);

int main(int argc, char * argv[])
{
    static char line[MAXCOLUMN*2];
    char c;
    int ci = 0;     /* current inserted char in line */
    int p = -1;     /* index of last not blank char, in line */
    int ep, bp;     /* index of last word end, this word begin */
    int infolding = 0;

    int i,j;

    while ( ( c = getchar() ) != EOF)
    {
        if (ci<MAXCOLUMN)        /* one line not full */
        {
            line[ci++] = c;
            if ( 0 == countbn(c) )
                p = ci;
        }else               /* got a full line */
        {
            if ( countbn(c) )           /* c: a blank */
            {
                putline( line, p+1);
                putchar('\n');
                ci = 0;
                p = -1;
                // eat blank
                while ( ( c = getchar() ) != EOF && (countbn(c)))
                    ;
                if ( c == EOF)
                    break;
                else
                    line[0] = c;
            }else{                      /* c: not a blank */
                if (countbn( line[MAXCOLUMN] )) /* break just before a word */
                {
                    putline( line, p+1);
                    putchar('\n');
                    ci = 0;
                    p = -1;
                    line[ci++] = c;
                }else   /* break in words */
                {
                    // search back one word end
                    ep = lastwordend( line, p);
                    // success: print to that word, rest to new line
                    if (ep != -1)
                    {
                        putline( line, ep);
                        putchar('\n');
                        bp = lastwordbegin( line, p);
                        for (ci = 0; ci < p - bp + 1; ++ci)
                            line[ci] = line[ci + bp];
                        p = ci;
                        line[ci++] = c;

                    }
                    // fail: add word concatenate sign - and to new line
                    else
                    {
                        putline( line, MAXCOLUMN-1 );
                        putchar('-');
                        putchar('\n');
                        line[0] = line[MAXCOLUMN];
                        line[1] = c;
                        p = ci = 1;
                    }
                    ep = -1;
                }
            }
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

void putline( char line[], int len){
    int i;
    for (i = 0; i < len; ++i)
        putchar(line[i]);
}

/* assert: line[p] is not blank char
 * search back to the end of last word
 */
int lastwordend( char line[], int p){
    //to blank or zero pos
    while ( countbn(line[p--])  != 0 && p >= 0)
        ;
    if ( p == -1 && countbn(line[0]) != 0)
        return -1;

    //to char or zero pos
    while ( countbn(line[p--])  == 0 && p >= 0)
        ;
    if ( p == -1 && countbn(line[0]) == 0)
        return -1;

    return p;
}

/* assert: line[p] is not blank char
 */
int lastwordbegin( char line[], int p){
    while ( countbn( line[p--] ==0 && p>=0))
            ;
    if ( p == -1 && countbn(line[0]) == 0)
        return -1;
    return p;
}
