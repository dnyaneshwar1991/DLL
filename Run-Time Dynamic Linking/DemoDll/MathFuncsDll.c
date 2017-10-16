/** @file MathFuncsDll.c
*   @brief Function definitions for the DLL.
*
*   This contains the definitions for basic math functions,
*   which will be exported from this DLL
*
*   @author Sonu Gupta
*/

#include "MathFuncsDll.h"

double Add(double a, double b)
{
  return a+b;
}

double Sub(double a, double b)
{
  return a-b;
}

double Mul(double a, double b)
{
  return a*b;
}

double Div(double a, double b)
{
  if (b == 0)
  {
    printf("\n Cant Dvivide by Zero!!!");
    return -1;
  }
  else
    return a/b;
}