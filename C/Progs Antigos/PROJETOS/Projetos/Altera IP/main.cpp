#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include "resource.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>




   char ip[16]="IP";
   char mk[16];
   char gw[16];
   char var[100]; //variável que recebe o comando+variável ip

HINSTANCE hInst;

BOOL CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
       case WM_INITDIALOG:
            /*


             * TODO: Add code to initialize the dialog.
             */

            return TRUE;

        case WM_CLOSE:
            EndDialog(hwndDlg, 0);
            return TRUE;

        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                /*
                 * TODO: Add more control ID's, when needed.
                 */
                case IDC_BTN_QUIT:
                    EndDialog(hwndDlg, 0);
                    return TRUE;

                case IDC_BTN_1:




   /*printf("Entre com o número do ip: ");
   scanf("%s",&ip);

   printf("Entre com o número da mascara: ");
   scanf("%s",&mk);

   printf("Entre com o número do gw: ");
   scanf("%s",&gw);
*/
   sprintf(var, "netsh interface ip set address name=\"Conexão local\" static %s %s %s 1", ip, mk, gw); //var recebe valor com + var ip

   system(var); //system recebe valor de var






                    MessageBox(hwndDlg, "You clicked \"Test\" button!", "Information", MB_ICONINFORMATION);
                    return TRUE;

                    case IDC_BTN_2:

                    return TRUE;

                    case IDC_BTN_3:





                    return TRUE;




            }
    }

    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst = hInstance;

    // The user interface is a modal dialog box
    return DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, DialogProc);
}

