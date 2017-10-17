/** @file DllDef.cpp
*   @brief
*
*   This contains the definitions of the math functions which will be exported
*
*   @author Sonu Gupta
*/

#include"DllDef.h"

double __stdcall Add(  // Make sure to write same calling convention while declaration and definition of function in dll
  double a,
  double b
 )
{
  return a+b;
}

double __stdcall Sub( // Make sure to write same calling convention while declaration and definition of function in dll
  double a,
  double b
  )
{
  return a-b;
}

