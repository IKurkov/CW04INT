/* Kurkov Ivan, 22.B05-MM, 31.03.2024 */
#ifndef INT_H
#define INT_H

/* Struct for store accumulated values of function for partition
   Fields:
   begin = f(left)
   end = f(right)
   even = sum f(edges of segments)
   odd = sum f(middles of segments)
   step = (right - left) / n */
struct AcmFVals
{
  double begin, end, even, odd, step;
};

struct QRUnit
{
  const char *Name;
  double (*Rule)(AcmFVals);
};

AcmFVals Accumulate( double (*f)(double), size_t n, double left, double right );
double QRLeftRectangles( AcmFVals acm );
double QRRightRectangles( AcmFVals acm );
double QRMiddleRectangles( AcmFVals acm );
double QRTrapeze( AcmFVals acm );
double QRSimpson( AcmFVals acm );
double QRThreeEighths( AcmFVals acm );

template <typename T, size_t N>
constexpr size_t Length( const T(&)[N] )
{
  return N;
}

extern const QRUnit QRList[];
extern const size_t NumOfQR;

#endif // !INT_H

