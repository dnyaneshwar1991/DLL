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
*  @brief  This is Run time DLL.
   @details
         @n Here you, only need to include header files like "windows.h" and others which you require. 
         No need to include ".h" file of dll. But if u have defined "typedef Function Pointer in ".h" 
         file of DLL then you need to include it.
         For instance, in this example I have used function pointer 'PFN_ADD', 'PFN_SUB', 'PFN_MUL' etc.

         @n 'LoadLibrary()' and 'GetProcAddress()' Functions are mandatory for loading the DLL and required functions.

         @n Unlike Load-time DLL, you don't need to provide "dll" file near "exe of an application".
         Just provide the relative path of the required DLL to LoadLibrary() function.
         This is the main advantage of "Run time DLL".

         @n Also, whenever library(.dll) is changed, you dont need to rebuild the application.
*/
//------------------------------------------------------------------------------ 

#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <conio.h>
#include "..\DemoDll\MathFuncsdll.h" // Included, since it has function pointers, you can create your own function pointers 
using namespace std;

#define DLL_PATH  _T("..\\DemoDll\\Debug\\DemoDll.dll")

int
main(
  )
{
  HINSTANCE hDllHandle = NULL;

  // Following declarations have been taken from ".h" of DLL
  PFN_ADD AddFunc = NULL;
  PFN_SUB SubFunc = NULL;
  PFN_MUL MulFunc = NULL;
  PFN_DIV DivFunc = NULL;

  //
  //	Loadlibrary function to load the DLL at run-time.
  //
  hDllHandle = LoadLibrary(DLL_PATH);
  if(NULL == hDllHandle)
  {
    cout<<"Error in loading Dll";
    return 0;
  }

  //
  // GetProcAddress to get the address of the required function.
  //


  // Addition
  AddFunc = (PFN_ADD)GetProcAddress(hDllHandle, "Add");

  if(NULL != AddFunc)
  {
    cout<<" Addition is:" << AddFunc(10, 20) << endl; //Created function pointer object can be used instead of actual function name.
  }
  else
  {
    cout<<" Error: " << std::dec << GetLastError() << endl;
  }

  // Substraction
  SubFunc = (PFN_SUB)GetProcAddress(hDllHandle, "Sub");

  if (NULL != SubFunc)
  {
    cout << " Substraction is:" << SubFunc(10, 20) << endl; //Created function pointer object can be used instead of actual function name.
  }
  else
  {
    cout << " Error: " << std::dec << GetLastError() << endl;
  }

  // Multiplication
  MulFunc = (PFN_ADD)GetProcAddress(hDllHandle, "Mul");

  if (NULL != MulFunc)
  {
    cout << " Multiplication is:" << MulFunc(10, 20) << endl; //Created function pointer object can be used instead of actual function name.
  }
  else
  {
    cout << " Error: " << std::dec << GetLastError();
  }

  // Division
  DivFunc = (PFN_ADD)GetProcAddress(hDllHandle, "Div");

  if (NULL != DivFunc)
  {
    cout << " Division is:" << DivFunc(10, 20) << endl; //Created function pointer object can be used instead of actual function name.
  }
  else
  {
    cout << " Error: " << std::dec << GetLastError() << endl;
  }

  //
  // Frees the library at the end
  //
  FreeLibrary(hDllHandle); 

  _getch();
  return 0;
}