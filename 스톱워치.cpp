#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#define Ture 1
#define False 0
#define Start 10

void gotoxy(short x, short y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int IsKeyDown(int Key) {
    return ((GetAsyncKeyState(Key) & 0x0000) != 0);
}

int keycontorl() {
    char temp = _getch();
    if (temp == ' ') {
        return Start;
    }
}

void CursorView(char show) {
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int main() {
    CursorView(0);
    system("mode con cols=40 lines=15 | title Timer");

start:
    int m = 0;
    int s = 0;
    int h = 0;
    int i = 1;
    system("cls");

    gotoxy(8, 6);
    printf("스톱워치 시작 : <SPACE>");
    while (1) {
        int k = keycontorl();

        switch (k) {
        case Start: {
            goto timer;
        }
        }
    }

timer:
    do {
        system("cls");
        if (s > 60) {
            s = 0;
            m++;
        }
        if (m > 60) {
            m = 0;
            h++;
        }
        gotoxy(15, 5);
        printf("%d : %d : %d", h, m, s);
        gotoxy(13, 7);
        printf("일시정지 : <P>");
        gotoxy(13, 9);
        printf("중지 : <ENTER>\n\n ");
        if (GetAsyncKeyState(VK_RETURN) & 0x0001) {
            break;
        }
        if (GetAsyncKeyState(0x50) & 0x0001) {
            system("pause");
        }
        s++;
        Sleep(1000);
    } while (1);

exit:
    system("cls");
    gotoxy(17, 5);
    printf("%d : %d : %d", h, m, s);
    gotoxy(11, 7);
    printf("처음으로 : <SPACE>");
    while (1) {
        int k = keycontorl();
        switch (k) {
        case Start: {
            goto start;
        }
        }
    }
    return 0;
}

