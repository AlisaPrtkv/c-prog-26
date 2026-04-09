#include <stdio.h>
#include "triangle.h"
#include "perimetr.h"
#include "area.h"

int main() {
    double a,b,c;
    printf("Enter the values of the sides of the triangle: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (! triangle (a,b,c)) {
        printf ("The triangle doesn't exist\n ");
        return 1;
    }

    double p = perimetr(a,b,c);
    double s = area(a,b,c);

    printf("Perimetr: %.2f\n ", p);
    printf ("Area: %.2f\n ", s);

return 0;
}