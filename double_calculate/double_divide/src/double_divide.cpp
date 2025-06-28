#include "double_divide.h"

static bool is_zero(double d)
{
    return d > -1e-9 && d < 1e-9;
}

double two_double_divide(double a, double b)
{
    if (is_zero(b))
    {
        throw "Division by zero";
    }
    return a / b;
}
