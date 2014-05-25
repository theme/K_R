#include <stdio.h>

#define MAXLINE 80
#define TABWIDTH 4

int readline(char line[], int maxline);
int countbn( char c);   /* count c equal to ? blanks */

int main(int argc, char * argv[])
{
    int len;
    char line[MAXLINE+1];
    char b, c;
    int nr = MAXLINE;   /* next read count */
    int i;

    while( (len = readline( line, nr)) > 0 ){
        if (len == (nr-1) && line[nr-2] != '\n'){ /* longer than LIMIT*/
            c = getchar();
            if ( countbn(c) > 0 )       /* next char is blank */
            {
                printf("%s\n%c",line,c );
                nr = MAXLINE-1;
            }else{          /* next char is not blank */
                b = line[nr-2];
                if( countbn( b ) == 0 ) //break a word
                {
                    line[nr-2] = '\0';
                    printf("%s-\n%c%c",line, b, c );
                    nr = MAXLINE-2;
                }else   // break no word
                {
                    printf("%s%c",line,c );
                    nr = MAXLINE-1;
                }
            }
        }
        else{       /* short line */
            printf("%s",line );
            nr = MAXLINE;
        }
    }
    return 0;
}

/* readline: read a line into s, return length */
int readline(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
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

