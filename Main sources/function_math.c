#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>
#include "function_math.h"

//les formules de projection de Mercator
double lat2y_m(double lat){
  return earth_radius * log(tan(M_PI/4+ deg2rad(lat)/2));
}

double lon2x_m(double lon){
  return deg2rad(lon) * earth_radius;
}

