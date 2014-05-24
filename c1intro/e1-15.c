/* K_R e1-4 temperature conversion
 * Celsius-Fahrenheit table
 * for fahr = 0,20,..., 300; floating-point version
 * with a header 
 *
 * e1-15, add a function
 */

#include <stdio.h>

float fahrenheit( float celsius ){
    return ((9.0/5.0) * celsius ) + 32.0;
}

int main(int argc, char * argv[])
{
    float celsius;
    float lower, upper, step;

    lower = -60;  /* lower limit of temperature scale */
    upper = 300;  /* upper limit*/
    step = 20;  /* step size*/

    celsius = lower;
    //print header
    printf("Celsius Fahrenheit\n");

    printf("%7.2f %10.1f\n", -273.15, fahrenheit(-273.15));

    while ( celsius <= upper ){
        printf("%7.0f %10.2f\n",celsius, fahrenheit(celsius));
        celsius = celsius + step;
    }

    return 0;
}
