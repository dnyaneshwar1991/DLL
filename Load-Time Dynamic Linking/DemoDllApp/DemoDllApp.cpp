/** @file DemoDllApp.cpp
*   @brief
*
*   This contains the application which will be using math functions
*   those were exported from the DLL 'MathFuncsdll'
*
*   @author Sonu Gupta
*/

//------------------------------------------------------------------------------
/*!
*   @brief  This is Load time DLL.
    @details
    @n Here you, need to include 'HEADER FILE' which lists all the function prototypes those are exported.

    @n You need to provide the full/relative path of the ".lib" file in project Properties --> Linker --> Input

    @n But main thing is that you need to place the created ".dll" file near your "exe". That is .exe and .dll
       will always be together. If you don't provide ".dll" near exe it will give error.

    @n Maintaining this kind of ".dll" and applications are so onerous, whenever you update your ".dll", you nedd to explicitly
       replace that ".dll" near ".exe".

    @n Also, whenever the library(.dll) is changed, you need to rebuild your application(.exe).
*/
//------------------------------------------------------------------------------ 


//
//	@brief: Relative path of ".h" file where functions are declared
//
#include "..\DemoDll\MathFuncsdll.h"


#include <iostream>
#include <conio.h>
using namespace std;

int
main(
  )
{
  double a = 10.2;
  double b = 5;
  cout<<"\n a = "<<a;
  cout<<"\n b = "<<b;
  cout << endl;
  //
  // @brief: No need to use any function pointers, directly use function name as it is.
  //
  cout<<"\n Addition a+b       = "<<Add(a,b);
  cout<<"\n Substraction a-b   = "<<Sub(a,b);
  cout<<"\n Multiplication a*b = "<<Mul(a,b);
  cout<<"\n Division a/b       = "<<Div(a,b);

  _getch();
  return 0;
}