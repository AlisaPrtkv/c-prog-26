# include "triangle.h"
# include <math.h>

int triangle(double a, double b, double c){
    return (a + b > c) && (a + c > b) && (c + b > a);
}