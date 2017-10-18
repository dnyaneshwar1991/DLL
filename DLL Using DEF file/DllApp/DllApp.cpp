/** @file DllApp.cpp
*   @brief
*
*   This is the application project using functionality of DLLDef.
*
*   @author Sonu Gupta
*/

#include <windows.h>
#include <iostream>
#include <conio.h>
#include "..\Dll_using_def\DllDef.h"  // has function pointers
using namespace std;

int 
main(
	)
{
  double a = 22;
  double b = 20;
  PFN_ADD  FuncAdd = NULL;
  PFN_SUB  FuncSub = NULL;
  HINSTANCE hDllHandle = NULL;

  hDllHandle = LoadLibrary(L"..\\Dll_using_def\\Debug\\Dll_using_def.dll"); //dont forget to give PATH_SEPARATOR "\\"
  if(NULL == hDllHandle)
  {
    cout<<"Error in loading library: ErrorCode: "<<GetLastError();
    _getch();
    return 0;
  }

  FuncAdd = (PFN_ADD)GetProcAddress(hDllHandle,"Add");
  if (NULL == FuncAdd)
  {
    cout << "Error in loading library: ErrorCode: " << GetLastError();
    return 0;
  }

  FuncSub = (PFN_SUB)GetProcAddress(hDllHandle,"Sub");
  if (NULL == FuncSub)
  {
    cout << "Error in loading library: ErrorCode: " << GetLastError();
    return 0;
  }

  cout<<"\n Addition is:      "<<FuncAdd(a,b);
  cout<<"\n Substarction is:  "<<FuncSub(a,b);

  FreeLibrary(hDllHandle);

  _getch();
  return 0;
}



