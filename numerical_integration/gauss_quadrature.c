#include<stdio.h>
#include<common_include.h>
#include<math.h>

/*
* gauss_quadrature
 */

float gauss_quadrature()
{
        float area = 0.0;
        float interval_value = 0.0;
        float k = 0.0;

        interval_value = (UPPER_BOUND - LOWER_BOUND)/2;
        k = LOWER_BOUND + interval_value;

        area = interval_value * (sin(k - (interval_value/(sqrt(3)))) + sin(k + (interval_value/(sqrt(3)))));

        return area;
}

