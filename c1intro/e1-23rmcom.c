#include <stdio.h>

char repeatCharConst();
char repeatString();
char eatLineComment();
char eatBlockComment();

int main(int argc, char * argv[])
{
    char c, d, r=0;
    while ( ( c = getchar() ) != EOF )
    {
        switch(c){
            case '\'':
                r = repeatCharConst();
                break;
            case '\"':
                r = repeatString();
                break;
            case '/':
                d = getchar();
                if ( d == '/'){
                    r = eatLineComment();
                    break;
                } else if ( d == '*'){
                    r = eatBlockComment();
                    break;
                } else if ( d == EOF){
                    return 0;
                } else {
                    putchar(c); putchar(d);
                    continue;
                }
            default:
                putchar(c); continue;
        }
        if (r == EOF) // break from swtich
            break;
    }

    return 0;
}

char repeatCharConst(){
    char c;
    putchar('\'');
    if ( (c = getchar()) != EOF)
    {
        putchar(c);
        switch(c){
            case '\'':
                return c;
            case '\\':
                if ( (c = getchar()) != EOF) {
                    putchar(c);
                    if ( (c = getchar()) != EOF) {
                        putchar(c);
                        return c;
                    }else
                        return EOF;
                }else
                    return EOF;
                break;
            default:
                if ( (c = getchar()) != EOF) {
                    putchar(c);
                    return c;
                }else
                    return EOF;
        }
    }
    else
        return EOF;
}

char repeatString(){
    char e, f;
    putchar('\"');  // left "
    e = getchar();

    if ( e == EOF)  // broken EOF
        return EOF;
    else if ( e == '\"'){
        putchar('\"');  // right "
        return '\"';
    }
    else{   // into string
        putchar(e);
        
        while ( (f = getchar() ) != EOF)
        {
            if ( e != '\\' && f == '\"'){
                putchar('\"');  // right "
                return '\"';
            } else{
                putchar(f);
                e = f;
            }
        }
        return EOF;
    }
}

char eatLineComment(){
    char e;
    while ( ( e = getchar() ) != EOF && e != '\n')
        ;
    if ( e == '\n')
        putchar(e);
    return e;
}

char eatBlockComment(){
    char e, f;
    while ( ( e = getchar() ) != EOF && e != '*')
        ;

    if ( e == '*'){
        f = getchar();
        if ( f == '/')
            return '/';
        else if ( f == EOF )
            return EOF;
        else
            return eatBlockComment();
    }
    else
        return EOF;
}

