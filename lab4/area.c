# include "area.h"
# include <math.h>

double area(double a, double b, double c) {
    double perimetr(double a, double b, double c);
    double p = perimetr(a, b, c) / 2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}