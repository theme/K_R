/* K_R e1-5 temperature conversion
 * Fahrenheit-Celsius table
 * for fahr = 300, 280, ..., 0; floating-point version
 * with a header */

#include <stdio.h>

int main(int argc, char * argv[])
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;  /* lower limit of temperature scale */
    upper = 300;  /* upper limit*/
    step = 20;  /* step size*/

    
    //print header
    printf("Fahrenheit Celsius\n");

    for (fahr = upper; fahr >= lower; fahr -= step){
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%10.0f %7.1f\n",fahr, celsius );
    }

    return 0;
}
