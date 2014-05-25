/* write a program to reverse input aline at a time.*/

#include <stdio.h>
#define MAXLINE 80

/* maximum input line length */
int readline(char line[], int maxline);
void reverse(char str[], int len);

int main()
{
    int len;	/* current current line length */
    char line[MAXLINE];	/* current input line */
    char c;

    while ((len = readline(line, MAXLINE)) > 0){
        reverse(line,len);
        printf("%s",line);
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

void reverse(char str[], int len){
    char c;
    int i;
    for ( i = 0; i< (len-1)/2 ; ++i )
    {
        c = str[i];
        str[i] = str[ len -i -2 ];
        str[ len -i -2 ] = c;
    }
}

