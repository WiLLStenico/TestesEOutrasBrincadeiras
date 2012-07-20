#include <windows.h>
//int main(){ char buffer[MAX_PATH];char *message = "hello";sprintf(buffer, "%s", message);  //GetWindowText(hwContact, szContact, 256);//strcpy(&szContact[strlen(szContact)], " - Conversation"); //GetWindowText(hwMsg, szMsg, 256);//strcpy(&szMsg[strlen(szMsg)], ""); HWND fcContact = FindWindow(NULL, "Untitled - Notepad"); ShowWindow(fcContact, SW_SHOWMAXIMIZED);SetForegroundWindow(fcContact);//FindWindowEx( hTray, NULL, "Button", NULL);SendMessage(FindWindowEx(fcContact, NULL, "Edit", NULL), WM_SETTEXT, 0, (LPARAM)buffer); return 0;}#include <windows.h>


int main()
{

char buffer[MAX_PATH];
char *message = "9";
sprintf(buffer, "%s", message);

//GetWindowText(hwContact, szContact, 256);
//strcpy(&szContact[strlen(szContact)], " - Conversation");

//GetWindowText(hwMsg, szMsg, 256);
//strcpy(&szMsg[strlen(szMsg)], "");

//WinExec('C:\WINDOWS\COMMAND.COM C:\ARQUIVO.BAT', SW_SHOW);
WinExec("calc",0);
HWND fcContact = FindWindow(NULL, "Calculadora");

ShowWindow(fcContact, SW_SHOWDEFAULT);
SetForegroundWindow(fcContact);

//FindWindowEx( hTray, NULL, "Button", NULL);

//SendMessage(FindWindowEx(fcContact, NULL, "Edit", NULL), WM_SETTEXT, 0, (LPARAM)buffer); ////////MENSAGENS


keybd_event(VK_MENU,0xb8,0 , 0); //Alt Press

keybd_event(VkKeyScan('X'),0x58,0 , 0); // �A� Press
keybd_event(VkKeyScan('X'),0x58, KEYEVENTF_KEYUP,0); // �A� Release

keybd_event(VkKeyScan('C'),0x43,0 , 0); // �A� Press
keybd_event(VkKeyScan('C'),0x43, KEYEVENTF_KEYUP,0); // �A� Release

keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0); // Alt Release



//FONTE DE CODIGOS!!!!!!!!
  // http://msdn.microsoft.com/en-us/library/ms645540(VS.85).aspx

  ////////////////////////////////////////////////////////////////////////


// Simulating a Ctrl+A keystroke
/*keybd_event(VK_CONTROL,0x9d,0 , 0); // Ctrl Press
keybd_event(VkKeyScan("A"),0x9e,0 , 0); // �A� Press
keybd_event(VkKeyScan("A"),0x9e, KEYEVENTF_KEYUP,0); // �A� Release
keybd_event(VK_CONTROL,0x9d,KEYEVENTF_KEYUP,0); // Ctrl Release


// Simulating a Alt+Tab keystroke
keybd_event(VK_MENU,0xb8,0 , 0); //Alt Press
keybd_event(VK_TAB,0x8f,0 , 0); // Tab Press
keybd_event(VK_TAB,0x8f, KEYEVENTF_KEYUP,0); // Tab Release
keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0); // Alt Release


*/



return 0;
}
