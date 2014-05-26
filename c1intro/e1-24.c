/***************************************************************************
 * Description rudimentary syntax check
 * ( ), [ ], { }, '\escape', " \escape ", /block comment/ ,  //
 *
 ***************************************************************************/

#include <stdio.h>

char gc();  /* gc, change position */
char cc;    /* current char */
long crow=0, ccol =0;    /* current row and pos */
long nrow=1, ncol =1;    /* current row and pos */
void errc( char msg[], char c);     /* print error with current position */
void err( long row, long col, char msg[], char c);

char cCharConst();  /* check a constant char syntax */
char cString();     /* chech a string syntax */
char cLineComment();
char cBlockComment();

char pair(const char c);    /* return pair char to c */
char csyntax(const char r); /* check simple syntax, return on r*/
char cnpairs(char l); /* check pairing (can nest) */
char cquotes(char q);     /* check quotes (no nest) */
char ccom(char c);        /* check comments (no nest) */

int main(int argc, char * argv[])
{
    csyntax(EOF);

    return 0;
}

char cCharConst(){
    char c;
    if ( (c = gc()) != EOF)
    {
        switch(c){
            case '\'':
                break;
            case '\\':
                if ( (c = gc()) != EOF)
                    c = gc();
                break;
            default:
                c = gc();
        }
    }
    return c;
}

char cString(){
    char e, f;
    e = gc();
    if ( e == EOF || e == '\"'){
        return e;
    } else {
        while ( (f = gc() ) != EOF)
        {
            if ( e != '\\' && f == '\"'){
                return f;
            }else if( e!='\\' && f == '\n' ){
                return f;
            }else {
                e = f;
            }
        }
        return EOF;
    }
}

char cLineComment(){
    char e, f;
    e = gc();
    if ( e == EOF || e == '\n'){
        return e;
    } else {
        while ( (f = gc() ) != EOF)
        {
            if ( e != '\\' && f == '\n'){
                return f;
            }else {
                e = f;
            }
        }
        return EOF;
    }
}

char cBlockComment(){
    char e, f;
    while ( ( e = gc() ) != EOF && e != '*')
        ;

    if ( e == '*'){
        if((f = gc()) != EOF){
            if ( f == '/')
                return '/';
            else
                return cBlockComment();
        }else{
            errc("\tbroken block comment at EOF", ' ');
            return EOF;
        }
    }else{
        errc("\tbroken block comment at EOF", ' ');
        return EOF;
    }
}

char pair(const char c){
    switch(c){
        case '(':
            return ')';
        case '[':
            return ']';
        case '{':
            return '}';
        case ')':
            return '(';
        case ']':
            return '[';
        case '}':
            return '{';
        default:
            return EOF;
    }
}

char csyntax( const char r) {
    char c, b;
    long row, col;
    while ( ( c = gc() ) != EOF ){
        if (c == r)
            return r;

        row = crow;
        col = ccol;
        b = 0; // != EOF
        switch (c)
        {
            case '(':
            case '[':
            case '{':
                if ( (b = cnpairs( c )) != pair(c) )
                    err(row,col, "missing right", pair(c));
                break;
            case ')':
            case ']':
            case '}':
                errc("missing left", pair(c));
                break;
            case '\'':
                if( ( b = cquotes('\'') ) != '\''){
                    err(row,col, "char constant missing right",'\'');
                }
                break;
            case '\"':
                if( ( b = cquotes('\"') ) != '\"'){
                    err(row,col, "string constant missing right",'\"');
                }
                break;
            case '/':
                if ( (c = gc()) != EOF) {
                    if ( c == '*')
                    {
                        if( ( b = ccom('*') ) != '/'){
                            err(row,col, "bad block comment",' ');
                        }
                    }else if ( c=='/' ){
                        if( ( b = ccom('/') ) != '\n'){
                            err(row,col, "bad line comment",' ');
                        }
                    }else{
                        err(row,col, "/ in text", ' ');
                        return '/';
                    }
                }else
                {
                    err(row,col, "/ before EOF", ' ');
                    return EOF;
                }
                break;
            default:
                ;
        }
        if( b == EOF)
            return EOF;
    }
    return c;
}

char cnpairs(char l){
    return csyntax( pair(l) );
}

char cquotes(char q){
    if( q == '\'' )
        return cCharConst();
    if( q == '\"' )
        return cString();
    else
        errc("not a quotes start", q);
    return q;
}

char ccom(char c){
    if( c == '*' )
        return cBlockComment();
    if( c == '/' )
        return cLineComment();
    else
        errc("not a comment start /", c);
    return c;
}

char gc(){
    extern char cc;
    extern long nrow, crow, ncol, ccol;
    if ( (cc = getchar()) !=EOF )
    {
        crow = nrow;
        ccol = ncol;
        if ( cc == '\n' ){
            nrow = crow +1;
            ncol = 1;
        }
        else{
            nrow = crow;
            ncol = ccol +1;
        }
    }
    return cc;
}

void err( long row, long col, char msg[], char c){
    printf("%ld:%ld: error: %s: %c\n", row, col, msg, c);
}

void errc( char msg[], char c){
    err( crow, ccol, msg, c);
}

