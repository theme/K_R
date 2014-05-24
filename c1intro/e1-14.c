/* print a histogram of the frequency of difference characters
 */

#include <stdio.h>
#include <string.h>

#define LINE_LEN 40
#define V_HEIGHT 16

void vertical(float cn[], float maxcn){
    int i,j;
    int h;

    for ( i=0; i<V_HEIGHT; ++i )
    {
        for ( j=0; j< 26*2; ++j )
        {
            if ( i >= V_HEIGHT * (1 - cn[j] / maxcn) )
                putchar('|');
            else
                putchar(' ');
        }
        putchar('\n');
    }
    for ( j=0; j< 26; ++j )
        putchar('a'+j);
    for ( j=0; j< 26; ++j )
        putchar('A'+j);
    putchar('\n');
}

void horizontal(float cn[], float maxcn){
    int i,j;
    int len;
    // lower case chars
    for ( i = 0; i< 26 ; ++i )
    {
        printf( "%c %.0f \t", 'a' + i, cn[i]);
        len = (int) LINE_LEN * ( cn[i]/maxcn );
        for ( j = 0; j<len ;++j )
            putchar( '|' );
        putchar('\n');
    }

    // upper case chars
    for ( i = 0; i< 26 ; ++i )
    {
        printf( "%c %.0f \t", 'A' + i, cn[i+26]);
        len = (int) LINE_LEN * ( cn[i+26]/maxcn );
        for ( j = 0; j<len ;++j )
            putchar( '|' );
        putchar('\n');
    }
}

int main(int argc, char * argv[])
{
    char c,a=EOF;
    float cn[26*2] = {};
    float maxcn =0;
    int i;

    void (*fp)(float [], float);
    if ( 2 == argc && 0 == strcmp("-v", argv[1]) )
        fp = vertical;
    else
        fp = horizontal;

    while ((c = getchar()) != EOF)
    {
        if ( 'a' <= c && c <= 'z' ){
            ++cn[ c - 'a' ];
        }else if ( 'A' <= c && c <= 'Z' ){
            ++cn[ c - 'A' + 26];
        }
    }

    for (i=0; i< 26*2 ; ++i)
    {
        if ( cn[i] >= maxcn)
            maxcn = cn[i];
    }

    fp( cn , maxcn);
    return 0;
}
