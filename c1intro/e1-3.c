/* K_R e1-3 temperature conversion
 * Fahrenheit-Celsius table
 * for fahr = 0,20,..., 300; floating-point version
 * with a header */

#include <stdio.h>

int main(int argc, char * argv[])
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;  /* lower limit of temperature scale */
    upper = 300;  /* upper limit*/
    step = 20;  /* step size*/

    fahr = lower;
    //print header
    printf("Fahrenheit Celsius\n");

    while ( fahr <= upper ){
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%10.0f %7.1f\n",fahr, celsius );
        fahr = fahr + step;
    }

    return 0;
}
