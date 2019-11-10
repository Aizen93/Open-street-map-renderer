#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

#ifndef _FUNCTION_MATH_H
#define _FUNCTION_MATH_H
#define deg2rad(d) (((d)*M_PI)/180)
#define rad2deg(d) (((d)*180)/M_PI)
#define earth_radius 6378137

double lat2y_m(double lat);
double lon2x_m(double lon);

#endif



