#include <iostream>
#include "windows.h"
#include <string>

using namespace std;

HWND hWinRMM;

BOOL CALLBACK GetHandleMM(HWND hWnd, unsigned long hproc)
{
      LPSTR str;
      char buffer[100];
      str = buffer;
      GetWindowText(hWnd,str, 99);
      if (strstr(str,"RamMap - Sysinternals"))
      {
           hWinRMM = hWnd;
           cout << "Found Handler:" << hWinRMM << endl;
      }

      if (hWnd != NULL) return true;
      return false;

}


int main(int argc,char *argv[])
{

if(argc == 2)
{
  hWinRMM = NULL;
  ShellExecute(NULL, "open", argv[1], NULL, NULL, 1);

  Sleep(1000);
  EnumWindows((WNDENUMPROC)GetHandleMM,0);
  if (hWinRMM == NULL)
  {
      cerr << "RAMMAP NOT FOUND" ;
      return 1;
  }
  SetWindowText(hWinRMM,"Окно перехвачено лаунчером!");
  PostMessage(hWinRMM, WM_COMMAND, 0x00009C93 , 0); // Empty Working Sets
  Sleep(1000);
  PostMessage(hWinRMM, WM_COMMAND, 0x00009C97 , 0); // Empty System Working Set
  Sleep(1000);
  PostMessage(hWinRMM, WM_COMMAND, 0x00009C94 , 0); // Empty Modified Page List
  Sleep(1000);
  PostMessage(hWinRMM, WM_COMMAND, 0x00009C95 , 0); // Empty Standby List
  Sleep(1000);
  PostMessage(hWinRMM, WM_COMMAND, 0x00009C96 , 0); // Empty Priority 0 Standby List
  Sleep(1000);
  PostMessage(hWinRMM, WM_COMMAND, 0x00009C99 , 0); // Usage Menu Item , test hook
  Sleep(1000);
  PostMessage(hWinRMM,WM_CLOSE,NULL,NULL);
  return 0;
}
else
{

    cout<< "RAMMap Launcher" << endl;
    cout<< "Usage: RAMMapLaunch.exe PATH-TO/RAMMap.exe" << endl;

    return 0;
}
}
