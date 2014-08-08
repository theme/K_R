#include <stdio.h>
static int times = 2;

void sayhello( char s[]){
    printf("hello of %d %s", ++times , s);
}
