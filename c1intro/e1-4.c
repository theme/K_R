/* K_R e1-4 temperature conversion
 * Celsius-Fahrenheit table
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

    celsius = lower;
    //print header
    printf("Celsius Fahrenheit\n");

    while ( celsius <= upper ){
        fahr = ((9.0/5.0) * celsius ) + 32.0;
        printf("%7.0f %10.1f\n",celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
