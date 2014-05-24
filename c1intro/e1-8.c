#include <stdio.h>

int main(int argc, char * argv[])
{
    float blanks =0;
    float tabs =0;
    float newlines =0;

    char c;

    while ( (c = getchar()) != EOF )
    {
        switch(c){
            case ' ':
                ++blanks;
                break;
            case '\t':
                ++tabs;
                break;
            case '\n':
                ++newlines;
                break;
        }
    }
    printf("blanks:%.0f, tabs:%.0f, newlines:%.0f\n",blanks, tabs, newlines );
    return 0;
}
