//
// Created by LI XIAO DONG on 2019/10/8.
//

#include <stdio.h>
#include <math.h>

float Q_rsqrt( float number )
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//    y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
}

void main(){
    float x = 567890567890;
    float q_rsqrt = Q_rsqrt(x);
    float q_sqrt = 1 / q_rsqrt;
    printf("the inverse square root of i is: %f\n", q_rsqrt);
    printf("the square root of x is: %f\n", q_sqrt);

    double y = 567890567890;
    double sqrtofy = sqrt(y);
    printf("the square root of y (%f) is: %f", y, sqrtofy);
}
