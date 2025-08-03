#include "CTime.h"
#include <iostream>
#include <thread>
#include <chrono>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

using namespace std;

void gotoxy(int x, int y) {
#ifdef _WIN32
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    printf("\033[%d;%dH", y + 1, x + 1);
#endif
}

int main() {
    CTime currentTime(23, 59, 50); // Bắt đầu từ gần nửa đêm để test rollover

    while (true) {
        gotoxy(70, 0); // In ở góc trên bên phải (x = 70, y = 0)
        cout << currentTime << flush;

        this_thread::sleep_for(chrono::seconds(1));
        ++currentTime;
    }

    return 0;
}
