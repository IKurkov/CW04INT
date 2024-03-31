/* Kurkov Ivan, 22.B05-MM, 28.03.2024 */
#include <cmath>

#include "int.h"
#include "test_functions.h"

const FunctionUnit FunctionsList[] = 
{
  {"30", Const, ConstAD},
  {"19x + 5", Linear, LinearAD},
  {"(x + 1)^2", Quadratic, QuadraticAD},
  {"4x^3 - 3x + 1", Qubic, QubicAD},
  {"1 / (1 + x^2)", Special, SpecialAD}
};
const size_t NumOfFunctions = Length(FunctionsList);

double Const( double x )
{
  return 30;
}

double ConstAD( double x )
{
  return 30 * x;
}

double Linear( double x )
{
  return 19 * x + 5;
}

double LinearAD( double x )
{
  return 9.5 * x * x + 5 * x;
}

double Quadratic( double x )
{
  return x * x + 2 * x + 1;
}

double QuadraticAD( double x )
{
  double sqr_x = x * x;

  return sqr_x * x / 3 + sqr_x + x;
}

double Qubic( double x )
{
  return 4 * x * x * x - 3 * x + 1;
}

double QubicAD( double x )
{
  double sqr_x = x * x;

  return sqr_x * sqr_x - 1.5 * sqr_x + x;
}

double Special( double x )
{
  return 1 / (1 + x * x);
}

double SpecialAD( double x )
{
  return atan(x);
}