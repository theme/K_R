#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
    char * prog = argv[0];
    int i;
    char *fn;

    if ( ! ( argc >1 && (fn = argv[1])))
    {
        fprintf(stderr, "%s: usage: readf FILENAME\n", prog);
        exit(0);
    }

    {// open, read, print
        FILE *fp;
        char c;
        if ( NULL  == (fp = fopen( fn , "r")))
        {
            fprintf(stderr, "%s: error open file %s", prog, fn);
            exit(1);
        }

        while ( EOF != ( c = getc( fp ) ))
        {
            putchar(c);
        }
        fclose(fp);
    }

    if(ferror(stdout)){
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}

