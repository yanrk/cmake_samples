#include <cstdio>
#include "double_operators.h"

int main()
{
    double a = 135.456;
    double b = 7.89;
    printf("%f + %f = %f\n", a, b, double_operators::add(a, b));
    printf("%f - %f = %f\n", a, b, double_operators::subtract(a, b));
    printf("%f * %f = %f\n", a, b, double_operators::multiply(a, b));
    printf("%f / %f = %f\n", a, b, double_operators::divide(a, b));
    return 0;
}
