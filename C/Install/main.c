#include <windows.h>
#include <string.h>
//int main(){ char buffer[MAX_PATH];char *message = "hello";sprintf(buffer, "%s", message);  //GetWindowText(hwContact, szContact, 256);//strcpy(&szContact[strlen(szContact)], " - Conversation"); //GetWindowText(hwMsg, szMsg, 256);//strcpy(&szMsg[strlen(szMsg)], ""); HWND fcContact = FindWindow(NULL, "Untitled - Notepad"); ShowWindow(fcContact, SW_SHOWMAXIMIZED);SetForegroundWindow(fcContact);//FindWindowEx( hTray, NULL, "Button", NULL);SendMessage(FindWindowEx(fcContact, NULL, "Edit", NULL), WM_SETTEXT, 0, (LPARAM)buffer); return 0;}#include <windows.h>
#define time 1000


HWND Procura_Tela(char nome_classe[250],char nome_title[250]){

    HWND fcContact=0;

    while(fcContact==0){
        system("cls");
        printf("\nProcurando Janela");
        Sleep(time);
        printf(".");
        Sleep(time);
        printf(".");
        Sleep(time);
        printf(".");
        Sleep(time);

fcContact=FindWindow(nome_classe,nome_title);
        //FindWindow(NULL, "Sem título - Bloco de notas");
}
puts("\nJanela Encontrada...");


ShowWindow(fcContact, SW_SHOWDEFAULT);
SetForegroundWindow(fcContact);

return fcContact;

}

char Procura_Subtela(HWND Tela_Principal, char classname[250]){

 char nome_subjanela[250];
 HWND subjanela=0;

 while(subjanela==0){
system("cls");
printf("\nProcurando Subjanela");
Sleep(time);
printf(".");
Sleep(time);
printf(".");
Sleep(time);
printf(".");
Sleep(time);
subjanela = FindWindowEx(Tela_Principal, 0, classname , NULL);
GetWindowText(subjanela,nome_subjanela,255);
//printf("\nO titulo da janela de HWND: %d, e' %s",subjanela,nome);
//getch();

}
puts("\nSubjanela Encontrada...");

return nome_subjanela;
}

void EnviaTecla(char texto[250]){

    int x;
    for(x=0;texto[x]!=NULL;x++){
         keybd_event( VkKeyScan( texto[x] ), OemKeyScan( VkKeyScan( texto[x]) ), 0, 0);
         Sleep(time);
     printf("\n%c",texto[x]);
    }

}

void EnviaEspecial(char tecla[25], int press, int solta){

    if( strcmp(tecla,"7")==0){
        if(press==1){
            keybd_event(VK_NUMPAD7, 0x67,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_NUMPAD7 ,0x67,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"BACK")==0){
        if(press==1){
            keybd_event(VK_BACK, 0x08 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_BACK, 0x08 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"8")==0){
        if(press==1){
            keybd_event(VK_NUMPAD8 ,0x68,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_NUMPAD8 ,0x68,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"TAB")==0){
        if(press==1){
            keybd_event(VK_TAB ,0x09 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_TAB ,0x09 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"9")==0){
        if(press==1){
            keybd_event(VK_NUMPAD9 ,0x69 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_NUMPAD9 ,0x69 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"ENTER")==0){
        if(press==1){
            keybd_event(VK_RETURN ,0x0D ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_RETURN ,0x0D ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"*")==0){
        if(press==1){
            keybd_event(VK_MULTIPLY ,0x6A ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_MULTIPLY ,0x6A ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"SHIFT")==0){
        if(press==1){
            keybd_event(VK_SHIFT ,0x10 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_SHIFT ,0x10 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"+")==0){
        if(press==1){
            keybd_event(VK_ADD ,0x6B ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_ADD ,0x6B ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"CTRL")==0){
        if(press==1){
            keybd_event(VK_CONTROL ,0x11 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_CONTROL ,0x11 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"SEPARATOR")==0){
        if(press==1){
            keybd_event(VK_SEPARATOR ,0x6C ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_SEPARATOR ,0x6C ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"ALT")==0){
        if(press==1){
            keybd_event(VK_MENU ,0x12 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_MENU ,0x12 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"-")==0){
        if(press==1){
            keybd_event(VK_SUBTRACT ,0x6D ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_SUBTRACT ,0x6D ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"PAUSE")==0){
        if(press==1){
            keybd_event(VK_PAUSE ,0x13 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_PAUSE ,0x13 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"DECIMAL")==0){
        if(press==1){
            keybd_event(VK_DECIMAL ,0x6E ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_DECIMAL ,0x6E ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"CAPS_LOCK")==0){
        if(press==1){
            keybd_event(VK_CAPITAL ,0x14 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_CAPITAL ,0x14 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"/")==0){
        if(press==1){
            keybd_event(VK_DIVIDE ,0x6F ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_DIVIDE ,0x6F ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"ESC")==0){
        if(press==1){
            keybd_event(VK_ESCAPE ,0x1B ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_ESCAPE ,0x1B ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"F1")==0){
        if(press==1){
            keybd_event(VK_F1, 0x70 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_F1, 0x70 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"SPACE")==0){
        if(press==1){
            keybd_event(VK_SPACE, 0x20 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_SPACE, 0x20 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"F2")==0){
        if(press==1){
            keybd_event(VK_F2, 0x71 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_F2, 0x71 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"END")==0){
        if(press==1){
            keybd_event(VK_END, 0x23 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_END, 0x23,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"F3")==0){
        if(press==1){
            keybd_event(VK_F3, 0x72 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_F3, 0x72 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"HOME")==0){
        if(press==1){
            keybd_event(VK_HOME, 0x24 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_HOME, 0x24 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"F4")==0){
        if(press==1){
            keybd_event(VK_F4, 0x73 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_F4, 0x73 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"LEFT")==0){
        if(press==1){
            keybd_event(VK_LEFT, 0x25 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_LEFT, 0x25 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"F5")==0){
        if(press==1){
            keybd_event(VK_F5, 0x74 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_F5, 0x74 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"UP")==0){
        if(press==1){
            keybd_event(VK_UP, 0x26 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_UP, 0x26 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"F6")==0){
        if(press==1){
            keybd_event(VK_F6, 0x75 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_F6, 0x75 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"RIGHT")==0){
        if(press==1){
            keybd_event(VK_RIGHT, 0x27 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_RIGHT, 0x27 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"F7")==0){
        if(press==1){
            keybd_event(VK_F7, 0x76 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_F7, 0x76 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"DOWN")==0){
        if(press==1){
            keybd_event(VK_DOWN, 0x28 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_DOWN, 0x28 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"F8")==0){
        if(press==1){
            keybd_event(VK_F8, 0x77 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_F8, 0x77 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"PRINT_SCREEN")==0){
        if(press==1){
            keybd_event(VK_PRINT, 0x2A ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_PRINT, 0x2A ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"F9")==0){
        if(press==1){
            keybd_event(VK_F9, 0x78 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_F9, 0x78 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"SNAPSHOT")==0){
        if(press==1){
            keybd_event(VK_SNAPSHOT, 0x2C ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_SNAPSHOT, 0x2C ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"F10")==0){
        if(press==1){
            keybd_event(VK_F10, 0x79 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_F10, 0x79 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"INSERT")==0){
        if(press==1){
            keybd_event(VK_INSERT, 0x2D ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_INSERT, 0x2D ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"F11")==0){
        if(press==1){
            keybd_event(VK_F11, 0x7A ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_F11, 0x7A ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"DEL")==0){
        if(press==1){
            keybd_event(VK_DELETE, 0x2E ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_DELETE, 0x2E ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"F12")==0){
        if(press==1){
            keybd_event(VK_F12, 0x7B ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_F12, 0x7B ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"WIN")==0){
        if(press==1){
            keybd_event(VK_LWIN, 0x5B ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_LWIN, 0x5B,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"NUM_LOCK")==0){
        if(press==1){
            keybd_event(VK_NUMLOCK, 0x90 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_NUMLOCK, 0x90 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"")==0){
        if(press==1){
            keybd_event(VK_RWIN, 0x5C ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_RWIN, 0x5C ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"SCROLL")==0){
        if(press==1){
            keybd_event(VK_SCROLL, 0x91 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_SCROLL, 0x91 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"0")==0){
        if(press==1){
            keybd_event(VK_NUMPAD0, 0x60 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_NUMPAD0, 0x60,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"SHIFT")==0){
        if(press==1){
            keybd_event(VK_LSHIFT, 0xA0 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_LSHIFT, 0xA0 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"1")==0){
        if(press==1){
            keybd_event(VK_NUMPAD1, 0x61 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_NUMPAD1, 0x61,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"RSHIFT")==0){
        if(press==1){
            keybd_event(VK_RSHIFT, 0xA1 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_RSHIFT, 0xA1 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"2")==0){
        if(press==1){
            keybd_event(VK_NUMPAD2, 0x62 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_NUMPAD2, 0x62,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"CTRL")==0){
        if(press==1){
            keybd_event(VK_LCONTROL, 0xA2 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_LCONTROL, 0xA2 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"3")==0){
        if(press==1){
            keybd_event(VK_NUMPAD3, 0x63 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_NUMPAD3, 0x63 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"RCTRL")==0){
        if(press==1){
            keybd_event(VK_RCONTROL, 0xA3 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_RCONTROL, 0xA3,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"4")==0){
        if(press==1){
            keybd_event(VK_NUMPAD4, 0x64 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_NUMPAD4, 0x64 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"LALT")==0){
        if(press==1){
            keybd_event(VK_LMENU, 0xA4 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_LMENU, 0xA4 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"5")==0){
        if(press==1){
            keybd_event(VK_NUMPAD5, 0x65 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_NUMPAD5, 0x65 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"RALT")==0){
        if(press==1){
            keybd_event(VK_RMENU, 0xA5 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_RMENU, 0xA5 ,KEYEVENTF_KEYUP , 0);
        }
    }
    if( strcmp(tecla,"6")==0){
        if(press==1){
            keybd_event(VK_NUMPAD6, 0x66 ,0 , 0);
        }
        if(solta==1){
            keybd_event(VK_NUMPAD6, 0x66 ,KEYEVENTF_KEYUP , 0);
        }
    }

    Sleep(time);


}

void Adobe(){

//================================ADOBE READER========================================================//
WinExec("\\\\192.168.79.10\\informatica\\PROGS\\AdobeReader\\9\\AdbeRdr90_pt_BR.exe",SW_SHOWNORMAL);

HWND fcContact=0;

while(fcContact==0){
system("cls");
printf("\nProcurando Janela");
Sleep(1000);
printf(".");
Sleep(1000);
printf(".");

Sleep(1000);
printf(".");
Sleep(1000);

fcContact=FindWindow("MsiDialogCloseClass",NULL);
        //FindWindow(NULL, "Sem título - Bloco de notas");
}
puts("\nJanela Encontrada...");

//fcContact = FindWindow(NULL, "Seleção do Idioma para a Instalação");
ShowWindow(fcContact, SW_SHOWDEFAULT);
SetForegroundWindow(fcContact);

keybd_event(VK_MENU,0xb8,0 , 0); //Alt Press
keybd_event( VkKeyScan( 'a' ), OemKeyScan( VkKeyScan( 'a' ) ), 0, 0);
Sleep(1000);
keybd_event( VkKeyScan( 'i' ), OemKeyScan( VkKeyScan( 'i' ) ), 0, 0);

Sleep(1000);
//fcContact=0;
while(fcContact!=0){
printf(".");
Sleep(1000);
fcContact=FindWindow("MsiDialogCloseClass",NULL);
        //FindWindow(NULL, "Sem título - Bloco de notas");
keybd_event( VkKeyScan( 'o' ), OemKeyScan( VkKeyScan( 'o' ) ), 0, 0);
}

keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0); // Alt Release

system("cls");
puts("\nAdobe Reader 9 Instalado!!");
//================================FIM ADOBE READER========================================================//
}

void CCleaner(){

int i;
//================================ CCleanner ========================================================//
WinExec("\\\\192.168.79.10\\informatica\\PROGS\\CCLEANER\\ccsetup226.exe",SW_SHOWNORMAL);

HWND fcContact=0;

while(fcContact==0){

system("cls");
printf("\nProcurando Janela");
Sleep(500);
printf(".");
Sleep(500);
printf(".");
Sleep(500);
printf(".");
Sleep(900);

fcContact=FindWindow(NULL,"Installer Language");
        //FindWindow(NULL, "Sem título - Bloco de notas");
}
puts("\nJanela Encontrada...");

ShowWindow(fcContact, SW_SHOWDEFAULT);
SetForegroundWindow(fcContact);

Sleep(100);
keybd_event(VK_RETURN,0x0D,0 , 0); //ENTER Press
keybd_event(VK_RETURN,0x0D,KEYEVENTF_KEYUP,0); // ENTER Release

Sleep(1000);

keybd_event(VK_MENU,0xb8,0 , 0); //Alt Press
keybd_event( VkKeyScan( 'p' ), OemKeyScan( VkKeyScan( 'p' ) ), 0, 0);

Sleep(1000);

keybd_event( VkKeyScan( 'c' ), OemKeyScan( VkKeyScan( 'c' ) ), 0, 0);

Sleep(1000);

keybd_event( VkKeyScan( 'p' ), OemKeyScan( VkKeyScan( 'p' ) ), 0, 0);

keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0); // Alt Release

keybd_event(VK_SPACE,0x20,0 , 0); // SPACE Press
keybd_event(VK_SPACE,0x20, KEYEVENTF_KEYUP,0); // SpACE Release


for(i=0;i<5;i++){
Sleep(1000);
keybd_event(VK_TAB,0x8f,0 , 0); // Tab Press
keybd_event(VK_TAB,0x8f, KEYEVENTF_KEYUP,0); // Tab Release
}

keybd_event(VK_SPACE,0x20,0 , 0); // SPACE Press
keybd_event(VK_SPACE,0x20, KEYEVENTF_KEYUP,0); // SpACE Release

Sleep(1000);

keybd_event(VK_RETURN,0x0D,0 , 0); //ENTER Press
keybd_event(VK_RETURN,0x0D,KEYEVENTF_KEYUP,0); // ENTER Release

Sleep(10000);


keybd_event(VK_SPACE,0x20,0 , 0); // SPACE Press
keybd_event(VK_SPACE,0x20, KEYEVENTF_KEYUP,0); // SpACE Release

Sleep(1000);

keybd_event(VK_RETURN,0x0D,0 , 0); //ENTER Press
keybd_event(VK_RETURN,0x0D,KEYEVENTF_KEYUP,0); // ENTER Release


system("cls");
puts("\nCCleaner Instalado!!        \\o/");

}

void EndPoint(){

    WinExec("\\\\192.168.79.10\\informatica\\PROGS\\EndPoint\\Administrativo_32-bit\\setup.exe",SW_SHOWNORMAL);

    Sleep(2000);

    WinExec("\\\\192.168.79.10\\informatica\\PROGS\\EndPoint\\Administrativo_32-bit\\setup.exe",SW_SHOWNORMAL);

    Procura_Tela(NULL,"Restart Notification");

    EnviaEspecial("TAB",1,1);
    Sleep(100);
    EnviaEspecial("TAB",1,1);
    Sleep(100);
    EnviaEspecial("SPACE",1,1);

}

void FilZip(){
    WinExec("\\\\192.168.79.10\\informatica\\PROGS\\FILZIP\\fz306.exe",SW_SHOWNORMAL);

    Procura_Tela("TSelectLanguageForm",NULL);

    EnviaEspecial("TAB",1,1);
    EnviaEspecial("SPACE",1,1);

    int i;

    Procura_Tela("TWizardForm",NULL);
    for(i=0;i<4;i++){

    EnviaEspecial("ALT",1,0);
    EnviaTecla("a");
    EnviaEspecial("ALT",0,1);
    }

    EnviaEspecial("TAB",1,1);
    EnviaEspecial("DOWN",1,1);

    EnviaEspecial("DOWN",1,1);

    EnviaEspecial("DOWN",1,1);

    EnviaEspecial("SPACE",1,1);

    EnviaEspecial("DOWN",1,1);

    EnviaEspecial("SPACE",1,1);

    EnviaEspecial("DOWN",1,1);
    EnviaEspecial("SPACE",1,1);

    EnviaEspecial("ALT",1,0);
    EnviaTecla("a");
    EnviaTecla("a");
    EnviaEspecial("ALT",0,1);

       EnviaEspecial("SPACE",1,1);

          EnviaEspecial("ALT",1,0);
    EnviaTecla("a");

    EnviaTecla("i");
    EnviaEspecial("ALT",0,1);
    Sleep(1000);
    EnviaEspecial("SPACE",1,1);
    EnviaEspecial("ALT",1,0);
    EnviaTecla("c");
    EnviaEspecial("ALT",0,1);


Sleep(1000);

Procura_Tela(NULL,"REgistro");


    EnviaEspecial("TAB",1,1);
    EnviaEspecial("TAB",1,1);
    EnviaEspecial("SPACE",1,1);
    EnviaEspecial("ALT",1,0);
    EnviaTecla("c");
    EnviaEspecial("ALT",0,1);
    EnviaEspecial("TAB",1,1);
    EnviaEspecial("SPACE",1,1);
    EnviaEspecial("ALT",1,0);
    EnviaTecla("a");
    EnviaEspecial("ALT",0,1);
    EnviaEspecial("ALT",1,0);
    EnviaEspecial("F4",1,1);
    EnviaEspecial("ALT",0,1);

}

void Flash(){

    WinExec("\\\\192.168.79.10\\informatica\\PROGS\\Flash\\Flash_Player_10.exe",SW_SHOWNORMAL);

        Sleep(5000);

        EnviaEspecial("ALT",1,0);
        EnviaEspecial("F4",1,1);
        EnviaEspecial("ALT",0,1);




}

void IE(){

    system("secedit /configure /cfg %windir%\\repair\\secsetup.inf /db secsetup.sdb /verbose");

   while(FindWindowEx("ConsoleWindowClass", 0, NULL , NULL)){
        puts("Aguardando SecEdit");
    }

}

int main(){

//Adobe();

//CCleaner();

//FilZip();

//Flash();

IE();

//EndPoint();

//EnviaTecla("WiLLiaM H. Stenico");

puts("\nDesenvolvido por: WiLLiaM H. Stenico!!\nINICIO: 15/02/2010");

return 0;
}




//FONTE DE CODIGOS!!!!!!!!
  // http://msdn.microsoft.com/en-us/library/ms645540(VS.85).aspx

  //http://msdn.microsoft.com/en-us/library/ms646304(VS.85).aspx

  //http://www.codeproject.com/KB/system/keyboard.aspx

  //http://josiel.orgfree.com/blog/?cat=35
  //*****************RETURN = ENTER**********************

  ////////////////////////////////////////////////////////////////////////

//FindWindowEx(HNDWjanelaprincipal, 0, classe, nul);


//SetWindowText(fcContact,"TEXTO");

//////////////////////////////////////////////////////////////////////

//eybd_event( VkKeyScan( 'a' ), OemKeyScan( VkKeyScan( 'a' ) ), 0, 0);


// Simulating a +A keystroke
/*keybd_event(VK_CONTROL,0x9d,0 , 0); // Ctrl Press
keybd_event(VkKeyScan("A"),0x9e,0 , 0); // �A� Press
keybd_event(VkKeyScan("A"),0x9e, KEYEVENTF_KEYUP,0); // �A� Release
keybd_event(VK_CONTROL,0x9d,KEYEVENTF_KEYUP,0); // Ctrl Release


// Simulating a Alt+Tab keystroke
keybd_event(VK_MENU,0xb8,0 , 0); //Alt Press
keybd_event(VK_TAB,0x8f,0 , 0); // Tab Press
keybd_event(VK_TAB,0x8f, KEYEVENTF_KEYUP,0); // Tab Release
keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0); // Alt Release

/*
keybd_event(VK_MENU,0xb8,0 , 0); //Alt Press

keybd_event(VkKeyScan('X'),0x58,0 , 0); // �X� Press
keybd_event(VkKeyScan('X'),0x58, KEYEVENTF_KEYUP,0); // �X� Release

keybd_event(VkKeyScan('C'),0x43,0 , 0); // �C� Press
keybd_event(VkKeyScan('C'),0x43, KEYEVENTF_KEYUP,0); // �C� Release

keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0); // Alt Release
*/


/*MENSAGENS:::::::::::::

char buffer[MAX_PATH];
char *message = "9";
sprintf(buffer, "%s", message);

SendMessage(FindWindowEx(fcContact, NULL, "Edit", NULL), WM_SETTEXT, 0, (LPARAM)buffer); ////////MENSAGENS


*/




