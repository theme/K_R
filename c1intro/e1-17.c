/* print all input lines that are longer than 80 characters.*/

#include <stdio.h>
#define MAXLINE 80

/* maximum input line length */
int readline(char line[], int maxline);

int main()
{
    int len;	/* current current line length */
    char line[MAXLINE];	/* current input line */
    char c;

    while ((len = readline(line, MAXLINE)) > 0){
        if (len == (MAXLINE-1) && line[MAXLINE-2] != '\n'){ /* longer than LIMIT*/
            printf("%s", line );
            while ( (c = getchar())!=EOF && c!= '\n'){
                putchar(c);
                len ++;
            }
            putchar('\n');
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
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    //printf("%d | %s",i, s);
    return i;
}

