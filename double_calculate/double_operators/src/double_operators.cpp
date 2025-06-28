#include "double_operators.h"
#include "double_add.h"
#include "double_subtract.h"
#include "double_multiply.h"
#include "double_divide.h"

namespace double_operators
{
    double add(double a, double b)
    {
        return two_double_add(a, b);
    }

    double subtract(double a, double b)
    {
        return two_double_subtract(a, b);
    }

    double multiply(double a, double b)
    {
        return two_double_multiply(a, b);
    }

    double divide(double a, double b)
    {
        return two_double_divide(a, b);
    }
}
