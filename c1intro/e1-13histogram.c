/* print a histogram of the lengths of words in its input.
 * It is easy to draw with the bars horizontal;
 * vertical orientation is harder
 */

#include <stdio.h>
#include <string.h>

void vertical(int len, char word[]){
    int i;

    for(i=0;i<len;++i)
        printf("-\n");
    for(i=0;i<len;++i)
        putchar(word[i]);
    putchar('\n');
}

void horizontal(int len, char word[]){
    int i;

    for(i=0;i<len;++i)
        putchar('|');
    putchar('\t');
    for(i=0;i<len;++i)
        putchar(word[i]);
    putchar('\n');
}

int main(int argc, char * argv[])
{
    char c,a=EOF;
    char word[100];
    int len = 0;

    void (*fp)( int, char []);
    if ( 2 == argc && 0 == strcmp("-v", argv[1]) )
        fp = vertical;
    else
        fp = horizontal;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if ( a == ' ' || a == '\t' || a == '\n')
                ;
            else{
                fp( len, word );
                len = 0;
            }
        }else{
            word[len++]= c;
        }
        a = c;
    }
    return 0;
}
