/** @file DllDef.h
*   @brief
*
*   This contains the prototypes of the math functions which will be exported
*
*   @author Sonu Gupta
*/


//------------------------------------------------------------------------------
/*!
*   @details
    
    @n Here,you don't need to define any __declspec(dllexport/dllimport) because you are using ".def"
      	file and using this linker automatically decides which functions has been exported and all.

    @n Compiler internally by default use "__cdecl" coding convention. Whereas other companies compiler mostly uses "__stdcall" 
     calling convention so better use it. Another calling convention is "__fastcall".
     For more details regarding calling conventions, @see http://coderdreambook.blogspot.in/2013/10/stdcall-vs-cdecl.html
*/
//------------------------------------------------------------------------------ 

#if __cplusplus
extern "C"
{
#endif

double __stdcall // Make sure to write same calling convention while declaration and definition of function in dll
Add(
  double,
  double
 );

double __stdcall // Make sure to write same calling convention while declaration and definition of function in dll
Sub(
  double,
  double
 );

#if __cplusplus
}
#endif

// Function pointers

typedef double
(__stdcall *PFN_ADD)(
 double,
 double
);

typedef double
(__stdcall *PFN_SUB)(
 double,
 double
);
