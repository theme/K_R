#include <stdio.h>
#define MAXLINE 1000
/* maximum input line length */
int readline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len;	/* current current line length */
    int max;	/* maximum length seen so far */
    char line[MAXLINE];	/* current input line */
    char longest[MAXLINE];	/* longest line saved here */
    char c;

    max = 0;
    while ((len = readline(line, MAXLINE)) > 0){
        if (len == (MAXLINE-1) && line[MAXLINE-2] != '\n')/*too long*/
            while ( (c = getchar())!=EOF && c!= '\n')
                len ++;

        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) /* there was a line */
        printf("max=%d\n%s\n",max, longest);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

