/* fold long lines */
#include <stdio.h>

#define MAXCOLUMN 80
#define TABWIDTH 4  /* > 0 */

int countbn( char c);   /* count c equal to ? blanks */
void putline( char []);    /* print char array line, \0 do nothing */
void zeroline( char []);   /* reset line array */
void copyline( char[], char[] );

int main(int argc, char * argv[])
{
    static char line[MAXCOLUMN];
    static char newl[MAXCOLUMN];
    char c;
    int i = 0 , j = 0;

    while ( ( c = getchar() ) != EOF)
    {
        switch(c){
            case '\n':
                if(i == MAXCOLUMN){ //full one line
                    if ( countbn( line[i] ) )
                    {
                    }
                    line[i++] = c;
                    putline( line );
                    copyline( 
                }
                putline( line );
                putchar('\n');
                ; break;
            case ' ':
                if(i < MAXCOLUMN){
                    line[i++] = c;
                }else{
                }
        }
        // save to line > new line
        if ( i < MAXCOLUMN - 1
        // print line , copy newline to line
        line[i++] = c;
        if ( i >)
        {
        }
    }
    //print new line
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

void putline( char line[]){
    int i;
    char c;

    //trim tail blanks
    for (i = MAXCOLUMN-1; i > 0; --i)
    {
        if ( c == ' ' || c == '\t')
            line[i] = '\0';
        else
            break;
    }
    // print
    for (i = 0; i < MAXCOLUMN; ++i)
    {
        c = line[i];
        if ( c != '\0')
            putchar(c);
    }
}

void zeroline( char line[]){
    int i;
    for (i = 0; i < MAXCOLUMN; ++i)
        line[i] = '\0';
}

void copyline( char from[], char to[]){
    int i;
    for (i = 0; i < MAXCOLUMN; ++i)
    {
        to[i] = from[i];
    }
}

