/*==================================================================
 *
 *               University College Dublin
 *          EEEN20010 - Computer Engineering I
 *
 * File Name	:	flight.c
 *
 * Description	: 	Program to read in lower and upper limits of
 *                  distance travelled by a flight, and calculate
 *                  and print a table of flight times, increasing
 *                  in distance by steps entered by user. Only
 *                  positive numbers will be accepted, and upper
 *                  limit must be greater than lower limit.
 *
 * Author		:	Donal C. Monahan
 *
 * Date			:	29-09-22
 *
 *==================================================================*/

#include <stdio.h>

#define VEL (529 / 0.621371)    /* average velocity in km/h */

int main(void) {

    /* declare variables */
    float lower_lim, upper_lim, step, time, mins;
    int hrs;

    /* prompt user to input lower limit, upper limit and step */
    printf("Enter the lower limit on distance in km: ");
    scanf("%f", &lower_lim);

    printf("Enter the upper limit on distance in km: ");
    scanf("%f", &upper_lim);

    printf("Enter the step size in km: ");
    scanf("%f", &step);

    /* test whether entered values are acceptable */
    if(lower_lim < upper_lim && lower_lim > 0 && upper_lim > 0 && step > 0) {

        /* print table headers */
        printf("===============================================\n|  distance (km)  |    hours    |   minutes   |\n|=============================================|\n");

        /* loop over distance limits, increasing in increments of step */
        for(float i = lower_lim; i <= upper_lim; i += step) {

            /* calculate flight time */
            time = i / VEL;

            hrs = time;                 /* hrs is an int; time is truncated when it is stored in hrs */
            mins = (time - hrs) * 60;   /* time - hrs equals difference between time and hours (in hours). multiply by 60 for mins */

            /* print table row with columns for distance, hours and minutes */
            printf("|%12.2f     |%7.0f      |%7.0f      |\n", i, (float)hrs, mins);

        }

        /* print table footer */
        printf("===============================================\n");

    }

    /* print error message if values are not accepted */
    else

        printf("Error. All values must be positive. Upper limit must be greater than lower limit.\n");

    return 0;

}
