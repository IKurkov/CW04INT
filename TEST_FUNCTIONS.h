/* Kurkov Ivan, 22.B05-MM, 28.03.2024 */
#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

/* Expr = string expression of function
   Func = evaluated function
   FuncAD = Antiderivative of function */
struct FunctionUnit
{
  const char *Expr;
  double (*Func)( double );
  double (*FuncAD)( double );
};

double Const( double x );
double ConstAD( double x );
double Linear( double x );
double LinearAD( double x );
double Quadratic( double x );
double QuadraticAD( double x );
double Qubic( double x );
double QubicAD( double x );
double Special( double x );
double SpecialAD( double x );

extern const FunctionUnit FunctionsList[];
extern const size_t NumOfFunctions;

#endif // !TEST_FUNCTIONS_H