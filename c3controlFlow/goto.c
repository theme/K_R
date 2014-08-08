#include <stdio.h>
int main(int argc, char * argv[])
{
    goto label2;
    goto label1;

label1:
    printf("hello you\n");
    goto end;

label2:
    printf("hello 2\n");
    goto label1;

end:
    printf("end\n");
    return 0;
}
