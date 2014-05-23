#include <stdio.h>

void funa();
void funb();

int main(int argc, char * argv[])
{
    funa();

    return 0;
}

void funa(){
    printf("funa\n");
    funb();
    return;
}
void funb(){
    printf("funb\n");
    return;
}
