// Recria a estrutura COORD
typedef struct {
    short X;
    short Y;
} COORD;



// Define o identificador da saída padrão
#define STD_OUTPUT_HANDLE ((unsigned int)-11)
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
typedef void* HANDLE;
typedef unsigned int UINT;
typedef unsigned char BYTE;
typedef unsigned long DWORD;

#define VK_MENU    0x12 
#define VK_RETURN  0x0D 
#define SC_ALT     0x38
#define SC_ENTER   0x1C

#define KEYEVENTF_KEYUP 0x0002

// Declara manualmente as funções da WinAPI
__declspec(dllimport) int __stdcall GetConsoleMode(void*, unsigned long*);
__declspec(dllimport) int __stdcall SetConsoleMode(void*, unsigned long);
__declspec(dllimport) void* __stdcall GetStdHandle(unsigned int);
__declspec(dllimport) int __stdcall SetConsoleTextAttribute(HANDLE, unsigned short);
__declspec(dllimport) int __stdcall SetConsoleCursorPosition(void* hConsoleOutput, COORD dwCursorPosition);
__declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);
__declspec(dllimport) int __stdcall Beep(unsigned int dwFreq, unsigned int dwDuration);
__declspec(dllimport) void __stdcall keybd_event(BYTE bVk, BYTE bScan, DWORD dwFlags, DWORD dwExtraInfo);



#define SW_MAXIMIZE 3




void gotoxy(int x, int y){
void* hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos = {x, y};
SetConsoleCursorPosition(hConsole, pos);
}

void ativarANSI() {
    void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
    unsigned long mode;
    GetConsoleMode(handle, &mode);
    SetConsoleMode(handle, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void pressionarTecla(BYTE tecla, BYTE scanCode) {
    keybd_event(tecla, scanCode, 0, 0);
}
void soltarTecla(BYTE tecla, BYTE scanCode) {
    keybd_event(tecla, scanCode, KEYEVENTF_KEYUP, 0);
}
void forcarFullscreen() {
    pressionarTecla(VK_MENU, SC_ALT);
    pressionarTecla(VK_RETURN, SC_ENTER);
    soltarTecla(VK_RETURN, SC_ENTER);
    soltarTecla(VK_MENU, SC_ALT);
}
