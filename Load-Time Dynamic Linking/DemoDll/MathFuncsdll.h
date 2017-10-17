/** @file MathFuncsDll.h
*   @brief Function prototypes for the DLL.
*
*   This contains the prototypes for basic math functions,
*   which will be exported from this DLL
*
*   @author Sonu Gupta
*/

//------------------------------------------------------------------------------
/*!
* @brief Following definitions are must in order to use "DLL".
       __declspec(dllexport) needs to be enter because this causes the respective
        function to be exported and use in application(.exe)
*/
//------------------------------------------------------------------------------ 
#ifndef DLLDEMO_EXPORTS
#define DLLDEMO_EXPORTS
#endif

#ifdef DLLDEMO_EXPORTS
#define MATHFUNCSDLL_API __declspec(dllexport)
#else
#define MATHFUNCSDLL_API __declspec(dllimport)
#endif

//------------------------------------------------------------------------------
/*!
* @brief	 Why extern C ?
      Extern "C" is necessary because, C++ does some name mangligs i.e,
	     variable names are changed to some other name format which you can see using CFF explorer.
*/
//------------------------------------------------------------------------------ 
#if __cplusplus
extern "C"
{
#endif

MATHFUNCSDLL_API
double
Add(
  double,
  double
  );

MATHFUNCSDLL_API
double 
Sub(
  double,
  double
  );

MATHFUNCSDLL_API
double 
Mul(
  double,
  double
  );

MATHFUNCSDLL_API
double 
Div(
  double,
  double
  );

#if __cplusplus
}
#endif

//------------------------------------------------------------------------------
/*!
* @brief
    Typedef of every single function is necessary(not manadatory of course) 
    This is used by function "GetProcessAddress".
//
*/
//------------------------------------------------------------------------------ 
typedef double(*PFN_ADD)(double, double);
typedef double(*PFN_SUB)(double, double);
typedef double(*PFN_MUL)(double, double);
typedef double(*PFN_DIV)(double, double);
