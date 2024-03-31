/* Kurkov Ivan, 22.B05-MM, 28.03.2024 */
#include <iostream>
#include <conio.h>

#include "int.h"
#include "test_functions.h"
#include "fort.hpp"


int main( void )
{
  bool run = true;
  int FId = -1, key;
  size_t n;
  double a = 1, b = -1, I, I_QR;
  AcmFVals acm_vals;

  while (run)
  {
    std::cout << "Numerical integration menu:\n"
      "0 - exit\n"
      "1 - interpolation quadrature rules\n"
      "2 - composite quadrature rules\n"
      "3 - change function\n"
      "4 - change segment\n"
      "5 - change cardinality of partition\n";
    key = _getch();

    if (key == '1' || key == '2' || key == '3')
    {
      if (FId == -1 && key == '3')
      {
        std::cout << "[Error]: No previous run data found!\n";
        continue;
      }

      std::cout << "Choose function to integrate:\n";
      for (size_t i = 0; i < NumOfFunctions; i++)
        std::cout << i << " - f(x) = " << FunctionsList[i].Expr << '\n';
      while ((FId = _getch() - '0') < 0 || FId >= NumOfFunctions)
        std::cout << "[Error]: Incorrect choice, try again!\n";
    }
    if (key == '1' || key == '2')
    {
      do
      {
        std::cout << "Input [a, b]: ";
        std::cin >> a >> b;
      } while (a > b);
      if (key == '1')
        n = 1;
      else
      {
        std::cout << "Input cardinality of partition: ";
        std::cin >> n;
      }
    }
    if (key == '4')
    {
      if (FId == -1)
      {
        std::cout << "[Error]: No previous run data found!\n";
        continue;
      }

      do
      {
        std::cout << "Input [a, b]: ";
        std::cin >> a >> b;
      } while (a > b);
    }
    if (key == '5')
    {
      if (FId == -1)
      {
        std::cout << "[Error]: No previous run data found!\n";
        continue;
      }

      std::cout << "Input cardinality of partition: ";
      std::cin >> n;
    }

    if (key == '0')
      run = false;
    else if (key > '0' && key <= '5')
    {
      fort::char_table output;

      I = FunctionsList[FId].FuncAD(b) - FunctionsList[FId].FuncAD(a);
      acm_vals = Accumulate(FunctionsList[FId].Func, n, a, b);
      std::cout << "Int(" << FunctionsList[FId].Expr << ", " << a << ", " << b << ") = " << I << '\n';
      output << fort::header << "Method" << "I(h)" << "|I - I(h)|" << "|I - I(h)| / |I|" << fort::endr;
      for (size_t i = 0; i < NumOfQR; i++)
      {
        I_QR = QRList[i].Rule(acm_vals);
        output << QRList[i].Name << I_QR << fabs(I - I_QR) << fabs(I - I_QR) / fabs(I) << fort::endr;
      }
      if (key == '1')
      {
        I_QR = QRThreeEighths(acm_vals);
        output << "3/8" << I_QR << fabs(I - I_QR) << fabs(I - I_QR) / fabs(I) << fort::endr;
      }
      std::cout << output.to_string();
    }
    else
      std::cout << "[Error]: Incorrect choice!\n";
  }
  return 0;
}